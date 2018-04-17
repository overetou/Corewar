/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:53:59 by overetou          #+#    #+#             */
/*   Updated: 2018/04/11 18:42:56 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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
	int value;

	if (!*code)
		return (0);
	if (*code == 1)
		size = 1;
	else if (*code == DIRFOR)
		size = DIRFOR;
	else
		size = 2;
	value = board[++(*index) % MEM_SIZE];
	while (--size)
	{
		(*index)++;
		value = value << 8;
		value = value | board[(*index) % MEM_SIZE];
	}
	return (value);
}

int		cut_ocp(int ocp, int code, int margin)
{
	if (code == DIRFOR)
		code = DIRTWO;
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
	int		ocp;
	t_op	op;
	int		x;

	process->next_index = process->index;
	op = ope[(process->opcode)];
	x = 0;
	if (op.has_ocp)
	{
		ocp = board[++(process->next_index) % MEM_SIZE];
		ocp_margin = 3;
		while (ocp && ++x <= 3)
		{
			param->code = extract_bin_code(ocp, ocp_margin, op.ind_option);
			param->value = extract_param_value(&(param->code), board, &(process->next_index));
			ocp = cut_ocp(ocp, param->code, ocp_margin--);
			param = param->next;
		}
	}
	else if ((process->opcode))
	{
		x = 1;
		param->code = op.hardcode;
		param->value = extract_param_value(&(param->code), board, &(process->next_index));
	}
	(process->next_index)++;
	return (x);
}
