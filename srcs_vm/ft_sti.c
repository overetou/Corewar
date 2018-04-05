/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:35:47 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/05 14:02:31 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_sti(t_param *param, t_arena *arena, t_process *process)
{
	int value1;
	int value2;
	int value3;

	if (process->waitting == -1)
		process->waitting = 25;
	else
	{
		value1 = get_param_value(param, process, arena, 1);
		param = param->next;
		value2 = get_param_value(param, process, arena, 1);
		param = param->next;
		value3 = get_param_value(param, process, arena, 1);
		write_tab(value1, arena, ((value2 + value3) % IDX_MOD), 4);
		if (process->aff == NCURSE)
			refresh_arena(arena, ((value2 + value3) % IDX_MOD), 4, process->color);	
	}
}
