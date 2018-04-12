/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:26:23 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/12 17:01:48 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_live(t_param *param, t_arena *arena, t_process *process)
{
	t_player	*player;
	int			next;
	int test;

	test = 1;
	if (process->waitting == -1)
		process->waitting = 10;
	else
	{
		next = process->index + 1;
		player = arena->players;
		while (player)
		{
			if (player->nbr == param->value)
			{
				arena->winner = param->value;
				arena->nbr_live++;
				player->last_live = arena->cycles;
				next = process->next_index;
				process->did_live = 1;
				test = 0;
				break ;
			}
			player = player->next;
		}
		//if (test)
			//ft_printf("%d\n", param->value);
			//arena->cycles -= 9;
		//process->next_index = next;
	}
}
