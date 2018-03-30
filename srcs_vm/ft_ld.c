/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 21:10:21 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/30 17:03:27 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/**
lld WRITE IN 2 octets FOR INDIRECT
**/
void	ft_ld(t_param *param, t_arena *arena, t_process *process)
{
	int value;

	process->carry = 0;
	value = get_param_value(param, process);
	param = param->next;
	validate_reg_nbr(param);
	// ADD MOD FOR INDIRECT
	process->reg[param->value - 1] = value;
	process->carry = 1;
}
