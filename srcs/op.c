/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:39:11 by overetou          #+#    #+#             */
/*   Updated: 2018/03/20 16:39:24 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_op    *new_op(t_op *op2)
{
    t_op *op;

    if (!(op = (t_op*)(malloc(sizeof(t_op)))))
        return (NULL);
    op->short_name = op2->short_name;
    op->param_numbers = op2->param_numbers;
    op->perm[0] = op2->perm[0];
    op->perm[1] = op2->perm[1];
    op->perm[2] = op2->perm[2];
    op->perm[3] = op2->perm[3];
    op->opcode = op2->opcode;
    op->cycles_numbers = op2->cycles_numbers;
    op->full_name = op2->full_name;
    op->has_ocp = op2->has_ocp;
    op->dir_size = op2->dir_size;
    op->next = NULL;
}
