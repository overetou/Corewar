/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:53:59 by overetou          #+#    #+#             */
/*   Updated: 2018/04/24 21:02:18 by ysingaye         ###   ########.fr       */
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
		size = 4;
	else
		size = 2;
	value = board[get_valide_adr(++(*index))];
	while (--size)
	{
		(*index)++;
		value = value << 8;
		value = value | board[get_valide_adr((*index))];
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

int		parse_ocp(t_param *param, unsigned char *board, t_process *process,
	t_op op)
{
	int		ocp_margin;
	int		ocp;
	int		x;

	x = 0;
	ocp = board[get_valide_adr(++(process->next_index))];
	ocp_margin = 3;
	while (ocp && ++x <= op.nbr_param)
	{
		param->code = extract_bin_code(ocp, ocp_margin, op.ind_option);
		param->value = extract_param_value(&(param->code), board,
			&(process->next_index));
		ocp = cut_ocp(ocp, param->code, ocp_margin--);
		param = param->next;
	}
	if (ocp)
		x--;
	while (param)
	{
		param->code = 0;
		param->value = 0;
		param = param->next;
	}
	return (x);
}

int		load_params(t_param *param, unsigned char *board, t_process *process,
	t_op *ope)
{
	t_op	op;
	int		x;

	process->next_index = process->index;
	op = ope[(process->opcode)];
	x = 0;
	if (op.has_ocp)
		x = parse_ocp(param, board, process, op);
	else if ((process->opcode))
	{
		x = 1;
		param->code = op.hardcode;
		param->value = extract_param_value(&(param->code), board,
			&(process->next_index));
		param = param->next;
		while (param)
		{
			param->code = 0;
			param->value = 0;
			param = param->next;
		}
	}
	(process->next_index)++;
	return (x);
}
