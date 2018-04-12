/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:59:30 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/10 16:52:17 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	valid_labels(t_champ *champ)
{
	t_cmd	*cmd;
	t_param	*param;

	cmd = champ->cmd;
	while (cmd)
	{
		param = cmd->param;
		while (param)
		{
			if (param->label && !find_label(champ->label, param->label))
				ft_error(champ, "ERROR LABEL UNEXIST");
			champ->file_size += param->nbr_octet;
			param = param->next;
		}
		if (cmd->op->has_ocp)
			champ->file_size++;
		champ->file_size++;
		cmd = cmd->next;
	}
}

t_label	*find_label(t_label *label, char *str)
{
	while (label)
	{
		if (ft_strequ(str, label->name))
			return (label);
		label = label->next;
	}
	return (NULL);
}

t_label	*new_label(char *str, t_champ *champ)
{
	t_label	*label;

	if (!(label = (t_label*)malloc(sizeof(t_label))))
		ft_error(champ, "ERROR MALLOC LABEL");
	label->name = ft_strdup(str);
	label->cmd = NULL;
	label->next = NULL;
	return (label);
}

void	add_label(t_label **label, t_label *new_label)
{
	new_label->next = *label;
	*label = new_label;
}
