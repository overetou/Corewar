/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 21:25:04 by pkeita            #+#    #+#             */
/*   Updated: 2018/04/29 21:25:07 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	refresh_status2(int *x, int *y, t_player *player)
{
	if (has_colors() != FALSE)
		attron(COLOR_PAIR((unsigned char)player->nbr));
	mvprintw(*y += 2, *x, "%s", player->name);
	if (has_colors() != FALSE)
		attroff(COLOR_PAIR((unsigned char)player->nbr));
	while ((player = player->next))
	{
		mvprintw(*y += 1, *x, "vs");
		if (has_colors() != FALSE)
			attron(COLOR_PAIR((unsigned char)player->nbr));
		mvprintw(*y += 1, *x, "%s", player->name);
		if (has_colors() != FALSE)
			attroff(COLOR_PAIR((unsigned char)player->nbr));
	}
}
