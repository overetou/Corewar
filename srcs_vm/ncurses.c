/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:26:51 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/29 16:16:12 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include <ncurses.h>
#include <stdlib.h>
#include <strings.h>
# define LINES 10
# define COLS 10

void		refresh_arena(unsigned char *tab)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	initscr();/* Start curses mode 		  */
	while (i < MEM_SIZE)
	{
		mvprintw(y, x % 192, "%.2x ", tab[i]);
		i++;
		x += 3;
		if (x % 192 == 0)
			y++;
	}
	refresh();			/* Print it on to the real screen */
}

int		main(void)
{
	unsigned char *tab;

	tab = malloc(sizeof(unsigned char) * MEM_SIZE);
	refresh_arena(tab);
	getch();			/* Wait for user input */
	tab[64] = (unsigned char)255;
	refresh_arena(tab);
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
	return (0);
}
