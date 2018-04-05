/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:00:16 by overetou          #+#    #+#             */
/*   Updated: 2018/04/05 19:48:20 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		secure_open(char *file_name, int code)
{
	int fd;

	if ((fd = open(file_name, code)) < 0)
		exit(ft_printf("ERROR SECURE OPEN\n"));
	return (fd);
}

char	*get_name(int fd)
{
	char	*name;

	name = ft_strnew(PROG_NAME_LENGTH);
	lseek(fd, 4, SEEK_SET);
	if (read(fd, name, PROG_NAME_LENGTH) < 0)
		exit(ft_printf("ERROR GET NAME\n"));
	return (name);
}

char	*get_comment(int fd)
{
	char	*comment;

	comment = ft_strnew(COMMENT_LENGTH);
	lseek(fd, 0, PROG_NAME_LENGTH + 12);
	if (read(fd, comment, COMMENT_LENGTH) < 0)
		exit(ft_printf("ERROR SECURE COMMENT\n"));
	return (comment);
}

int		get_file_size(int fd)
{
	char	str_size[4];
	int		file_size;
	int		size;
	int		mask;

	size = 0;
	lseek(fd, 4, SEEK_CUR);
	if (read(fd, str_size, 4) < 0)
		exit(ft_printf("ERROR GET FILE SIZE\n"));
	file_size = str_size[0];
	while (++size < 4)
	{
		file_size = file_size << 8;
		mask = str_size[size];
		file_size = file_size | mask;
	}
	return (file_size);
}

void	write_player(int fd, t_arena *arena, int adr, int file_size)
{
	int offset;

	offset = lseek(fd, 0, SEEK_END) - (PROG_NAME_LENGTH + COMMENT_LENGTH + 16);
	if (offset != file_size)
		exit(ft_printf("ERROR WRITE PLAYER\noffset = %d\nfile_size = %d\n", offset, file_size));
	lseek(fd, PROG_NAME_LENGTH + COMMENT_LENGTH + 16, SEEK_SET);
	read(fd, (arena->board) + adr, file_size);
}

void	fill_players(t_arena *arena)
{
	t_player	*player;
	int			i;
	int			adr;
	int			fd;

	player = arena->players;
	i = 1;
	while (player)
	{
		fd = secure_open(player->file_name, O_RDONLY);
		player->name = get_name(fd);
		player->file_size = get_file_size(fd);
		player->comment = get_comment(fd);
		adr = (MEM_SIZE / arena->number_of_players) * (arena->number_of_players - i);
		write_player(fd, arena, adr, player->file_size);
		add_process(&(arena->process), new_process(player->nbr, adr));
		i++;
		player = player->next;
	}
}
