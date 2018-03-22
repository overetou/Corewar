/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:11:29 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/22 16:17:24 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	valid_params(t_param *param, t_op *op)
{
	int		i;
	int		mask;

	i = 0;
	while (param && i < op->param_numbers)
	{
		else if (param->code == REG_CODE && !HAS_REG_PERM(op->perm[i]))
			ft_error("ERROR HAS_REG_PERM", 0);
		else if (param->code == DIR_CODE && !HAS_DIR_PERM(op->perm[i]))
			ft_error("ERROR HAS_DIR_PERM", 0);
		else if (param->code == IND_CODE && !HAS_IND_PERM(op->perm[i]))
			ft_error("ERROR HAS_IND_PERM", 0);
		i++;
		param = param->next;
	}
	if (i != op->param_numbers)
		ft_error("ERROR NBR PARAM", 0);
}

void	parse_param(t_cmd *cmd, t_champ *champ)
{
	int len;
	char *tmp;
	t_param *param;

	while (ft_isspace(champ->file[champ->i]))
		champ->i++;
	len = ft_charcspn(&champ->file[champ->i], SEPARATOR_CHAR);
	tmp = ft_strsub(champ->file, champ->i, len);
	champ->i += len;
	param = NULL;
	push_param(&param, new_param(ft_strtrim(tmp), champ, cmd));
	ft_strdel(tmp);
	cmd->param = param;
}

void	push_cmd(t_cmd **cmd, t_cmd *new_cmd)
{
	t_cmd *tmp;

	if (!*cmd)
		*cmd = new_cmd;
	else
	{
		tmp = *cmd;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_cmd;
	}
}

t_cmd	*new_cmd(t_op *op, t_champ *champ, int index)
{
	t_cmd	*cmd;

	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		ft_error("ERROR MALLOC CMD", 0);
	cmd->op = op;
	cmd->index = index;
	cmd->next = NULL;
	while (champ->file[champ->i] && !ft_strchr(champ->file[champ->i], "#\n"))
		parse_param(cmd, champ);
	valid_params(cmd->param, op);
	if (champ->label && !champ->label->cmd)
		champ->label->cmd = cmd;
}
