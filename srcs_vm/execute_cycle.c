/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 21:33:58 by overetou          #+#    #+#             */
/*   Updated: 2018/04/05 20:08:33 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	execute_process(t_process *process, t_param *param, t_arena *arena)
{
	int	opcode;

	opcode = load_params(param, arena->board, process, arena->op);
	((arena->f)[opcode])(param, arena, process);
	if (opcode != 9)
		process->index = process->next_index;
}

void	execute_cycle(t_arena *arena, t_param *param)
{
	t_process	*head;

	head = arena->process;
	while (head)
	{
		(head->waitting)--;
		if (head->waitting < 1)
			execute_process(head, param, arena);
		head = head->next;
	}
}

void	execute_vm(t_arena *arena, t_param *param)
{
	if (arena->aff == NCURSE)
	{
		initscr();
		ft_init_color(arena->players, arena);
		getch();
	}
	// CHANGER POUR CALCULER LES CYCLES
	while (arena->cycles != CYCLE_TO_DIE)
	{
		execute_cycle(arena, param);
		arena->cycles++;
		if (arena->aff == DUMP && arena->end_cycle >= arena->cycles)
			dump_tab(arena);
	}
	if (arena->aff == NCURSE)
	{
		getch();
		endwin();
	}
}
