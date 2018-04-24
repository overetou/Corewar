/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:47:55 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/24 18:20:40 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_zjmp(t_param *param, t_arena *arena, t_process *process)
{
	int value;

	if (process->waitting == -1)
		process->waitting += 20;
	else if (process->waitting < -1)
		process->waitting = 20;
	else
	{
		if (!validate_all_reg_nbr(param))
			return ;
		value = get_param_value(param, process, arena, 1);
		if (process->carry)
			process->next_index = process->index + (value % IDX_MOD);
		if (arena->debug)
			ft_printf("P %4d | zjmp %d %s\n", process->nbr, param->value,
				((process->carry) ? "OK" : "FAILED"));
	}
	(void)arena;
}
