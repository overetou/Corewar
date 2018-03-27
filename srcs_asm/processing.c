/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:56:58 by overetou          #+#    #+#             */
/*   Updated: 2018/03/26 17:58:04 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int     assemble_ocp(t_cmd *cmd)
{
    t_param *head;
    int     ocp;
    int     i;

    ocp = 0;
    i = 0;
    head = cmd->param;
    while (head)
    {
        ocp = ocp | head->code;
        ocp = ocp << 2;
        head = head->next;
        i++;
    }
    while (i < 3)
    {
        ocp = ocp << 2;
        i++;
    }
    return (ocp);
}
