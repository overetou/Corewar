/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:04:50 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/30 15:18:08 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_and(t_param *param, t_arena *arena, t_process *process)
{
	int value1;
	int value2;

	process->carry = 0;
	value1 = get_param_value(param, process);
	param = param->next;
	value2 = get_param_value(param, process);
	param = param->next;
	validate_reg_nbr(param);
	process->reg[param->value - 1] = value1 & value2;
	process->carry = 1;
}
