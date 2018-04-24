/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:06:50 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/24 17:42:47 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_fork(t_param *param, t_arena *arena, t_process *process)
{
	int value;

	if (process->waitting == -1)
		process->waitting += 800;
	else if (process->waitting < -1)
		process->waitting = 800;
	else
	{
		add_process(&(arena->process), dup_process(process, arena));
		value = get_param_value(param, process, arena, 0);
		arena->process->index =
			get_valide_adr(process->index + (value % IDX_MOD));
		arena->process->nbr = ++arena->nbr_process;
		arena->process_cpt++;
		arena->process->waitting = 0;
		if (arena->debug)
			ft_printf("P %4d | fork %d (%d)\n",
				process->nbr, param->value, process->index + (value % IDX_MOD));
	}
}
