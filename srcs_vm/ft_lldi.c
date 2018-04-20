/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:06:50 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/20 16:49:28 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_lldi(t_param *param, t_arena *arena, t_process *process)
{
	int value1;
	int value2;

	if (process->waitting == -1)
		process->waitting += 50;
	else if (process->waitting < -1)
		process->waitting = 50;
	else
	{
		if (!validate_all_reg_nbr(param))
			return ;
		value1 = get_param_value(param, process, arena, 0);
		param = param->next;
		value2 = get_param_value(param, process, arena, 0);
		param = param->next;
		process->reg[param->value - 1] =
			get_adr_value(arena, process->index + value1 + value2, REG_SIZE);
			process->carry = 0;
		if (!process->reg[param->value - 1])
			process->carry = 1;
		if (arena->debug)
			ft_printf("P %4d | lldi %d %d r%d\n       | -> load from %d + %d = %d (with pc %d)\n", process->nbr, value1, value2, param->value, value1, value2, value1 + value2, process->index + value1 + value2);
	}
}
