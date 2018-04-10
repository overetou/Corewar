/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:11:18 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/10 15:51:31 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_void(t_param *param, t_arena *arena, t_process *process)
{
	process->waitting++;
	process->next_index = process->index + 1;
	(void)param;
	(void)arena;
}
