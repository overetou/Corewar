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

void	ft_get_reg(t_env *e, t_cmd *cmd)
{
	// printf("enter ft_get_reg\n");
	cmd->param[cmd->index].code = REG_CODE;
	cmd->param[cmd->index].value = e->file[e->i];
	if (cmd->param[cmd->index].value < 1 ||
		cmd->param[cmd->index].value > REG_NUMBER)
		ft_error(e, "Bad reg number");
	++e->i >= e->len ? ft_error(e, "C'est pas forcement une erreur reg") : 0;
}

void	ft_get_dir2(t_env *e, t_cmd *cmd)
{
	unsigned char tmp;
	 // printf("enter ft_get_dir2\n");

	cmd->param[cmd->index].code = DIR_CODE;
	tmp = e->file[e->i++];
	cmd->param[cmd->index].value += tmp << 8;
	e->i >= e->len ? ft_error(e, "dir 4, 2") : 0;
	tmp = e->file[e->i++];
	cmd->param[cmd->index].value += tmp;
	printf("check value avec d = %d\ncheck value avec d = %u ",
		cmd->param[cmd->index].value, cmd->param[cmd->index].value);
	e->i++ >= e->len ? ft_error(e, "C'est pas forcement une erreur dir4") : 0;
}

void	ft_get_dir4(t_env *e, t_cmd *cmd)
{
	unsigned char tmp;
	// printf("enter ft_get_dir4\n");

	cmd->param[cmd->index].code = DIR_CODE;
	tmp = e->file[e->i++];
	cmd->param[cmd->index].value = tmp << 24;
	e->i >= e->len ? ft_error(e, "dir4, 1") : 0;
	tmp = e->file[e->i++];
	cmd->param[cmd->index].value += tmp << 16;
	e->i >= e->len ? ft_error(e, "dir 4, 2") : 0;
	tmp = e->file[e->i++];
	cmd->param[cmd->index].value += tmp << 8;
	e->i >= e->len ? ft_error(e, "dir 4, 2") : 0;
	tmp = e->file[e->i++];
	cmd->param[cmd->index].value += tmp;
	printf("check value avec d = %d\ncheck value avec u = %u\n",
		cmd->param[cmd->index].value, cmd->param[cmd->index].value);
	e->i++ >= e->len ? ft_error(e, "C'est pas forcement une erreur dir4") : 0;
}

void	ft_get_ind(t_env *e, t_cmd *cmd)
{
	unsigned char tmp;
	// printf("enter ft_get_ind\n");

	cmd->param[cmd->index].code = IND_CODE;
	tmp = e->file[e->i++];
	cmd->param[cmd->index].value += tmp << 8;
	e->i >= e->len ? ft_error(e, "dir 4, 2") : 0;
	tmp = e->file[e->i++];
	cmd->param[cmd->index].value += tmp;
	printf("check value avec d = %d\ncheck value avec d = %u ",
		cmd->param[cmd->index].value, cmd->param[cmd->index].value);
	e->i++ >= e->len ? ft_error(e, "C'est pas forcement une erreur ind") : 0;
	// printf("check value avec d = %d\ncheck value avec d = %u ",
		// cmd->param[cmd->index].value, cmd->param[cmd->index].value);	
}

