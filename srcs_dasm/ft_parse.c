/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:52:28 by pkeita            #+#    #+#             */
/*   Updated: 2018/04/09 16:52:30 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dasm.h>

void	ft_check_magic(t_env *e)
{
	int  magic = COREWAR_EXEC_MAGIC;
	unsigned char tmp;

	tmp = e->file[e->i++];
	if (!(tmp == magic >> 24))
		ft_error(e, "BAD COREWAR_EXEC_MAGIC");
	tmp = e->file[e->i++];
	if (!(tmp == (magic >> 16 & 0xff)))
		ft_error(e, "BAD COREWAR_EXEC_MAGIC");
	tmp = e->file[e->i++];
	if (!(tmp == (magic >> 8 & 0xff)))
		ft_error(e, "BAD COREWAR_EXEC_MAGIC");
	tmp = e->file[e->i++];
	if (!(tmp == (magic & 0xff)))
		ft_error(e, "BAD COREWAR_EXEC_MAGIC");
}

void		ft_parse_comment_name(t_env *e)
{
	e->name = ft_strdup(e->file + e->i);
	while (e->file[e->i] != 0)
		e->i++;
	while (e->file[e->i] == 0)
		e->i++;
	e->comment = ft_strdup(e->file + e->i);
	while (e->file[e->i] != 0)
		e->i++;
	while (e->file[e->i] == 0)
		e->i++;	
}


void		ft_parse_cmd(t_env *e)
{
	t_cmd		*cmd;

	while (e->i < e->len)
	{
		while (e->i < e->len && e->[e->i] == 0)
			e->i++;
		ft_push_cmd(e->cmd, new_cmd(cmd));
		ft_get_ocp(e);
		ft_parse_param(e);
	}	
}

void		ft_parse(t_env *e)
{
	ft_check_magic(e);
	ft_parse_comment_name(e);
	ft_parse_cmd(e);
}
