/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:42:00 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/11 19:25:11 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_lld(t_param *param, t_arena *arena, t_process *process)
{
	int value;

	if (process->waitting == -1)
		process->waitting = 10;
	else
	{
		process->carry = 0;
		value = get_param_value(param, process, arena, 0);
		param = param->next;
		if (validate_reg_nbr(param))
		{
			process->reg[param->value - 1] = value;
			if (!process->reg[param->value - 1])
				process->carry = 1;
		}
	}
}
