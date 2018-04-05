/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:26:51 by kenguyen          #+#    #+#             */
/*   Updated: 2018/04/05 19:50:02 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		dump_tab(t_arena *arena)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.2x ", arena->board[i]);
		i++;
		if (i % 32 == 0)
			ft_putchar('\n');
	}
	exit(0);
}

void		ft_init_color(t_player *players, t_arena *arena)
{
	int color;
	int i;
	int adr;

	start_color();
	refresh_arena(arena, 0, MEM_SIZE, 0);
	getch();
	i = 1;
	if (arena->number_of_players <= 7)
	{
		color = 1;
		while (players)
		{
			init_pair(players->nbr, color++, COLOR_BLACK);
			adr = (MEM_SIZE / arena->number_of_players) * (arena->number_of_players - i);
			refresh_arena(arena, adr, players->file_size, players->nbr);
			players = players->next;
			i++;
		}
	}
	getch();
}

void		refresh_arena(t_arena *arena, int index, int len, int color)
{
	int x;
	int y;

	x = (index + len - 1) * 3;
	y = x / 192;
	if (len)
	{
		refresh_arena(arena, index, --len, color);
		if (color && has_colors() != FALSE)
			attron(COLOR_PAIR(color));
		mvprintw(y, x % 192, "%.2x ", arena->board[index + len]);
		refresh();
		if (color && has_colors() != FALSE)
			attroff(COLOR_PAIR(color));
	}
}
