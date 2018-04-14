/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:09:04 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/13 15:45:09 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		validate_reg_nbr(t_param *param)
{
	if (param->code == REG_CODE && (param->value < 1 || param->value > REG_NUMBER))
		return (0);
	return (1);
}

int		get_adr_value(t_arena *arena, int index, int nbr_oct)
{
	int value;
	int i;

	value = 0;
	i = 0;
	index = get_valide_adr(index);
	while ((index + i) < MEM_SIZE && i < nbr_oct)
	{
		value = value << 8;
		value = value | arena->board[index + i];
		i++;
	}
	return (value);
}

int		get_param_value(t_param *param, t_process *process, t_arena *arena, int has_mod)
{
	int value;

	if (param->code == IND_CODE || param->code == DIRTWO)
		param->value = (short)param->value;
	if (param->code == REG_CODE)
	{
		if (validate_reg_nbr(param))
			return (process->reg[param->value - 1]);
		return (0);
	}
	else if (arena && param->code == IND_CODE)
	{
		if (has_mod)
			value = get_adr_value(arena, process->index + (param->value % IDX_MOD), 4);
		else
			value = get_adr_value(arena, process->index + param->value, 4);
		return (value);
	}
	else
		return (param->value);
}
