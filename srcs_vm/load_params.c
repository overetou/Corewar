/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:53:59 by overetou          #+#    #+#             */
/*   Updated: 2018/03/30 19:54:01 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		extract_bin_code(int ocp, int ocp_margin, int ind_option)
{
	while (margin)
	{
		ocp = ocp >> 2;
		margin--;
	}
	if (ocp == 2)
	{
		if (ind_option == 4)
			ocp = ind_option;
	}
	return (ocp);
}

int		extract_param_value(int	code, unsigned char *board, int *index)
{
	int size;
	int	mask;

	if (code == 1)
		size = 1;
	else if (code == 4)
		size = 4;
	else
		size = 2;
	code = board[++(*index)];
	while (--size)
	{
		(*index)++;
		code = code << 8;
		mask = board[(*index)];
		code = code | mask;
	}
	return (code);
}

int		cut_ocp(int ocp, int code, int ocp_margin)
{
	while (ocp_margin)
	{
		code = code << 2;
		ocp_margin--;
	}
	return (ocp ^ code);
}

int	load_params(t_param *param, unsigned char *board, int index, t_op *op)
{
	int		ocp_margin;
	int		opcode;

	opcode = board[index];
	while (op->opcode != opcode)
		op = op->next;
	if (op->has_ocp)
	{
		ocp = board[++index];
		ocp_margin = 3;
		while (ocp)
		{
			param->code = extract_bin_code(ocp, ocp_margin, op->ind_option);
			param->value = extract_param_value(param->code, board, &index);
			ocp = cut_ocp(ocp, param->code, ocp_margin--);
			param = param->next;
		}
	}
	else
	{
		param->code = op->hardcode;
		param->value = extract_param_value(param->code, board, &index);
	}
	return (opcode);
}
