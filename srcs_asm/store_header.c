/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:26:01 by kenguyen          #+#    #+#             */
/*   Updated: 2018/04/25 19:01:33 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void		store_name(t_champ *champ)
{
	int tmp;
	int len;

	champ->i += ft_strlen(NAME_CMD_STRING);
	while (ft_isspace(champ->file[champ->i]))
		champ->i++;
	if (champ->file[champ->i] != '"')
		ft_error(champ, "The name must be enclosed in double quotes");
	if (!ft_strchr(&champ->file[++champ->i], '"'))
		ft_error(champ, "The name must be enclosed in double quotes");
	tmp = ft_strcspn(&champ->file[champ->i], "\"");
	champ->name = ft_strsub(champ->file, champ->i, tmp);
	len = ft_strlen(champ->name);
	if (len > PROG_NAME_LENGTH || len == 0)
		ft_error(champ, "Name size is invalid");
	champ->i += tmp;
}

void		store_comment(t_champ *champ)
{
	int tmp;

	champ->i += ft_strlen(COMMENT_CMD_STRING);
	while (ft_isspace(champ->file[champ->i]))
		champ->i++;
	if (champ->file[champ->i] != '"')
		ft_error(champ, "The comment must be enclosed in double quotes");
	if (!ft_strchr(&champ->file[++champ->i], '"'))
		ft_error(champ, "The comment must be enclosed in double quotes");
	tmp = ft_strcspn(&champ->file[champ->i], "\"");
	champ->comment = ft_strsub(champ->file, champ->i, tmp);
	if (ft_strlen(champ->comment) > COMMENT_LENGTH)
		ft_error(champ, "The comment is too long");
	champ->i += tmp;
}

void		store_hash(t_champ *champ)
{
	++champ->i;
	champ->i += ft_strcspn(&champ->file[champ->i], "\n");
}

void		store_header(t_champ *champ)
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
		else if (champ->file[champ->i] == COMMENT_CHAR ||
			champ->file[champ->i] == ';')
			store_hash(champ);
		else
			ft_error(champ, "Missing name or comment");
		champ->i++;
	}
}
