/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:05:25 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/27 18:24:37 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	dump_tab(t_arena *arena)
{
	int i;

	i = 0;
	ft_printf("0x%.4x : ", i);
	while (i < MEM_SIZE)
	{
		ft_printf("%.2x ", arena->board[i]);
		i++;
		if (i % 64 == 0)
		{
			ft_putchar('\n');
			ft_printf("%#.4x : ", i);
		}
	}
	free_arena(arena);
	exit(0);
}

int		get_valide_adr(int adr)
{
	if (adr < 0)
		return (get_valide_adr(MEM_SIZE + adr));
	else if (adr >= MEM_SIZE)
		return (get_valide_adr(adr % MEM_SIZE));
	else
		return (adr);
}

void	write_tab(unsigned int to_write, t_arena *arena, int adr, int len)
{
	int c;

	if (len)
	{
		write_tab((to_write / 256), arena, adr, --len);
		c = to_write % 256;
		arena->board[get_valide_adr(adr + len)] = c;
	}
}
