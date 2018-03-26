/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:11:29 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/26 17:33:21 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	valid_params(t_param *param, t_op *op, t_champ *champ)
{
	int		i;

	i = 0;
	while (param && i < op->param_numbers)
	{
		if (param->code == REG_CODE && !HAS_REG_PERM(op->perm[i]))
			ft_error(champ, "ERROR HAS_REG_PERM");
		else if (param->code == DIR_CODE && !HAS_DIR_PERM(op->perm[i]))
			ft_error(champ, "ERROR HAS_DIR_PERM");
		else if (param->code == IND_CODE && !HAS_IND_PERM(op->perm[i]))
			ft_error(champ, "ERROR HAS_IND_PERM");
		i++;
		param = param->next;
	}
	if (i != op->param_numbers)
		ft_error(champ, "ERROR NBR PARAM");
}

void	parse_param(t_cmd *cmd, t_champ *champ)
{
	int len;
	int len2;
	char *tmp;

	while (ft_isspace(champ->file[champ->i]))
		champ->i++;
	len = ft_charcspn(&champ->file[champ->i], SEPARATOR_CHAR);
	len2 = ft_strcspn(&champ->file[champ->i], "\n#");
	if (len2 < len)
		len = len2;
	tmp = ft_strsub(champ->file, champ->i, len);
	champ->i += len;
	push_param(&cmd->param, new_param(ft_strtrim(tmp), cmd, champ));
	ft_strdel(&tmp);
	if (champ->file[champ->i] == SEPARATOR_CHAR)
		champ->i++;
	while (ft_isspace(champ->file[champ->i]))
		champ->i++;
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
		ft_error(champ, "ERROR MALLOC CMD");
	cmd->op = op;
	cmd->index = index;
	cmd->next = NULL;
	cmd->next = NULL;
	cmd->param = NULL;
	while (champ->file[champ->i] && !ft_strchr("#\n", champ->file[champ->i]))
		parse_param(cmd, champ);
	valid_params(cmd->param, op, champ);
	if (champ->label && !champ->label->cmd)
		champ->label->cmd = cmd;
	return (cmd);
}
