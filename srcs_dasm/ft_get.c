/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:18:48 by pkeita            #+#    #+#             */
/*   Updated: 2018/04/10 17:18:51 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dasm.h>

void				ft_check_ocp(t_env *e, t_cmd *cmd)
{
	int				i;

	i = 0;
	while (i < cmd->op->param_numbers && i < 4)
	{
		if (cmd->param[i].code == REG_CODE &&
			(cmd->op->perm[i] & T_REG) == 0)
			ft_error(e, "ERROR NO REG_PERM");
		else if (cmd->param[i].code == DIR_CODE &&
			(cmd->op->perm[i] & T_DIR) == 0)
			ft_error(e, "ERROR NO DIR_PERM");
		else if (cmd->param[i].code == IND_CODE &&
			(cmd->op->perm[i] & T_IND) == 0)
			ft_error(e, "ERROR NO IND_PERM");
		i++;
	}
}

void				ft_get_reg(t_env *e, t_cmd *cmd)
{
	unsigned char	tmp;

	cmd->param[cmd->index].code = REG_CODE;
	tmp = e->file[e->i];
	cmd->param[cmd->index].value = tmp;
	if (cmd->param[cmd->index].value < 1 ||
		cmd->param[cmd->index].value > REG_NUMBER)
		ft_error(e, "Bad reg number");
	++(cmd->index);
	ft_iter(e, "Don't fuck with me", 0, cmd);
}

void				ft_get_dir2(t_env *e, t_cmd *cmd)
{
	unsigned char	tmp;

	cmd->param[cmd->index].code = DIR_CODE;
	cmd->param[cmd->index].nbr_octet = 2;
	tmp = e->file[e->i];
	cmd->param[cmd->index].value += tmp << 8;
	ft_iter(e, "Don't fuck with me", 1, cmd);
	tmp = e->file[e->i];
	cmd->param[cmd->index++].value += tmp;
	ft_iter(e, "Don't fuck with me", 0, cmd);
}

void				ft_get_dir4(t_env *e, t_cmd *cmd)
{
	unsigned char	tmp;

	cmd->param[cmd->index].code = DIR_CODE;
	cmd->param[cmd->index].nbr_octet = 4;
	tmp = e->file[e->i];
	cmd->param[cmd->index].value = tmp << 24;
	ft_iter(e, "Don't fuck with me", 1, cmd);
	tmp = e->file[e->i];
	cmd->param[cmd->index].value += tmp << 16;
	ft_iter(e, "Don't fuck with me", 1, cmd);
	tmp = e->file[e->i];
	cmd->param[cmd->index].value += tmp << 8;
	ft_iter(e, "Don't fuck with me", 1, cmd);
	tmp = e->file[e->i];
	cmd->param[cmd->index++].value += tmp;
	ft_iter(e, "Don't fuck with me", 0, cmd);
}

void				ft_get_ind(t_env *e, t_cmd *cmd)
{
	unsigned char	tmp;

	cmd->param[cmd->index].code = IND_CODE;
	tmp = e->file[e->i];
	cmd->param[cmd->index].value += tmp << 8;
	ft_iter(e, "Don't fuck with me", 1, cmd);
	tmp = e->file[e->i];
	cmd->param[cmd->index++].value += tmp;
	ft_iter(e, "Don't fuck with me", 0, cmd);
}
