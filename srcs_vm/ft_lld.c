/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:42:00 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/04 16:46:56 by ysingaye         ###   ########.fr       */
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
		if (param->code != IND_CODE)
		value = get_param_value(param, process, arena, 0);
		else
		value = get_adr_value(arena, process->index + param->value, 2));
		param = param->next;
		validate_reg_nbr(param);
		process->reg[param->value - 1] = value;
		process->carry = 1;
	}
}
