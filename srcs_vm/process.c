/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:23:09 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/13 16:36:05 by ysingaye         ###   ########.fr       */
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
	process->opcode = 0;
	process->carry = old_process->carry;
	process->index = old_process->index;
	process->next_index = old_process->index;
	process->waitting = old_process->waitting;
	process->did_live = old_process->did_live;
	process->color = old_process->color;
	process->param = create_three_params();
	process->next = NULL;
	return (process);
}

t_process	*new_process(int player_nbr, int index)
{
	t_process	*process;

	if (!(process = (t_process*)malloc(sizeof(t_process))))
		exit(ft_printf("ERROR MALLOC PROCESS\n"));
	process->opcode = 0;
	process->reg[0] = player_nbr;
	process->carry = 0;
	process->index = index;
	process->next_index = index;
	process->waitting = 0;
	process->did_live = 0;
	process->color = player_nbr;
	process->param = create_three_params();
	process->next = NULL;
	return (process);
}
