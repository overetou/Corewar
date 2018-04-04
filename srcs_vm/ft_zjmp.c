/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:47:55 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/03 19:54:14 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_zjmp(t_param *param, t_arena *arena, t_process *process)
{
	process->waitting = 20;
	if (process->carry)
		process->index += param->value;
}
