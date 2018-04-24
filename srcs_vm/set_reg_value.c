/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_reg_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:38:19 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/24 17:42:27 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	set_reg_value(int reg, int value, t_process *process)
{
	process->reg[reg] = value;
	process->carry = 0;
	if (!process->reg[reg])
		process->carry = 1;
}
