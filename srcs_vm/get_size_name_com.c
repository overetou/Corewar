/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_name_com.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:04:30 by overetou          #+#    #+#             */
/*   Updated: 2018/04/25 19:04:32 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

char				*get_name(int fd, t_arena *arena)
{
	char			*name;
	unsigned char	magic_buff[4];
	unsigned int	magic;

	name = ft_strnew(PROG_NAME_LENGTH);
	if (name == NULL)
		return (NULL);
	if (read(fd, &magic_buff, 4) < 0)
		ft_error("Read failed", arena);
	magic = magic_buff[0];
	magic = magic << 8;
	magic += magic_buff[1];
	magic = magic << 8;
	magic += magic_buff[2];
	magic = magic << 8;
	magic += magic_buff[3];
	if (magic != COREWAR_EXEC_MAGIC)
		ft_error("Bad COREWAR_EXEC_MAGIC", arena);
	if (read(fd, name, PROG_NAME_LENGTH) < 0)
		ft_strdel(&name);
	return (name);
}

int					get_file_size(int fd)
{
	unsigned char	str_size[4];
	int				file_size;
	int				size;

	size = 0;
	lseek(fd, 4, SEEK_CUR);
	if (read(fd, str_size, 4) < 0)
		return (-1);
	file_size = str_size[0];
	while (++size < 4)
	{
		file_size = file_size << 8;
		file_size = file_size | str_size[size];
	}
	return (file_size);
}

char				*get_comment(int fd)
{
	char			*comment;

	comment = ft_strnew(COMMENT_LENGTH);
	if (comment == NULL)
		return (NULL);
	lseek(fd, 0, PROG_NAME_LENGTH + 12);
	if (read(fd, comment, COMMENT_LENGTH) < 0)
	{
		free(comment);
		comment = NULL;
	}
	return (comment);
}
