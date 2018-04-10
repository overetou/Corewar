/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:05:25 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/10 14:45:28 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_tab(unsigned int to_write, t_arena *arena, int adr, int len)
{
    int c;

    if (adr < 0)
        write_tab(to_write, arena, MEM_SIZE + adr, len);
    else if (adr > MEM_SIZE)
        write_tab(to_write, arena, adr % MEM_SIZE, len);
    if (len)
    {
        write_tab((to_write / 256), arena, adr, --len);
        c = to_write % 256;
		arena->board[adr + len] = c;
    }
}
