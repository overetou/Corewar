/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:28:11 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/24 17:45:13 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_ldi(t_param *param, t_arena *arena, t_process *process)
{
	int value1;
	int value2;

	if (process->waitting == -1)
		process->waitting += 25;
	else if (process->waitting < -1)
		process->waitting = 25;
	else
	{
		if (!validate_all_reg_nbr(param))
			return ;
		value1 = get_param_value(param, process, arena, 1);
		param = param->next;
		value2 = get_param_value(param, process, arena, 1);
		param = param->next;
		process->reg[param->value - 1] =
			get_adr_value(arena, process->index +
			((value1 + value2) % IDX_MOD), REG_SIZE);
		if (arena->debug)
			ft_printf("P %4d | ldi %d %d r%d\n       | -> \
				load from %d + %d = %d (with pc and mod %d)\n", process->nbr,
				value1, value2, param->value, value1, value2, value1 + value2,
				process->index + ((value1 + value2) % IDX_MOD));
	}
}
