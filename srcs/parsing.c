/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:47:41 by overetou          #+#    #+#             */
/*   Updated: 2018/03/22 17:23:26 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		store_name(t_champ *champ)
{
	int tmp;

	champ->i += ft_strlen(NAME_CMD_STRING);
	while (ft_isspace(champ->file[champ->i]))
		champ->i++;
	if (champ->file[champ->i] != '"')
		ft_error(0, "bug name 1");
	if (!ft_strchr(&champ->file[++champ->i], '"'))
		ft_error(0, "bug name 2");
	tmp = ft_strcspn(&champ->file[champ->i], "\"");
	champ->name = ft_strsub(champ->file, champ->i, tmp);
	if (ft_strlen(champ->name) > PROG_NAME_LENGTH)
		ft_error(0, "bug on length prog");
	champ->i += tmp;
}

void		store_comment(t_champ *champ)
{
	int tmp;

	champ->i += ft_strlen(COMMENT_CMD_STRING);
	while (ft_isspace(champ->file[champ->i]))
		champ->i++;
	if (champ->file[champ->i] != '"')
		ft_error(0, "bug on comment 1");
	if (!ft_strchr(&champ->file[++champ->i], '"'))
		ft_error(0, "bug on comment 2");
	tmp = ft_strcspn(&champ->file[champ->i], "\"");
	champ->comment = ft_strsub(champ->file, champ->i, tmp);
	if (ft_strlen(champ->comment) > COMMENT_LENGTH)
		ft_error(0, "bug on length comment");
	champ->i += tmp;
}

void		store_hash(t_champ *champ)
{
	++champ->i;
	champ->i += ft_strcspn(&champ->file[champ->i], "\n");
}

void		set_name_comment(t_champ *champ)
{
	while (champ->file[champ->i] && (!champ->name || !champ->comment))
	{
		while (ft_isblank(champ->file[champ->i]))
			champ->i++;
		if (ft_strnequ(&champ->file[champ->i], NAME_CMD_STRING,
			ft_strlen(NAME_CMD_STRING)))
			store_name(champ);
		else if (ft_strnequ(&champ->file[champ->i], COMMENT_CMD_STRING,
			ft_strlen(COMMENT_CMD_STRING)))
			store_comment(champ);
		else if (champ->file[champ->i] == COMMENT_CHAR)
			store_hash(champ);
		else
			ft_error(0, "bug on parsing");
		champ->i++;
	}
}

void		parse(t_champ *champ)
{
	champ->name = NULL;
	champ->comment = NULL;
	champ->cmd = NULL;
	champ->label = NULL;
	set_name_comment(champ);
	ft_printf("name = %s\n", champ->name);
	ft_printf("comment = %s\n", champ->comment);
	parse_instruct(champ);
}
