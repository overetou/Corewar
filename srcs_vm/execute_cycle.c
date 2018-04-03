/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 21:33:58 by overetou          #+#    #+#             */
/*   Updated: 2018/03/29 21:33:59 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	launch_op(t_param *p, t_arena *arena, t_process *process, int opcode)
{
	((arena->f)[opcode])(param, arena, process);
//	if (opcode == operations qui bougnet deja le process)
//		return ;
//	else
//		move_process(process, param);
}

void	execute_process(t_process *process, t_param *param, t_arena *arena)
{
	int	opcode;

	opcode = load_params(param, arena->board, process->index, arena->op);
	launch_operation(param, arena, process, opcode);
}

void	execute_cycle(t_arena *arena, t_param *param)
{
	t_process	*head;

	head = arena->process;
	while (head)
	{
		if (head->waitting)
			(head->waitting)--;
		else
			execute_process(head, param, arena);
		head = head->next;
	}
}
