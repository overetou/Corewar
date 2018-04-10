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
	int i;
	
	i = -1;
	e->name = ft_strndup(e->file + e->i, e->len - e->i);
	if (ft_strlen(e->name) > PROG_NAME_LENGTH && ft_strlen(e->name) < 1)
		ft_error(e, "NAME BAD SIZE");
	while (e->file[e->i] != 0 && e->i < e->len && ++i < PROG_NAME_LENGTH)
		e->i++;
	while (e->file[e->i] == 0 && e->i < e->len)
		e->i++;
	e->comment = ft_strndup(e->file + e->i, e->len - e->i);
	i = 0;
	if (ft_strlen(e->comment) > COMMENT_LENGTH && ft_strlen(e->name) < 1)
		ft_error(e, "NAME BAD SIZE");
	while (e->file[e->i] != 0 && e->i < e->len && i < COMMENT_LENGTH)
		e->i++;
	while (e->file[e->i] != 0 && e->i < e->len)
		e->i++;
	while (e->file[e->i] == 0 && e->i < e->len)
		e->i++;	
}


void		ft_parse_cmd(t_env *e)
{
	t_cmd		*cmd;

	while (e->i < e->len)
	{
		while (e->i < e->len && e->file[e->i] == 0)
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
