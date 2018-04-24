/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:26:07 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/23 14:45:12 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	free_param(t_param *param)
{
	t_param *tmp_param;

	while (param)
	{
		tmp_param = param;
		param = param->next;
		free(tmp_param);
	}
}

void	free_arena(t_arena *arena)
{
	t_process	*tmp_process;
	t_player	*tmp_player;

	if (!arena)
		return ;
	if (arena->board)
		free(arena->board);
	while (arena->process)
	{
		tmp_process = arena->process;
		arena->process = tmp_process->next;
		free_param(tmp_process->param);
		free(tmp_process);
	}
	while(arena->players)
	{
		tmp_player = arena->players;
		arena->players = tmp_player->next;
		if (tmp_player->name)
			ft_strdel(&(tmp_player->name));
		if (tmp_player->comment)
			ft_strdel(&(tmp_player->comment));
		free(tmp_player);
	}
	free(arena);
}

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
	exit (0);
}

void	ft_error(char *message, t_arena *arena)
{
	if (arena->aff == NCURSE)
		endwin();
	ft_printf("Error: %s\n", message);
	free_arena(arena);
	exit (0);
}
