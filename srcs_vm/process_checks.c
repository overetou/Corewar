/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:27:55 by overetou          #+#    #+#             */
/*   Updated: 2018/04/27 18:32:49 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	check_remainer(t_process *back, t_process *process, t_arena *arena)
{
	while (process)
	{
		if (!(process->did_live))
		{
			back->next = process->next;
			free_param(process->param);
			free(process);
			process = back->next;
			arena->process_cpt--;
		}
		else
		{
			process->did_live = 0;
			back = process;
			process = process->next;
		}
	}
}

void	kill_unlively_processes(t_arena *arena)
{
	t_process	*process;

	if ((arena->process))
	{
		process = arena->process;
		while (process == arena->process && process)
		{
			if (!(process->did_live))
			{
				arena->process = process->next;
				free_param(process->param);
				free(process);
				process = arena->process;
				arena->process_cpt--;
			}
			else
			{
				process->did_live = 0;
				process = process->next;
			}
		}
		check_remainer(arena->process, process, arena);
	}
}

void	end_execution(t_arena *ar, int *ctd)
{
	if (ar->aff == NCURSE)
	{
		refresh_status(ar, *ctd, 1);
		getch();
		endwin();
	}
	ft_printf("And the winner is... %s!\n",
	get_winner(ar->players, ar->winner));
	free_arena(ar);
	exit(0);
}

void	reset_players_nbr_live(t_player *player)
{
	while (player)
	{
		player->nbr_live = 0;
		player = player->next;
	}
}

void	do_processes_checks(t_arena *arena, int *no_nbr_live, int *ctd)
{
	kill_unlively_processes(arena);
	if (!arena->process)
		end_execution(arena, ctd);
	if ((arena->nbr_live) >= NBR_LIVE)
	{
		*ctd -= CYCLE_DELTA;
		*no_nbr_live = 0;
		reset_players_nbr_live(arena->players);
	}
	else
		(*no_nbr_live)++;
	if (*no_nbr_live == MAX_CHECKS)
	{
		*ctd -= CYCLE_DELTA;
		*no_nbr_live = 0;
		reset_players_nbr_live(arena->players);
	}
	arena->executed_cycles = 0;
	arena->nbr_live = 0;
}
