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

// void 		ft_check_ocp(t_env)
void		ft_nb_param(t_cmd *cmd)
{
	if (cmd->op->opcode == 1 || cmd->op->opcode == 9 || cmd->op->opcode == 12 || 
		cmd->op->opcode == 15 || cmd->op->opcode == 16)
		cmd->nb_params = 1;
	else if (cmd->op->opcode == 2 || cmd->op->opcode == 3 ||
			 cmd->op->opcode == 13)
		cmd->nb_params = 2;
	else
		cmd->nb_params = 3;
}
void		ft_add_cmd(t_cmd **cmd, t_cmd *new_cmd)
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

void		ft_parse_param1(t_env *e, t_cmd *cmd)
{
	printf("enter ft_parse_param1\n");
	unsigned char tmp;
	int i;

	tmp = e->file[e->i];
	ft_check_ocp(e, tmp);
	ft_iter(e, "test 1", 1, cmd);
	i = 0;
	printf("op_code == %d\n",cmd->op->opcode);
	if ((tmp & 3) != 0)
		ft_error(e, "BAD little byte ocp");
	i = -1;
	while (++i < cmd->nb_params && i < 4)
	{
		// printf("nocomprede %d\n", i);
		if (((tmp >> (6 - (i * 2))) & 3) == 1)
			ft_get_reg(e, cmd);
		else if ((((tmp >> (6 - (i * 2))) & 3) == 2) && cmd->op->dir_size == 1)
			ft_get_dir2(e, cmd);
		else if (((tmp >> (6 - (i * 2))) & 3) == 2 && cmd->op->dir_size == 0)
			ft_get_dir4(e, cmd);
		else if (((tmp >> (6 - (i * 2))) & 3) == 3)
			ft_get_ind(e, cmd);
		else if (((tmp >> (6 - (i * 2))) & 3) == 0)
			ft_error(e, "BAD OCP");
		else
			ft_error(e, "\n\nWUT,?\n\n");
		printf("\ni == %d\n", i);
		// ++(e->i) >= e->len ? ft_error(e, "BAD PARAM NUMBER") : 0;
		// ft_iter(e, "test 2", 0, cmd);
	}
}

void		ft_parse_param2(t_env *e, t_cmd *cmd)
{
	printf("enter ft_parse_param2\n");
	if (cmd->op->opcode == 1)
		ft_get_dir4(e, cmd);
	else if (cmd->op->opcode == 9 || cmd->op->opcode == 12 ||
		cmd->op->opcode == 15)
		ft_get_dir2(e, cmd);
	else
		ft_error(e, "WTF dude");
}

t_cmd	*creat_cmd(t_env *e)
{
	t_cmd	*cmd;
	int 	op_code;

	cmd = NULL;
	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		ft_error(e, "ERROR MALLOC CMD");
	bzero(cmd, sizeof(*cmd));
	op_code = e->file[e->i];
	ft_iter(e, "no param", 1, cmd);
	printf("op_code == %d\n\n", op_code);
	if (!(op_code > 0 && op_code < 17))
		ft_error(e, "BAD OP_CODE1");
	cmd->op = &g_op_tab[op_code - 1];
	op_code = -1;
	ft_nb_param(cmd);
	cmd->next = NULL;
	// printf("has_ocp == %d\n\n", cmd->op->has_ocp);
	if (cmd->op->has_ocp)
		ft_parse_param1(e, cmd);
	else
		ft_parse_param2(e, cmd);
	return (cmd);
}
