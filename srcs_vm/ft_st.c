/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:51:43 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/24 18:09:40 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_st(t_param *param, t_arena *arena, t_process *process)
{
	int value1;
	int value2;

	if (process->waitting <= -1)
		process->waitting = 5 - ((process->waitting == -1) ? 1 : 0);
	else
	{
		if (!validate_all_reg_nbr(param))
			return ;
		value1 = get_param_value(param, process, arena, 1);
		if (arena->debug)
			ft_printf("P %4d | st r%d ", process->nbr, param->value);
		param = param->next;
		value2 = get_param_value(param, process, NULL, 0);
		if (param->code == REG_CODE)
			process->reg[param->value - 1] = value1;
		else
			write_tab(value1, arena, process->index + (value2 % IDX_MOD), 4);
		if (arena->aff == NCURSE && param->code != REG_CODE)
			refresh_arena(arena, process->index + (value2 % IDX_MOD),
				4, process->color);
		if (arena->debug)
			ft_printf("%d\n", param->value);
	}
}
