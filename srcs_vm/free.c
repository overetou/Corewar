/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:55:17 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/24 20:37:09 by ysingaye         ###   ########.fr       */
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

void	free_process(t_process *process)
{
	t_process	*tmp_process;

	while (process)
	{
		tmp_process = process;
		process = tmp_process->next;
		free_param(tmp_process->param);
		free(tmp_process);
	}
}

void	free_player(t_player *players)
{
	t_player	*tmp_player;

	while (players)
	{
		tmp_player = players;
		players = tmp_player->next;
		if (tmp_player->name)
			ft_strdel(&(tmp_player->name));
		if (tmp_player->comment)
			ft_strdel(&(tmp_player->comment));
		free(tmp_player);
	}
}

void	free_arena(t_arena *arena)
{
	if (!arena)
		return ;
	if (arena->board)
		free(arena->board);
	free_process(arena->process);
	free_player(arena->players);
	free(arena);
}
