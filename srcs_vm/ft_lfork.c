/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:44:00 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/24 17:45:24 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_lfork(t_param *param, t_arena *arena, t_process *process)
{
	int value;

	if (process->waitting == -1)
		process->waitting += 1000;
	else if (process->waitting < -1)
		process->waitting = 1000;
	else
	{
		add_process(&(arena->process), dup_process(process, arena));
		value = get_param_value(param, process, arena, 0);
		arena->process->index = get_valide_adr((process->index + value));
		arena->process->nbr = ++arena->nbr_process;
		arena->process_cpt++;
		arena->process->waitting = 0;
		if (arena->debug)
			ft_printf("P %4d | lfork %d (%d)\n",
				process->nbr, param->value, process->index + value);
	}
}
