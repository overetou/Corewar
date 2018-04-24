/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:55:18 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/24 20:06:44 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_aff(unsigned int to_write)
{
	int c;

	if (to_write)
	{
		print_aff((to_write / 256));
		c = to_write % 256;
		ft_printf("%C", c);
	}
	else
		ft_putstr("Aff: ");
}

void	ft_aff(t_param *param, t_arena *arena, t_process *process)
{
	unsigned int	value;

	if (process->waitting == -1)
		process->waitting += 2;
	else if (process->waitting < -1)
		process->waitting = 2;
	else if (arena->aff == AFF)
	{
		if (!validate_all_reg_nbr(param))
			return ;
		value = get_param_value(param, process, arena, 1);
		print_aff(value);
		ft_putchar('\n');
	}
}
