/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:05:25 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/13 15:34:40 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_valide_adr(int adr)
{
	if (adr >= MEM_SIZE || adr <= MEM_SIZE * -1)
		return (get_valide_adr(adr % MEM_SIZE));
    else if (adr < 0)
        return (get_valide_adr(MEM_SIZE + adr));
	else
		return (adr);
}

void	write_tab(unsigned int to_write, t_arena *arena, int adr, int len)
{
    int c;

	adr = get_valide_adr(adr);
	if (len)
    {
        write_tab((to_write / 256), arena, adr, --len);
        c = to_write % 256;
		arena->board[adr + len] = c;
    }
}
