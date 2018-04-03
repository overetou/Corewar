/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:26:23 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/03 19:51:43 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_live(t_param *param, t_arena *arena, t_process *process)
{
	t_player *player;

	process->waitting = 10;
	player = arena->player;
	while (player)
	{
		if (player->nbr == param->value)
		{
			champ->winner = param->value;
			player->nbr_live++;
			player->last_live = arena->cycles;
			break ;
		}
		player = player->next;
	}
}
