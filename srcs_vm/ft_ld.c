/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 21:10:21 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/03 19:51:54 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_ld(t_param *param, t_arena *arena, t_process *process)
{
	int value;

	process->waitting = 5;
	process->carry = 0;
	value = get_param_value(param, process, arena, 1);
	param = param->next;
	validate_reg_nbr(param);
	process->reg[param->value - 1] = value;
	process->carry = 1;
}
