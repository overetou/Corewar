/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:28:22 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/24 17:51:44 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_or(t_param *param, t_arena *arena, t_process *process)
{
	int value1;
	int value2;

	if (process->waitting == -1)
		process->waitting += 6;
	else if (process->waitting < -1)
		process->waitting = 6;
	else
	{
		if (!validate_all_reg_nbr(param))
			return ;
		value1 = get_param_value(param, process, arena, 1);
		param = param->next;
		value2 = get_param_value(param, process, arena, 1);
		param = param->next;
		set_reg_value(param->value - 1, value1 | value2, process);
		if (arena->debug)
			ft_printf("P %4d | or %d %d r%d\n",
				process->nbr, value1, value2, param->value);
	}
}
