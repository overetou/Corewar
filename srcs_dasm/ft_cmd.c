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


void		ft_dir_size(t_env *e, t_cmd *cmd)
{
	if (cmd->op_code == 1 || cmd->op_code == 2 || cmd->op_code == 6 || 
		cmd->op_code == 7 || cmd->op_code == 8 || cmd->op_code == 13)
		cmd->dir_size = 4;
	else if (cmd->op_code == 9)
		cmd->dir_size = 1;
	else if (cmd->opcode == 10 || cmd->opcode == 11 || cmd->opcode == 12 || 
			cmd->opcode == 14 ||  cmd->opcode == 15)
			cmd_dir_size = 2;
	else if (cmd->opcode == 3 || cmd->opcode == 4 || cmd->opcode == 5 ||
			cmd->op_code = 16)
		cmd_dir_size = -1;
	else 
		ft_error(e, "BAD OP_CODE");
}

void		ft_parse_param(t_env *e, t_cmd *cmd)
{
	unsigned int tmp;
	int i;

	i = 0;
	ft_dir_size(e, cmd);
	if (tmp = ++e->i >= e->len)
		ft_error(e, "BAD OCP");
	while (i < 3)
	{
		if (tmp >> 6 - (i * 2) & 0Xff == 1)
			ft_get_reg(e, cmd);
		else if (tmp >> 6 - (i * 2) & 0Xff == 2)
			ft_get_dir(e, cmd);
		else if (tmp >> 6 - (i * 2) & 0Xff == 3)
			ft_get_ind(e, cmd);
		else if (tmp >> 6 - (i * 2) & 0Xff == 0)
			ft_error(e, "BAD OCP");
		i++;
		if (++e->i >= e->len)
			ft_error(e, "BAD OCP");
	}
	if (tmp >> 6 & 0xff != 0)
		ft_error(e, "BAD OCP");
	if (++e->i >= e->len)
			ft_error(e, "c'est meme pas un erreur");
}

t_cmd	*new_cmd(t_env *e, t_cmd *cmd)
{
	t_cmd	*cmd;

	cmd = NULL;
	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		ft_error(champ, "ERROR MALLOC CMD");
	cmd->op_code = e->file[e->i++];
	cmd->ocp = e->file[e->i++];
	ft_parse_param(cmd);
	cmd->next = NULL;
	return (cmd);
}