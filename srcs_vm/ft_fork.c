/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:06:50 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/04 16:45:15 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_fork(t_param *param, t_arena *arena, t_process *process)
{
	if (process->waitting == -1)
	{
		ft_printf("WAITTING FORK\n");
		process->waitting = 800;
	}
	else
	{
		ft_printf("EXECUTE FORK\n");
		add_process(&(arena->process), dup_process(process));
		arena->process->index = process->index + (param->value % IDX_MOD);
	}
}
