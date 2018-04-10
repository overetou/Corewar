/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:06:50 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/10 19:12:55 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_lldi(t_param *param, t_arena *arena, t_process *process)
{
	int value1;
	int value2;

	if (process->waitting == -1)
		process->waitting = 50;
	else
	{
		process->carry = 0;
		value1 = get_param_value(param, process, arena, 0);
		param = param->next;
		value2 = get_param_value(param, process, arena, 0);
		param = param->next;
		validate_reg_nbr(param);
		process->reg[param->value - 1] =
			get_adr_value(arena, process->index + value1 + value2, REG_SIZE);
		if (!process->reg[param->value - 1])
			process->carry = 1;
	}
}
