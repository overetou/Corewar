/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:26:07 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/24 20:43:51 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_usage(char *path, t_arena *arena)
{
	if (arena->aff == NCURSE)
		endwin();
	ft_printf("Usage: %s [-dump N -degug -v] [-n N] <champ.cor> <...>\n\
\t-dump N : Dumps memory after N cycles\n\
\t-debug : Print executed operations\n\
\t-v: Ncurses visual mode\n\
\t-n: Set champ number at N\n", path);
	free_arena(arena);
	exit(0);
}

void	ft_error(char *message, t_arena *arena)
{
	if (arena && arena->aff == NCURSE)
		endwin();
	ft_printf("Error: %s\n", message);
	free_arena(arena);
	exit(EXIT_FAILURE);
}
