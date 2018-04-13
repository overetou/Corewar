/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:44:00 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/12 20:36:59 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_lfork(t_param *param, t_arena *arena, t_process *process)
{
	int value;

	if (process->waitting == -1)
		process->waitting = 1000;
	else
	{
		add_process(&(arena->process), dup_process(process));
		value = get_param_value(param, process, arena, 0);
		arena->process->index = (process->index + value) % MEM_SIZE;
		arena->process->waitting = -1;
		execute_process(arena->process, arena);
	}
}
