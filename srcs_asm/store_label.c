/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:39:17 by kenguyen          #+#    #+#             */
/*   Updated: 2018/04/12 18:03:29 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_op	*find_op(t_op *op, char *str)
{
	int i;

	i = 0;
	while (op && op[i].opcode)
	{
		if (ft_strequ(str, op[i].short_name))
			return (&op[i]);
		++i;
	}
	return (NULL);
}

void	parse_instruct(t_champ *champ)
{
	int		len;
	char	*tmp;
	int		index;
	t_op	*op;

	index = 1;
	while (champ->file[champ->i])
	{
		while (ft_isblank(champ->file[champ->i]))
			++champ->i;
		if (champ->file[champ->i] == COMMENT_CHAR)
			store_hash(champ);
		else
		{
			len = ft_strspn(&champ->file[champ->i], LABEL_CHARS);
			tmp = ft_strsub(champ->file, champ->i, len);
			champ->i += len;
			if (champ->file[champ->i] == LABEL_CHAR)
			{
				if (find_label(champ->label, tmp))
					ft_error(champ, "ERROR LABEL EXIST");
				add_label(&champ->label, new_label(tmp, champ));
				champ->i++;
			}
			else if (ft_isspace(champ->file[champ->i])
				&& (op = find_op(g_op_tab, tmp)))
				push_cmd(&champ->cmd, new_cmd(op, champ, index++));
			else if (champ->file[champ->i])
				ft_error(champ, "OP UNEXIST");
			ft_strdel(&tmp);
		}
	}
}
