/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:58:33 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/24 17:40:54 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_add(t_param *param, t_arena *arena, t_process *process)
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
			ft_printf("P %4d | add r%d ", process->nbr, param->value);
		param = param->next;
		value2 = get_param_value(param, process, arena, 1);
		if (arena->debug)
			ft_printf("r%d ", param->value);
		param = param->next;
		set_reg_value(param->value - 1, value1 + value2, process);
		if (arena->debug)
			ft_printf("r%d\n", param->value);
	}
	(void)arena;
}
