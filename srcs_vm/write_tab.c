/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:05:25 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/12 15:12:00 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_tab(unsigned int to_write, t_arena *arena, int adr, int len)
{
    int c;

	if (adr >= MEM_SIZE || adr <= MEM_SIZE * -1)
		write_tab(to_write, arena, adr % MEM_SIZE, len);
    else if (adr < 0)
        write_tab(to_write, arena, MEM_SIZE + adr, len);
    else if (len)
    {
        write_tab((to_write / 256), arena, adr, --len);
        c = to_write % 256;
		arena->board[adr + len] = c;
    }
}
