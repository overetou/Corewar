/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:56:58 by overetou          #+#    #+#             */
/*   Updated: 2018/03/21 14:56:59 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int     left_shift(int to_shift, int cycles)
{
    while (cycles)
    {
        to_shift << 2;
        cycles--;
    }
    return (to_shift);
}

int     assemble_ocp(t_cmd *cmd)
{
    int     param_nb;
    t_param *head;
    int     ocp;
    int     mask;

    ocp = 0;
    param_nb = cmd->op->param_numbers;
    head = cmd->param;
    while (param_nb)
    {
        mask = left_shift(head->code, param_nb);
        ocp = ocp | mask;
        head = head->next;
        param_nb--;
    }
    return (ocp);
}
