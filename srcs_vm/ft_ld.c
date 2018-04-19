/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 21:10:21 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/18 19:35:53 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_ld(t_param *param, t_arena *arena, t_process *process)
{
	int value;

	if (process->waitting == -1)
		process->waitting += 5;
	else if (process->waitting < -1)
		process->waitting = 5;
	else
	{
		process->carry = 0;
		if (!validate_all_reg_nbr(param))
			return ;
		value = get_param_value(param, process, arena, 1);
		param = param->next;
		process->reg[param->value - 1] = value;
		if (!process->reg[param->value - 1])
			process->carry = 1;
		if (arena->debug)
			ft_printf("P %4d | ld %d r%d\n", process->nbr, value, param->value);
	}
}
