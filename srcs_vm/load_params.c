/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:53:59 by overetou          #+#    #+#             */
/*   Updated: 2018/04/05 20:26:01 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "stdio.h"

int		extract_bin_code(int ocp, int margin, int ind_option)
{
	while (margin)
	{
		ocp = ocp >> 2;
		margin--;
	}
	if (ocp == 2)
	{
		if (ind_option == DIRFOR)
			ocp = ind_option;
	}
	return (ocp);
}

int		extract_param_value(char *code, unsigned char *board, int *index)
{
	int size;
	int	mask;
	int value;

	if (*code == 1)
		size = 1;
	else if (*code == 4)
	{
		size = 4;
		*code = 2;
	}
	else
		size = 2;
	value = board[++(*index)];
	while (--size)
	{
		(*index)++;
		value = value << 8;
		mask = board[(*index)];
		value = value | mask;
	}
	return (value);
}

int		cut_ocp(int ocp, int code, int margin)
{
	while (margin)
	{
		code = code << 2;
		margin--;
	}
	return (ocp ^ code);
}

int		load_params(t_param *param, unsigned char *board, t_process *process, t_op *ope)
{
	int		ocp_margin;
	int		opcode;
	int		ocp;
	t_op	op;

	process->next_index = process->index;
	opcode = board[process->index];
	op = ope[opcode];
	if (op.has_ocp)
	{
		ocp = board[++(process->next_index)];
		ocp_margin = 3;
		while (ocp)
		{
			param->code = extract_bin_code(ocp, ocp_margin, op.ind_option);
			param->value = extract_param_value(&(param->code), board, &(process->next_index));
			ocp = cut_ocp(ocp, param->code, ocp_margin--);
			param = param->next;
		}
	}
	else if (opcode)
	{
		param->code = op.hardcode;
		param->value = extract_param_value(&(param->code), board, &(process->next_index));
	}
	(process->next_index)++;
	return (opcode);
}
