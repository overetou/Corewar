/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 21:33:58 by overetou          #+#    #+#             */
/*   Updated: 2018/04/17 15:41:56 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int is_valide_param(t_process *process, t_op *op, int nbr_param)
{
	t_param	*param;
	int		i;

	if (process->opcode == 0)
		return (1);
	if (process->opcode < 0 || process->opcode > 16 || op[process->opcode].nbr_param > nbr_param)
		return (0);
	param = process->param;
	i = 0;
	return (1);
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
		//if (process->nbr == 14)
			//ft_printf("LOAD : cycles %d => op_code %d (adr %d)\n", arena->cycles, process->opcode, process->index);
		if(process->opcode >= 0 && process->opcode <= 16)
			((arena->f)[process->opcode])(process->param, arena, process);
		else
		{
			//ft_printf("Cycles %d : The function %d doesnt exist\n", arena->cycles, process->opcode);
			//ft_printf("param code = %d\n", process->param->next->code);
			//exit(0);
			process->waitting = 0;
			process->index = get_valide_adr(process->index + 1);
		}
	}
	else
	{
		nbr_param = load_params(process->param, arena->board, process, arena->op);
		if(is_valide_param(process, arena->op, nbr_param))
		{
			((arena->f)[process->opcode])(process->param, arena, process);
			//if (process->nbr == 14)
				//ft_printf("EXECUTE : cycles %d => op_code %d (adr %d)\n", arena->cycles, process->opcode, process->index);
			process->index = get_valide_adr(process->next_index);
		}
		else
		{
			if (process->opcode >= 0 && process->opcode <= 16 && arena->op[process->opcode].has_ocp)
				process->index++;
			process->index = get_valide_adr(process->index + 1);
			//ft_printf("Cycles %d : The function %d is invalide with %d (%d) param\n", arena->cycles, process->opcode, nbr_param, arena->op[process->opcode].nbr_param);
		}
		process->waitting = -1;
		execute_process(process, arena);
		//ft_printf("after executed op : %d\n", process->opcode);
	}
	//sleep(1);
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
				process->did_live = 0;
				back = process;
				process = process->next;
			}
		}
	}
}

void	do_processes_checks(t_arena *arena, int	*no_nbr_live, int *ctd)
{
	kill_unlively_processes(arena);
	if (!arena->process)
		exit(ft_printf("And the winner is... %s!\n", get_winner(arena->players, arena->winner)));
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

void	execute_cycle(t_arena *arena)
{
	t_process	*process;

	process = arena->process;
	while (process)
	{
		//  if (arena->cycles == 4575)
		//   	ft_printf("adr = %d, op_code = %d\n", process->index, process->opcode);
		(process->waitting)--;
		if (process->waitting < 1)
			execute_process(process, arena);
		process = process->next;
	}
}

int		print_process_state(t_arena *arena)
{
	ft_printf(">>>>>>>>>>>\ncycle = %d\n<<<<<<<<<<<\n", arena->cycles);
	while (arena->process)
	{
		ft_printf("index = %d, waitting = %d, opcode = %d\n", arena->process->index, arena->process->waitting, arena->process->opcode);
		arena->process = arena->process->next;
	}
	return (0);
}

void	execute_vm(t_arena *arena)
{
	int	ctd;
	int	no_nbr_live;

	ctd = CYCLE_TO_DIE;
	no_nbr_live = 0;
	if (arena->aff == NCURSE)
	{
		//initscr();
		//ft_init_color(arena->players, arena);
		//getch();
	}
	while (ctd > 0)
	{
		if ((arena->executed_cycles) == ctd)
			do_processes_checks(arena, &no_nbr_live, &ctd);
		execute_cycle(arena);
		arena->cycles++;
		arena->executed_cycles++;
		//if (arena->cycles == 4553)
		 	//exit(0);
		//	exit(print_process_state(arena));
		if (arena->aff == DUMP && arena->end_cycle < arena->cycles)
			dump_tab(arena);
	}
	//ft_printf("END AFTER %lld cycles\n", arena->cycles);
	if (arena->aff == NCURSE)
	{
		getch();
		//endwin();
	}
}
