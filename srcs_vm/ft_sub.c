/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:03:50 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/24 18:19:36 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_sub(t_param *param, t_arena *arena, t_process *process)
{
	int value1;
	int value2;

	if (process->waitting == -1)
		process->waitting += 10;
	else if (process->waitting < -1)
		process->waitting = 10;
	else
	{
		if (!validate_all_reg_nbr(param))
			return ;
		value1 = get_param_value(param, process, arena, 1);
		if (arena->debug)
			ft_printf("P %4d | sub r%d ", process->nbr, param->value);
		param = param->next;
		value2 = get_param_value(param, process, arena, 1);
		if (arena->debug)
			ft_printf("r%d ", param->value);
		param = param->next;
		set_reg_value(param->value - 1, value1 - value2, process);
		if (arena->debug)
			ft_printf("r%d\n", param->value);
	}
}
