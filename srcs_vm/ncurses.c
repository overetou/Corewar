/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:26:51 by kenguyen          #+#    #+#             */
/*   Updated: 2018/04/04 18:22:31 by ysingaye         ###   ########.fr       */
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
}

void		init_color(t_player *players)
{
	int color;

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
		if (has_colors() != FALSE)
			attron(COLOR_PAIR(color));
		mvprintw(y, x % 192, "%.2x ", arena->tab[index + len]);
		refresh();
		if (has_colors() != FALSE)
			attroff(COLOR_PAIR(color));
	}
}

/*int		main(void)
{
	unsigned char *tab;

	tab = malloc(sizeof(unsigned char) * MEM_SIZE);



	dump_tab(tab);
	return (0);





	initscr();
	start_color();
	init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
	refresh_arena(tab, 0, MEM_SIZE, COLOR_GREEN);
	getch();
	tab[64] = (unsigned char)255;
	tab[65] = (unsigned char)11;
	refresh_arena(tab, 64, 4, COLOR_RED);
	getch();
	endwin();
	return (0);
}*/
