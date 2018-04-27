/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 21:33:58 by overetou          #+#    #+#             */
/*   Updated: 2018/04/25 17:37:47 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		is_valide_param(t_process *prcss, t_op *op, int nbr_param)
{
	t_param	*prm;
	int		i;

	if (prcss->opcode == 0)
		return (1);
	if (prcss->opcode < 0 || prcss->opcode > 16 ||
	op[prcss->opcode].nbr_param != nbr_param)
		return (0);
	prm = prcss->param;
	i = -1;
	while (++i < nbr_param)
	{
		if (!prm->code || (prm->code == REG_CODE &&
			(op[prcss->opcode].perm[i] & T_REG) == 0))
			return (0);
		else if (prm->code == IND_CODE &&
			(op[prcss->opcode].perm[i] & T_IND) == 0)
			return (0);
		else if ((prm->code == DIRTWO || prm->code == DIRFOR) &&
		(op[prcss->opcode].perm[i] & T_DIR) == 0)
			return (0);
		prm = prm->next;
	}
	return (1);
}

void	execute_process(t_process *prcss, t_arena *ar)
{
	if (prcss->waitting < 0)
	{
		prcss->opcode = ar->board[get_valide_adr(prcss->index)];
		if (prcss->opcode >= 0 && prcss->opcode <= 16)
			((ar->f)[prcss->opcode])(prcss->param, ar, prcss);
		else
		{
			prcss->waitting = 0;
			prcss->index = get_valide_adr(prcss->index + 1);
		}
	}
	else
	{
		if (prcss->param == NULL)
			ft_error("Memory could not be allocated", ar);
		prcss->nbr_param = load_params(prcss->param, ar->board, prcss, ar->op);
		if (is_valide_param(prcss, ar->op, prcss->nbr_param))
			((ar->f)[prcss->opcode])(prcss->param, ar, prcss);
		prcss->index = get_valide_adr(prcss->next_index);
	}
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

void	vm_loop(t_arena *arena, int ctd, int no_nbr_live)
{
	while (ctd > 0)
	{
		if (arena->aff == NCURSE)
			refresh_status(arena, ctd, 0);
		execute_cycle(arena);
		if ((arena->executed_cycles) == ctd)
			do_processes_checks(arena, &no_nbr_live, &ctd);
		arena->cycles++;
		arena->executed_cycles++;
		if (arena->aff == DUMP && arena->end_cycle < arena->cycles)
			dump_tab(arena);
	}
	execute_cycle(arena);
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
		curs_set(0);
		ft_init_color(arena->players, arena);
	}
	vm_loop(arena, ctd, no_nbr_live);
	if (arena->aff == NCURSE)
	{
		refresh_status(arena, ctd, 1);
		getch();
		endwin();
	}
}
