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

void	ft_check_ocp(t_env *e, unsigned int tmp)
{
	tmp++;
	tmp--;
	e->i++;
	e->i--;
	return ;
}

void	ft_get_reg(t_env *e, t_cmd *cmd)
{
	unsigned char tmp;

	cmd->param[cmd->index].code = REG_CODE;
	tmp = e->file[e->i];
	cmd->param[cmd->index].value = tmp;
	if (cmd->param[cmd->index].value < 1 ||
		cmd->param[cmd->index].value > REG_NUMBER)
		ft_error(e, "Bad reg number");
	++(cmd->index);
	ft_iter(e, "test d 1", 0, cmd);
}

void	ft_get_dir2(t_env *e, t_cmd *cmd)
{
	unsigned char tmp;

	cmd->param[cmd->index].code = DIR_CODE;
	cmd->param[cmd->index].nbr_octet = 2;
	tmp = e->file[e->i];
	cmd->param[cmd->index].value += tmp << 8;
	ft_iter(e, "test d 1", 1, cmd);
	tmp = e->file[e->i];
	cmd->param[cmd->index++].value += tmp;
	ft_iter(e, "test d 2", 0, cmd);
}

void	ft_get_dir4(t_env *e, t_cmd *cmd)
{
	unsigned char tmp;

	cmd->param[cmd->index].code = DIR_CODE;
	cmd->param[cmd->index].nbr_octet = 4;
	tmp = e->file[e->i];
	cmd->param[cmd->index].value = tmp << 24;
	ft_iter(e, "test dir 1", 1, cmd);
	tmp = e->file[e->i];
	cmd->param[cmd->index].value += tmp << 16;
	ft_iter(e, "test dir 2", 1, cmd);
	tmp = e->file[e->i];
	cmd->param[cmd->index].value += tmp << 8;
	ft_iter(e, "test dir 3", 1, cmd);
	tmp = e->file[e->i];
	cmd->param[cmd->index++].value += tmp;
	ft_iter(e, "test dir 4", 0, cmd);
}

void	ft_get_ind(t_env *e, t_cmd *cmd)
{
	unsigned char tmp;

	cmd->param[cmd->index].code = IND_CODE;
	tmp = e->file[e->i];
	cmd->param[cmd->index].value += tmp << 8;
	ft_iter(e, "test ind 1", 1, cmd);
	tmp = e->file[e->i];
	cmd->param[cmd->index++].value += tmp;
	ft_iter(e, "test ind 2", 0, cmd);
}

