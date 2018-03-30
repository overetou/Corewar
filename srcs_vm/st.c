/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:51:43 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/30 16:34:40 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_st(t_param *param, t_arena *arena, t_process *process)
{
	int value1;
	int value2;

	value1 = get_param_value(param, process);
	param = param->next;
	value2 = get_param_value(param, process);
	if (param->code == REG_CODE)
		process->reg[param->value - 1] = value1;
	else
		write_tab(value1, arena, (value2 % IDX_MOD), 4);
}
