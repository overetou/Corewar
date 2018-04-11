/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:58:33 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/11 19:23:35 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_add(t_param *param, t_arena *arena, t_process *process)
{
	int value1;
	int value2;

	if (process->waitting == -1)
		process->waitting = 10;
	else
	{
		process->carry = 0;
		value1 = get_param_value(param, process, arena, 0);
		param = param->next;
		value2 = get_param_value(param, process, arena, 0);
		param = param->next;
		if (validate_reg_nbr(param))
		{
			process->reg[param->value - 1] = value1 + value2;
			if (!process->reg[param->value - 1])
				process->carry = 1;
		}
	}
	(void)arena;
}
