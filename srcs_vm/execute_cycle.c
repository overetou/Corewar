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
	if (process->waitting == -1)
	{
		process->opcode = arena->board[process->index];
		if(process->opcode >= 0 && process->opcode <= 16)
			((arena->f)[process->opcode])(param, arena, process);
		else
			process->waitting = 0;
	}
	else
	{
		//ft_printf("before executed op : %d\n", process->opcode);
		load_params(param, arena->board, process, arena->op);
		((arena->f)[process->opcode])(param, arena, process);
		process->index = process->next_index;
		//ft_printf("after executed op : %d\n", process->opcode);
	}
	//sleep(1);
}

void	execute_cycle(t_arena *arena, t_param *param)
{
	t_process	*process;

	process = arena->process;
	while (process)
	{
		(process->waitting)--;
		if (process->waitting < 1)
			execute_process(process, param, arena);
		process = process->next;
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
	ft_printf("nbr cycles = %d\n", arena->cycles);
	if (arena->aff == NCURSE)
	{
		getch();
		endwin();
	}
}
