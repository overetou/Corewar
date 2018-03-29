/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 21:10:21 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/29 21:20:11 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_ld(t_param *param, t_arena *arena, t_process *process)
{
	int value;

	process->carry = 0;
	value = param->value;
	param = param->next;
	if (param->value < 1 || param->value > REG_NUMBER)
		exit(ft_printf("ERROR FT_LD REG_NUMBER\n"));
	process->reg[param->value - 1] = value;
	process->carry = 1;
}
