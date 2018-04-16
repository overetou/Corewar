/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:44:00 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/16 19:54:12 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_lfork(t_param *param, t_arena *arena, t_process *process)
{
	int value;

	if (process->waitting == -1)
		process->waitting = 1000;
	else
	{
		add_process(&(arena->process), dup_process(process));
		value = get_param_value(param, process, arena, 0);
		arena->process->index = get_valide_adr((process->index + value));
		arena->process->nbr = ++arena->nbr_process;
		arena->process->waitting = -1;
		if (arena->debug)
			ft_printf("P %4d | lfork %d (%d)\n", process->nbr, param->value % MEM_SIZE, arena->process->index);
		execute_process(arena->process, arena);
	}
}
