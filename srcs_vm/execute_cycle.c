/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 21:33:58 by overetou          #+#    #+#             */
/*   Updated: 2018/04/10 20:18:07 by ysingaye         ###   ########.fr       */
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
		process->waitting = -1;
		execute_process(process, param, arena);
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

void	kill_unlively_processes(t_arena *arena)
{
	t_process	*process;
	t_process	*back;

	if (arena->process)
	{
		process = arena->process;
		while(process == arena->process && process)
		{
			if (!(process->did_live))
			{
				arena->process = process->next;
				free(process);
				process = arena->process;
			}
			else
				process = process->next;
		}
		back = arena->process;
		while (process)
		{
			if (!(process->did_live))
			{
				back = process->next;
				free(process);
				process = back->next;
			}
			else
			{
				back = process;
				process = process->next;
			}
		}
	}
}

void	do_processes_checks(t_arena *arena, int	*no_nbr_live, int *ctd)
{
	kill_unlively_processes(arena);
	if (arena->nbr_live >= NBR_LIVE)
		*ctd -= CYCLE_DELTA;
	else
		(*no_nbr_live)++;
	if (*no_nbr_live == MAX_CHECKS)
	{
		*ctd -= CYCLE_DELTA;
		*no_nbr_live = 0;
	}
}

void	execute_vm(t_arena *arena, t_param *param)
{
	int	ctd;
	int	no_nbr_live;

	ctd = CYCLE_TO_DIE;
	no_nbr_live = 0;
	if (arena->aff == NCURSE)
	{
		initscr();
		ft_init_color(arena->players, arena);
		getch();
	}
	// CHANGER POUR CALCULER LES CYCLES
	while (ctd)
	{
		if (arena->cycles % ctd == 0 && arena->cycles)
			do_processes_checks(arena, &no_nbr_live, &ctd);
		execute_cycle(arena, param);
		arena->cycles++;
		if (arena->aff == DUMP && arena->end_cycle < arena->cycles)
			dump_tab(arena);
	}
	ft_printf("CYCLES = %d\n", arena->cycles);
	if (arena->aff == NCURSE)
	{
		getch();
		endwin();
	}
}
