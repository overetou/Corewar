/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:11:29 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/12 19:26:10 by kenguyen         ###   ########.fr       */
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
		if (tmp->code == REG_CODE && !HAS_REG_PERM(op->perm[i]))
			ft_error(champ, "ERROR HAS_REG_PERM");
		else if (tmp->code == DIR_CODE && !HAS_DIR_PERM(op->perm[i]))
			ft_error(champ, "ERROR HAS_DIR_PERM");
		else if (tmp->code == IND_CODE && !HAS_IND_PERM(op->perm[i]))
			ft_error(champ, "ERROR HAS_IND_PERM");
		i++;
		tmp = tmp->next;
	}
	if (i != op->param_numbers || tmp)
		ft_error(champ, "ERROR NBR PARAM");
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
		ft_error(champ, "MALLOC FAIL");
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
// modif while ramplacer # pqr COMMENT_CHAR
t_cmd	*new_cmd(t_op *op, t_champ *champ, int index)
{
	t_cmd	*cmd;

	cmd = NULL;
	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		ft_error(champ, "ERROR MALLOC CMD");
	cmd->op = op;
	cmd->index = index;
	cmd->next = NULL;
	cmd->param = NULL;
	while (champ->file[champ->i] && !ft_strchr(";\n", champ->file[champ->i]) &&
		champ->file[champ->i] != COMMENT_CHAR)
		parse_param(cmd, champ);
	valid_params(cmd->param, op, champ);
	if (champ->label && !champ->label->cmd)
		champ->label->cmd = cmd;
	return (cmd);
}
