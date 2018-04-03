/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:35:47 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/03 19:58:37 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*********************************************/
/************** NE FONCTION PAS **************/
/*********************************************/
void	ft_sti(t_param *param, t_arena *arena, t_process *process)
{
	int value1;
	int value2;
	int value3;

	process->waitting = 25;
	value1 = get_param_value(param, process);
	param = param->next;
	value2 = get_param_value(param, process);
	param = param->next;
	value3 = get_param_value(param, process);
	write_tab(value1, arena, ((value2 + value3) % IDX_MOD), 4);
}
