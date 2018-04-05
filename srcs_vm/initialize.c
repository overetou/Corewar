/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:32:48 by overetou          #+#    #+#             */
/*   Updated: 2018/04/05 16:41:17 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vm.h"

t_param	*create_three_params(void)
{
	t_param	*new;

	new = (t_param*)malloc(sizeof(t_param));
	new->next = (t_param*)malloc(sizeof(t_param));
	(new->next)->next = (t_param*)malloc(sizeof(t_param));
	((new->next)->next)->next = NULL;
	return (new);
}

t_op	set_op(int ind_option, int has_ocp, int hardcode)
{
	t_op	op;

	op.hardcode = hardcode;
	op.has_ocp = has_ocp;
	op.ind_option = ind_option;
	return (op);
}

t_op	*hardcode_op(t_op *op)
{
	op[0] = set_op(DIRFOR, 0, DIRFOR);
	op[1] = set_op(DIRFOR, 1, 0);
	op[2] = set_op(0, 1, 0);
	op[3] = set_op(0, 1, 0);
	op[4] = set_op(0, 1, 0);
	op[5] = set_op(DIRFOR, 1, 0);
	op[6] = set_op(DIRFOR, 1, 0);
	op[7] = set_op(DIRFOR, 1, 0);
	op[8] = set_op(DIRTWO, 0, DIR_CODE);
	op[9] = set_op(DIRTWO, 1, 0);
	op[10] = set_op(DIRTWO, 1, 0);
	op[11] = set_op(DIRTWO, 0, DIR_CODE);
	op[12] = set_op(DIRFOR, 1, 0);
	op[13] = set_op(DIRTWO, 1, 0);
	op[14] = set_op(DIRTWO, 0, DIR_CODE);
	op[15] = set_op(0, 1, 0);
	return (op);
}

void hardcode_func(t_arena *arena)
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

t_arena	*new_arena()
{
	t_arena	*arena;

	if (!(arena = (t_arena*)malloc(sizeof(t_arena))))
		exit(0);
	arena->board = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE);
	arena->cycles = 0;
	arena->winner = 0;
	arena->op = hardcode_op(arena->op);
	return (arena);
	hardcode_func(arena);
	arena->aff = 0;
	arena->end_cycle = 0;
	arena->number_of_players = 0;
	arena->process = NULL;
	arena->players = NULL;
	return (arena);
}
