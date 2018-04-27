/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:42:17 by pkeita            #+#    #+#             */
/*   Updated: 2018/04/09 18:42:22 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dasm.h>

void				ft_nb_param(t_cmd *cmd)
{
	if (cmd->op->opcode == 1 || cmd->op->opcode == 9 ||
		cmd->op->opcode == 12 || cmd->op->opcode == 15 || cmd->op->opcode == 16)
		cmd->nb_params = 1;
	else if (cmd->op->opcode == 2 || cmd->op->opcode == 3 ||
			cmd->op->opcode == 13)
		cmd->nb_params = 2;
	else
		cmd->nb_params = 3;
}

void				ft_add_cmd(t_cmd **cmd, t_cmd *new_cmd)
{
	t_cmd			*tmp;

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

void				ft_parse_param1(t_env *e, t_cmd *cmd)
{
	unsigned char	ocp;
	int				i;

	ocp = e->file[e->i];
	ft_iter(e, "Command needs parameter", 1, cmd);
	if ((ocp & 3) != 0)
		ft_error(e, "ocp must have his 2 smallers bit at 0");
	i = -1;
	while (++i < cmd->nb_params && i < 4)
	{
		if (((ocp >> (6 - (i * 2))) & 3) == 1)
			ft_get_reg(e, cmd);
		else if ((((ocp >> (6 - (i * 2))) & 3) == 2) && cmd->op->dir_size == 1)
			ft_get_dir2(e, cmd);
		else if (((ocp >> (6 - (i * 2))) & 3) == 2 && cmd->op->dir_size == 0)
			ft_get_dir4(e, cmd);
		else if (((ocp >> (6 - (i * 2))) & 3) == 3)
			ft_get_ind(e, cmd);
		else if (((ocp >> (6 - (i * 2))) & 3) == 0)
			ft_error(e, "Bad ocp bro");
	}
	ft_check_ocp(e, cmd);
}

void				ft_parse_param2(t_env *e, t_cmd *cmd)
{
	if (cmd->op->opcode == 1)
		ft_get_dir4(e, cmd);
	else if (cmd->op->opcode == 9 || cmd->op->opcode == 12 ||
		cmd->op->opcode == 15)
		ft_get_dir2(e, cmd);
}

t_cmd				*creat_cmd(t_env *e)
{
	t_cmd			*cmd;
	int				op_code;

	cmd = NULL;
	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		ft_error(e, "Malloc failed");
	bzero(cmd, sizeof(*cmd));
	op_code = e->file[e->i];
	ft_iter(e, "Command needs parameter", 1, cmd);
	if (!(op_code > 0 && op_code < 17))
		ft_error(e, "BAD OP_CODE1");
	cmd->op = &g_op_tab[op_code - 1];
	op_code = -1;
	ft_nb_param(cmd);
	cmd->next = NULL;
	if (cmd->op->has_ocp)
		ft_parse_param1(e, cmd);
	else
		ft_parse_param2(e, cmd);
	return (cmd);
}
