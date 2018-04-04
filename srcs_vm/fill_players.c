/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:00:16 by overetou          #+#    #+#             */
/*   Updated: 2018/04/04 19:00:18 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		secure_open(char *file_name, int code)
{
	int fd;

	if ((fd = open(file_name, code)) < 0)
		exit(0);
	return (fd);
}

char	*get_name(int fd)
{
	char	*name;
	
	name = ft_strnew(PROG_NAME_LENGTH);
	lseek(fd, 0, 4);
	if (read(fd, name, PROG_NAME_LENGTH) < 0)
		exit(0);
	return (name);
}

char	*get_comment(int fd)
{
	char	*comment;
	
	comment = ft_strnew(COMMEMT_LENGTH);
	lseek(fd, 0, PROG_NAME_LENGTH + 12);
	if (read(fd, comment, PROG_comment_LENGTH) < 0)
		exit(0);
	return (comment);
}

int		get_file_size(int fd)
{
	char	*str_size;
	int		file_size;
	int		size;
	int		mask;

	size = 0;
	lseek(fd, 0, PROG_NAME_LENGTH + 8);
	if (read(fd, str_size, 4) < 0)
		exit(0);
	file_size = str_size[0];
	while (++size < 4)
	{
		file_size = file_size << 8;
		mask = str_size[size];
		file_size = file_size | mask;
	}
	return (file_size);
}

void	write_player(int fd, t_arena *arena, int i, int file_size)
{
	int adr;
	int offset;

	adr = (MEM_SIZE / arena->number_of_players) * i;
	offset = lseek(fd, PROG_NAME_LENGTH + COMMENT_LENGTH + 16, SEEK_END);
	if (offset != file_size)
		exit(0);
	lseek(fd, 0, PROG_NAME_LENGTH + COMMENT_LENGTH + 16);
	read(fd, (arena->board) + adr, file_size);
}

void	fill_players(t_arena *arena)
{
	t_player	*player;
	int		 file_size;
	int		 i;

	player = arena->players;
	i = 0;
	while (player)
	{
		fd = secure_open(player->file_name, O_RDONLY);
		player->name = get_name(fd);
		player->comment = get_coment(fd);
		file_size = get_file_size(fd);
		write_player(fd, arena, i, file_size);
		i++;
	}
}
