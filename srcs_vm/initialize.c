/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:32:48 by overetou          #+#    #+#             */
/*   Updated: 2018/04/05 15:17:01 by ysingaye         ###   ########.fr       */
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

void (*f[17])hardcode_func()
{
	void	 (*f[17])(t_param, t_arena, t_process);

	f[0] = ft_void;
	f[1] = ft_live;
	f[2] = ft_ld;
	f[3] = ft_st;
	f[4] = ft_add;
	f[5] = ft_sub;
	f[6] = ft_and;
	f[7] = ft_or;
	f[8] = ft_xor;
	f[9] = ft_zjmp;
	f[10] = ft_ldi;
	f[11] = ft_sti;
	f[12] = ft_fork;
	f[13] = ft_lld;
	f[14] = ft_lldi;
	f[15] = ft_lfork;
	f[16] = ft_aff;
	return (f)
}

t_arena	*new_arena()
{
	t_arena	*arena;

	if (!(arena = (t_arena*)malloc(sizeof(t_arena)))
		exit(0);
	arena->board = malloc(sizeof(unsigned char) * MEM_SIZE);
	arena->cycles = 0;
	arena->winner = 0;
	arena->op = hardcode_op(arena->op);
	arena->f = hardcode_func();
	arena->aff = 0;
	arena->end_cycle = 0;
	arena->number_of_players = 0;
	arena->process = NULL;
	arena->players = NULL;
}
