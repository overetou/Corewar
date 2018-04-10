/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:26:23 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/10 20:01:46 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_live(t_param *param, t_arena *arena, t_process *process)
{
	t_player *player;

	if (process->waitting == -1)
		process->waitting = 10;
	else
	{
		player = arena->players;
		while (player)
		{
			if (player->nbr == param->value)
			{
				arena->winner = param->value;
				arena->nbr_live++;
				player->last_live = arena->cycles;
				break ;
			}
			player = player->next;
		}
	}
}
