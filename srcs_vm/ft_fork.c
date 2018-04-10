/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:06:50 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/10 15:12:38 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_fork(t_param *param, t_arena *arena, t_process *process)
{
	int value;

	if (process->waitting == -1)
		process->waitting = 800;
	else
	{
		add_process(&(arena->process), dup_process(process));
		value = get_param_value(param, process, arena, 1);
		arena->process->index = (process->index + value) % IDX_MOD;
	}
}
