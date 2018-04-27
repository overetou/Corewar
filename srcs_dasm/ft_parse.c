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

void				ft_check_magic(t_env *e)
{
	int				magic;
	unsigned char	tmp;

	magic = COREWAR_EXEC_MAGIC;
	tmp = e->file[e->i++];
	if (!(tmp == magic >> 24) || e->i == e->len)
		ft_error(e, "Bad magic number");
	tmp = e->file[e->i++];
	if (!(tmp == (magic >> 16 & 0xff)) || e->i == e->len)
		ft_error(e, "Bad magic number");
	tmp = e->file[e->i++];
	if (!(tmp == (magic >> 8 & 0xff)) || e->i == e->len)
		ft_error(e, "Bad magic number");
	tmp = e->file[e->i++];
	if (!(tmp == (magic & 0xff)) || e->i == e->len)
		ft_error(e, "Bad magic number");
}

void				ft_get_champ_size(t_env *e)
{
	int				i;
	int				shift;
	unsigned char	tmp;

	i = -1;
	shift = 24;
	while (e->i < e->len && ++i < 4)
	{
		tmp = e->file[e->i++];
		e->champ_size += tmp << shift;
		shift -= 8;
		e->i >= e->len ? ft_error(e, "Not enough information") : 0;
	}
	if (e->champ_size == 0)
		ft_error(e, "size 0 rly ?");
}

void				ft_parse_comment_name_size(t_env *e)
{
	int				i;
	int				stop;

	i = -1;
	e->name = ft_strndup(e->file + e->i, e->len - e->i);
	stop = ft_strlen(e->name);
	if (stop > PROG_NAME_LENGTH && stop < 1)
		ft_error(e, "Bad name");
	stop = PROG_NAME_LENGTH + 4;
	while (e->i < e->len && ++i < stop)
		e->i++;
	ft_get_champ_size(e);
	e->comment = ft_strndup(e->file + e->i, e->len - e->i);
	stop = ft_strlen(e->comment);
	if (stop > COMMENT_LENGTH && stop < 1)
		ft_error(e, "Bad name");
	i = -1;
	stop = COMMENT_LENGTH + 4;
	while (e->i < e->len && ++i < stop)
		e->i++;
}

void				ft_parse(t_env *e)
{
	int				i;

	i = 0;
	ft_check_magic(e);
	ft_parse_comment_name_size(e);
	while (e->i < e->len)
		ft_add_cmd(&(e->cmd), creat_cmd(e));
}
