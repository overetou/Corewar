/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:23:09 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/10 15:56:26 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		add_process(t_process **process, t_process *new_process)
{
	t_process	*tmp;

	if (new_process)
	{
		tmp = *process;
		*process = new_process;
		new_process->next = tmp;
	}
}

t_process	*dup_process(t_process *old_process)
{
	t_process	*process;
	int			i;

	if (!(process = (t_process*)malloc(sizeof(t_process))))
		exit(ft_printf("ERROR MALLOC PROCESS\n"));
	i = 0;
	while (i < REG_NUMBER)
	{
		process->reg[i] = old_process->reg[i];
		i++;
	}
	process->carry = old_process->carry;
	process->index = old_process->index;
	process->waitting = old_process->waitting;
	process->next = NULL;
	return (process);
}

t_process	*new_process(int player_nbr, int index)
{
	t_process	*process;

	if (!(process = (t_process*)malloc(sizeof(t_process))))
		exit(ft_printf("ERROR MALLOC PROCESS\n"));
	process->reg[0] = player_nbr;
	process->carry = 0;
	process->index = index;
	process->next_index = index;
	process->waitting = 0;
	process->color = 0;
	process->next = NULL;
	return (process);
}
