/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:11:29 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/25 18:58:07 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		assemble_ocp(t_cmd *cmd)
{
	t_param	*head;
	int		ocp;
	int		i;

	ocp = 0;
	i = 0;
	head = cmd->param;
	while (head)
	{
		ocp = ocp | head->code;
		ocp = ocp << 2;
		head = head->next;
		i++;
	}
	while (i < 3)
	{
		ocp = ocp << 2;
		i++;
	}
	return (ocp);
}

void	valid_params(t_param *param, t_op *op, t_champ *champ)
{
	int		i;
	t_param *tmp;

	i = 0;
	tmp = param;
	while (tmp && i < op->param_numbers)
	{
		if (tmp->code == REG_CODE && (op->perm[i] & T_REG) == 0)
			ft_error(champ, "This parameter can't be a register");
		else if (tmp->code == DIR_CODE && (op->perm[i] & T_DIR) == 0)
			ft_error(champ, "This parameter can't be a direct parameter");
		else if (tmp->code == IND_CODE && (op->perm[i] & T_IND) == 0)
			ft_error(champ, "This parameter can't be an indirect parameter");
		i++;
		tmp = tmp->next;
	}
	if (i != op->param_numbers || tmp)
		ft_error(champ, "The number of parameter is invalid");
}

void	parse_param(t_cmd *cmd, t_champ *champ)
{
	int		len;
	int		len2;
	char	*tmp;

	while (ft_isspace(champ->file[champ->i]))
		champ->i++;
	len = ft_charcspn(&champ->file[champ->i], SEPARATOR_CHAR);
	len2 = ft_strcspn(&champ->file[champ->i], "\n");
	if (len2 < len)
		len = len2;
	len2 = ft_charcspn(&champ->file[champ->i], COMMENT_CHAR);
	len2 = ft_strcspn(&champ->file[champ->i], champ->comment_char);
	if (len2 < len)
		len = len2;
	if (!(tmp = ft_strsub(champ->file, champ->i, len)))
		ft_error(champ, "Memory could not be allocated");
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

	cmd = NULL;
	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		ft_error(champ, "Memory could not be allocated");
	cmd->op = op;
	cmd->index = index;
	cmd->next = NULL;
	cmd->param = NULL;
	while (champ->file[champ->i] && !ft_strchr(";\n", champ->file[champ->i])
		&& COMMENT_CHAR != champ->file[champ->i])
		parse_param(cmd, champ);
	valid_params(cmd->param, op, champ);
	if (champ->label && !champ->label->cmd)
		champ->label->cmd = cmd;
	return (cmd);
}
