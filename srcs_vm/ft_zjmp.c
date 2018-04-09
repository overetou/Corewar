/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:47:55 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/05 16:12:53 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_zjmp(t_param *param, t_arena *arena, t_process *process)
{
	if (process->waitting == -1)
		process->waitting = 20;
	else
	{
		if (process->carry)
			process->next_index = process->index + (short)param->value;
	}
	(void)arena;
}
