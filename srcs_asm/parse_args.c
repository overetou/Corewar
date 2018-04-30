/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:26:26 by kenguyen          #+#    #+#             */
/*   Updated: 2018/04/25 18:54:11 by ysingaye         ###   ########.fr       */
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

void	parse_label(t_champ *champ, int index, char *tmp)
{
	if (ft_strlen(tmp) < 1)
		ft_error(champ, "Label needs name");
	if (find_label(champ, champ->label, tmp))
	{
		free(tmp);
		ft_error(champ, "Label already exists");
	}
	add_label(&champ->label, new_label(tmp, champ, index));
	champ->i++;
}

void	parse_instruct(t_champ *champ, int *index)
{
	int		len;
	char	*tmp;
	t_op	*op;

	len = ft_strspn(&champ->file[champ->i], LABEL_CHARS);
	if (!(tmp = ft_strsub(champ->file, champ->i, len)))
		ft_error(champ, "Memory could not be allocated");
	champ->i += len;
	if (champ->file[champ->i] == LABEL_CHAR)
		parse_label(champ, *index, tmp);
	else if (ft_isspace(champ->file[champ->i])
		&& (op = find_op(g_op_tab, tmp)))
	{
		push_cmd(&champ->cmd, new_cmd(op, champ, (*index)++));
	}
	else if (champ->file[champ->i])
	{
		free(tmp);
		ft_error(champ, "Unvalide operation");
	}
	ft_strdel(&tmp);
}

void	parse_args(t_champ *champ)
{
	int		index;

	index = 1;
	while (champ->file[champ->i])
	{
		while (ft_isblank(champ->file[champ->i]))
			++champ->i;
		if (champ->file[champ->i] == COMMENT_CHAR ||
			champ->file[champ->i] == ';')
			store_hash(champ);
		else
			parse_instruct(champ, &index);
	}
}
