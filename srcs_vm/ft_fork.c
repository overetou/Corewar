/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:06:50 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/18 16:13:39 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_fork(t_param *param, t_arena *arena, t_process *process)
{
	int value;

	if (process->waitting == -1)
		process->waitting = 800;
	else
	{
		//if (process->nbr == 12)
		//	ft_printf("cycle %d, adr %d\n", arena->cycles, process->index);
		add_process(&(arena->process), dup_process(process));
		value = get_param_value(param, process, arena, 0);
		arena->process->index = get_valide_adr(process->index + (value % IDX_MOD));
		arena->process->nbr = ++arena->nbr_process;
		arena->process->waitting = -1;
		if (arena->debug)
			ft_printf("P %4d | fork %d (%d)\n", process->nbr, param->value % MEM_SIZE, arena->process->index);
		execute_process(arena->process, arena);
	}
}
