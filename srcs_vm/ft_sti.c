/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:35:47 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/18 19:38:23 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_sti(t_param *param, t_arena *arena, t_process *process)
{
	int value1;
	int value2;
	int value3;

	if (process->waitting == -1)
		process->waitting += 25;
	else if (process->waitting < -1)
		process->waitting = 25;
	else
	{
		//if (process->nbr == 17)
		//	ft_printf("CYCLE %d, adr %d\n", arena->cycles, process->index);
		if (!validate_reg_nbr(param))
			return ;
		value1 = get_param_value(param, process, arena, 1);
		if (arena->debug)
			ft_printf("P %4d | sti r%d ", process->nbr, param->value);
		param = param->next;
		if (!validate_reg_nbr(param))
		{
			//ft_printf("FUCK YOU !!!!!!!!!!!!!!!!!! (adr = %d)\n", arena->cycles);
			return ;
		}
		value2 = get_param_value(param, process, arena, 1);
		param = param->next;
		if (!validate_reg_nbr(param))
		{
			//ft_printf("FUCK YOU !!!!!!!!!!!!!!!!!! (adr = %d)\n", arena->cycles);
			return ;
		}
		value3 = get_param_value(param, process, arena, 1);
		write_tab(value1, arena, process->index + ((value2 + value3) % IDX_MOD), 4);
		if (arena->aff == NCURSE)
			refresh_arena(arena, process->index + ((value2 + value3) % IDX_MOD), 4, process->color);
		if (arena->debug)
			ft_printf("%d %d\n       | -> store to %d + %d = %d (with pc and mod %d)\n", value2, value3, value2, value3, value2 + value3, process->index + ((value2 + value3) % IDX_MOD));
	}
}
