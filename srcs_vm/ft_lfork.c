/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:44:00 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/03 19:59:34 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_lfork(t_param *param, t_arena *arena, t_process *process)
{
	process->waitting = 1000;
	add_process(&(arena->process), dup_process(process));
	arena->process->index = process->index + param->value;
}
