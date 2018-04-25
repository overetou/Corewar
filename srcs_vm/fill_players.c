/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:00:16 by overetou          #+#    #+#             */
/*   Updated: 2018/04/23 16:56:19 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		secure_open(char *file_name, int code)
{
	int fd;

	fd = open(file_name, code);
	return (fd);
}

char	*get_name(int fd)
{
	char	*name;

	name = ft_strnew(PROG_NAME_LENGTH);
	if (name == NULL)
		return (NULL);
	lseek(fd, 4, SEEK_SET);
	if (read(fd, name, PROG_NAME_LENGTH) < 0)
		exit(ft_printf("ERROR GET NAME\n"));
	return (name);
}

int		get_file_size(int fd)
{
	unsigned char	str_size[4];
	int		file_size;
	int		size;

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

char	*get_comment(int fd)
{
	char	*comment;

	comment = ft_strnew(COMMENT_LENGTH);
	if (comment == NULL)
		return (NULL);
	lseek(fd, 0, PROG_NAME_LENGTH + 12);
	if (read(fd, comment, COMMENT_LENGTH) < 0)
		exit(ft_printf("ERROR SECURE COMMENT\n"));
	return (comment);
}

void	write_player(int fd, t_arena *arena, int adr, int file_size)
{
	int offset;

	offset = lseek(fd, 0, SEEK_END) - (PROG_NAME_LENGTH + COMMENT_LENGTH + 16);
	if (offset != file_size)
		ft_error("ERROR WRITE PLAYER\n", arena);
	lseek(fd, PROG_NAME_LENGTH + COMMENT_LENGTH + 16, SEEK_SET);
	read(fd, (arena->board) + adr, file_size);
}

void	check_numbers(int fd, unsigned int file_size)
{
	unsigned int		count;
	char				buff[50];
	unsigned int		witness;

	count = 0;
	lseek(fd, 4, SEEK_CUR);
	while ((witness = read(fd, buff, 50)))
		count += witness;
	if (count != file_size)
		exit(ft_printf("ERROR : FILE SIZE DOES NOT MATCH, count = %u, file_size = %u\n", count, file_size));
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
		if (fd < 0)
			ft_error("Failed the openning of a file.\n", arena);
		player->name = get_name(fd);
		player->file_size = get_file_size(fd);
		player->comment = get_comment(fd);
		if (player->name == NULL || player->comment == NULL || player->file_size == -1)
			ft_error("Player generation failed.\n", arena);
		check_numbers(fd, player->file_size);
		adr = (MEM_SIZE / arena->number_of_players) * (arena->number_of_players - i);
		write_player(fd, arena, adr, player->file_size);
		push_process(&(arena->process), new_process(player->nbr, adr, arena));
		arena->process->nbr = ++arena->nbr_process;
		arena->process_cpt++;
		i++;
		player = player->next;
	}
}
