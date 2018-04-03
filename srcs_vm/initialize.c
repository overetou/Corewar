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
	int		x;
	t_param	*new;

	new = (t_param*)malloc(sizeof(t_param));
	new->next = (t_param*)malloc(sizeof(t_param));
	(new->next)->next = (t_param*)malloc(sizeof(t_param));
	((new->next)->next)->next = NULL;
	return (new);
}

t_op	*hardcode_op(t_op *op)
{
	op[0] = {};
}

void	initialize(t_arena **arena, t_param **param, t_op *op)
{
	ft_bzero(*arena, sizeof(t_arena));
	*param = create_three_params();
	arena->op = hardcode_op(op);
}