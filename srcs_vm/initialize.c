/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:32:48 by overetou          #+#    #+#             */
/*   Updated: 2018/04/25 18:53:49 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_param		*create_three_params(void)
{
	t_param	*new;
	t_param *old;
	int		i;

	old = NULL;
	i = 0;
	while (i != 3)
	{
		new = (t_param*)malloc(sizeof(t_param));
		if (new == NULL)
		{
			if (old)
			{
				free_param(old);
			}
			return (NULL);
		}
		new->next = old;
		old = new;
		i++;
	}
	return (new);
}

void		hardcode_func(t_arena *arena)
{
	arena->f[0] = ft_void;
	arena->f[1] = ft_live;
	arena->f[2] = ft_ld;
	arena->f[3] = ft_st;
	arena->f[4] = ft_add;
	arena->f[5] = ft_sub;
	arena->f[6] = ft_and;
	arena->f[7] = ft_or;
	arena->f[8] = ft_xor;
	arena->f[9] = ft_zjmp;
	arena->f[10] = ft_ldi;
	arena->f[11] = ft_sti;
	arena->f[12] = ft_fork;
	arena->f[13] = ft_lld;
	arena->f[14] = ft_lldi;
	arena->f[15] = ft_lfork;
	arena->f[16] = ft_aff;
}

t_arena		*new_arena(void)
{
	t_arena	*arena;

	if (!(arena = (t_arena*)malloc(sizeof(t_arena))))
		ft_error("Memory could not be allocated.\n", arena);
	if (!(arena->board =
		(unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE)))
		ft_error("Memory could not be allocated.", arena);
	bzero(arena->board, MEM_SIZE);
	arena->cycles = 0;
	arena->debug = 0;
	arena->executed_cycles = 0;
	arena->winner = 0;
	hardcode_op(arena->op);
	hardcode_func(arena);
	arena->aff = 0;
	arena->end_cycle = 0;
	arena->nbr_of_playr = 0;
	arena->nbr_process = 0;
	arena->nbr_live = 0;
	arena->process_cpt = 0;
	arena->process = NULL;
	arena->players = NULL;
	return (arena);
}
