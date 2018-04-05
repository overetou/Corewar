/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:26:51 by kenguyen          #+#    #+#             */
/*   Updated: 2018/04/05 14:26:46 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		dump_tab(t_arena *arena)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.2x ", tab[i]);
		i++;
		if (i % 32 == 0)
			ft_putchar('\n');
	}
	exit(0);
}

void		init_color(t_player *players)
{
	int color;

	start_color();
	color = 1;
	while (players)
	{
		init_pair(players->nbr, color++, COLOR_BLACK);
		players = players->next;
	}
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
