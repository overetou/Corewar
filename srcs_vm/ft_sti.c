/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:35:47 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/24 18:18:36 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_sti(t_param *param, t_arena *arena, t_process *process)
{
	int value1;
	int value2;
	int value3;

	if (process->waitting <= -1)
		process->waitting = 25 - ((process->waitting == -1) ? 1 : 0);
	else
	{
		if (!validate_all_reg_nbr(param))
			return ;
		value1 = get_param_value(param, process, arena, 1);
		if (arena->debug)
			ft_printf("P %4d | sti r%d ", process->nbr, param->value);
		value2 = get_param_value((param = param->next), process, arena, 1);
		value3 = get_param_value((param = param->next), process, arena, 1);
		write_tab(value1, arena,
			process->index + ((value2 + value3) % IDX_MOD), 4);
		if (arena->aff == NCURSE)
			refresh_arena(arena, process->index + ((value2 + value3) % IDX_MOD),
				4, process->color);
		if (arena->debug)
			ft_printf("%d %d\n       | -> store to %d + %d = %d (with pc \
				and mod %d)\n", value2, value3, value2, value3, value2 + value3,
				process->index + ((value2 + value3) % IDX_MOD));
	}
}
