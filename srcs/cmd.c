/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:11:29 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/22 17:13:07 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	valid_params(t_param *param, t_op *op)
{
	int		i;

	i = 0;
	while (param && i < op->param_numbers)
	{
		if (param->code == REG_CODE && !HAS_REG_PERM(op->perm[i]))
			ft_error(0, "ERROR HAS_REG_PERM");
		else if (param->code == DIR_CODE && !HAS_DIR_PERM(op->perm[i]))
			ft_error(0, "ERROR HAS_DIR_PERM");
		else if (param->code == IND_CODE && !HAS_IND_PERM(op->perm[i]))
			ft_error(0, "ERROR HAS_IND_PERM");
		i++;
		param = param->next;
	}
	if (i != op->param_numbers)
		ft_error(0, "ERROR NBR PARAM");
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
	ft_strdel(&tmp);
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
		ft_error(0, "ERROR MALLOC CMD");
	cmd->op = op;
	cmd->index = index;
	cmd->next = NULL;
	while (champ->file[champ->i] && !ft_strchr("#\n", champ->file[champ->i]))
		parse_param(cmd, champ);
	valid_params(cmd->param, op);
	if (champ->label && !champ->label->cmd)
		champ->label->cmd = cmd;
	return (cmd);
}
