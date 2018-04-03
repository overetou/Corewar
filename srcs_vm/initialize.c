/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:32:48 by overetou          #+#    #+#             */
/*   Updated: 2018/04/03 14:32:51 by overetou         ###   ########.fr       */
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

void	initialize(t_arena **arena, t_param **param, t_op *op)
{
	ft_bzero(*arena, sizeof(t_arena));
	*param = create_three_params();
	arena->op = hardcode_op(op);
}