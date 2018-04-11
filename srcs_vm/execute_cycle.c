/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 21:33:58 by overetou          #+#    #+#             */
/*   Updated: 2018/04/11 19:50:44 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int is_valide_param(t_process *process, t_op *op, int nbr_param)
{
	t_param	*param;
	int		i;

	if (process->opcode == 0)
		return (1);
	if(process->opcode < 0 || process->opcode > 16 || op[process->opcode].nbr_param != nbr_param)
	{
		//ft_printf("AAAAAAAAAAAAAAAAA\n");
		return (0);
	}
	param = process->param;
	i = 0;
	while (i < nbr_param)
	{
		if (param->code == REG_CODE && !HAS_REG_PERM(op[process->opcode].perm[i]))
		{
			//ft_printf("param %d dont have reg perm\n", i+1);
			return (0);
		}
		else if (param->code == IND_CODE && !HAS_IND_PERM(op[process->opcode].perm[i]))
		{
			//ft_printf("param %d dont have ind perm\n", i+1);
			return (0);
		}
		else if ((param->code == DIRTWO || param->code == DIRFOR) && !HAS_DIR_PERM(op[process->opcode].perm[i]))
		{
			//ft_printf("param %d dont have dir perm\n", i+1);
			return (0);
		}
		i++;
		param = param->next;
	}
	return (1);
}

void	execute_process(t_process *process, t_arena *arena)
{
	int nbr_param;

	if (process->waitting == -1)
	{
		process->opcode = arena->board[process->index];
		nbr_param = load_params(process->param, arena->board, process, arena->op);
		if(is_valide_param(process, arena->op, nbr_param))
			((arena->f)[process->opcode])(process->param, arena, process);
		else
		{
			//ft_printf("The function %d (%d) is invalide with %d param\n", process->opcode, arena->op[process->opcode].nbr_param, nbr_param);
			//ft_printf("param code = %d\n", process->param->next->code);
			//exit(0);
			process->waitting = 0;
			process->index++;
		}
		ft_printf("LOAD : cycles %d => op_code %d\n", arena->cycles, process->opcode);
	}
	else
	{
		((arena->f)[process->opcode])(process->param, arena, process);
		process->index = process->next_index;
		process->waitting = -1;
		ft_printf("EXECUTE : cycles %d => op_code %d\n", arena->cycles, process->opcode);
		execute_process(process, arena);
		//ft_printf("after executed op : %d\n", process->opcode);
	}
	//sleep(1);
}

void	execute_cycle(t_arena *arena)
{
	t_process	*process;

	process = arena->process;
	while (process)
	{
		(process->waitting)--;
		if (process->waitting < 1)
			execute_process(process, arena);
		process = process->next;
	}
}

void	kill_unlively_processes(t_arena *arena)
{
	t_process	*process;
	t_process	*back;

	if ((arena->process))
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
			{
				process->did_live = 0;
				process = process->next;
			}
		}
		back = arena->process;
		while (process)
		{
			if (!(process->did_live))
			{
				back->next = process->next;
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
	if ((arena->nbr_live) >= NBR_LIVE)
		*ctd -= CYCLE_DELTA;
	else
		(*no_nbr_live)++;
	if (*no_nbr_live == MAX_CHECKS)
	{
		*ctd -= CYCLE_DELTA;
		*no_nbr_live = 0;
	}
	arena->executed_cycles = 0;
	arena->nbr_live = 0;
}

void	execute_vm(t_arena *arena)
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
	while (ctd > 0)
	{
		if ((arena->executed_cycles) % ctd == 0 && arena->executed_cycles)
			do_processes_checks(arena, &no_nbr_live, &ctd);
		execute_cycle(arena);
		arena->cycles++;
		arena->executed_cycles++;
		if (arena->aff == DUMP && arena->end_cycle < arena->cycles)
			dump_tab(arena);
	}
	if (arena->aff == NCURSE)
	{
		getch();
		endwin();
	}
}
