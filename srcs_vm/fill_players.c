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

void	write_player(int fd, t_arena *arena, int adr, int file_size)
{
	int offset;

	offset = lseek(fd, 0, SEEK_END) - (PROG_NAME_LENGTH + COMMENT_LENGTH + 16);
	if (offset != file_size)
		ft_error("ERROR WRITE PLAYER\n", arena);
	lseek(fd, PROG_NAME_LENGTH + COMMENT_LENGTH + 16, SEEK_SET);
	read(fd, (arena->board) + adr, file_size);
}

void	check_numbers(int fd, unsigned int file_size, t_arena *arena)
{
	unsigned int		count;
	char				buff[50];
	unsigned int		witness;

	count = 0;
	lseek(fd, 4, SEEK_CUR);
	while ((witness = read(fd, buff, 50)))
		count += witness;
	if (count != file_size)
		ft_error("ERROR : FILE SIZE DOES NOT MATCH\n", arena);
}

void	fill_players(t_arena *arena)
{
	t_player	*plr;
	int			i;
	int			adr;
	int			fd;

	plr = arena->players;
	i = 1;
	while (plr)
	{
		if ((fd = secure_open(plr->file_name, O_RDONLY)) < 0)
			ft_error("Failed the openning of a file.\n", arena);
		plr->name = get_name(fd, arena);
		plr->file_size = get_file_size(fd);
		plr->comment = get_comment(fd);
		if (plr->name == NULL || plr->comment == NULL || plr->file_size == -1)
			ft_error("Player generation failed.\n", arena);
		check_numbers(fd, plr->file_size, arena);
		adr = (MEM_SIZE / arena->nbr_of_playr) * (arena->nbr_of_playr - i);
		write_player(fd, arena, adr, plr->file_size);
		push_process(&(arena->process), new_process(plr->nbr, adr, arena));
		arena->process->nbr = ++arena->nbr_process;
		arena->process_cpt++;
		i++;
		plr = plr->next;
	}
}
