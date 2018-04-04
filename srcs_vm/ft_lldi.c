/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:06:50 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/03 19:59:25 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_lldi(t_param *param, t_arena *arena, t_process *process)
{
	int value1;
	int value2;

	process->waitting = 50;
	process->carry = 0;
	value1 = get_param_value(param, process, arena, 0);
	param = param->next;
	value2 = get_param_value(param, process, arena, 0);
	param = param->next;
	validate_reg_nbr(param);
	process->reg[param->value - 1] =
		get_adr_value(arena, (value1 + value2), REG_SIZE);
	process->carry = 1;
}
