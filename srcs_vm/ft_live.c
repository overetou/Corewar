/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:26:23 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/24 17:45:42 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_live(t_param *param, t_arena *arena, t_process *process)
{
	t_player	*player;

	if (process->waitting == -1)
		process->waitting += 10;
	else if (process->waitting < -1)
		process->waitting = 10;
	else
	{
		player = arena->players;
		while (player)
		{
			if (player->nbr == param->value)
			{
				arena->winner = param->value;
				player->last_live = arena->cycles;
				break ;
			}
			player = player->next;
		}
		process->did_live = 1;
		arena->nbr_live++;
		if (arena->debug)
			ft_printf("P %4d | live %d\n", process->nbr, param->value);
	}
}
