/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:59:30 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/25 19:02:51 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_label	*find_label(t_champ *champ, t_label *label, char *str)
{
	t_label *tmp;

	tmp = label;
	if (ft_strlen(str) < 1)
		return (NULL);
	while (tmp)
	{
		if (tmp->name == NULL)
		{
			if (!(tmp->name = ft_strnew(1)))
			{
				free(tmp->name);
				ft_error(champ, "Memory could not be allocated");
			}
		}
		if (!ft_strcmp(str, tmp->name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_label	*new_label(char *str, t_champ *champ, int index)
{
	t_label	*label;

	label = NULL;
	if (!(label = (t_label*)malloc(sizeof(t_label))))
		ft_error(champ, "Memory could not be allocated");
	label->name = NULL;
	if (!(label->name = ft_strdup(str)))
		ft_error(champ, "Memory could not be allocated");
	label->index = index;
	label->cmd = NULL;
	label->next = NULL;
	return (label);
}

void	add_label(t_label **label, t_label *new_label)
{
	new_label->next = *label;
	*label = new_label;
}

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
			if (param->label && !find_label(champ, champ->label, param->label))
				ft_error_label(champ, "Label is invalid", param->label);
			champ->file_size += param->nbr_octet;
			param = param->next;
		}
		if (cmd->op->has_ocp)
			champ->file_size++;
		champ->file_size++;
		cmd = cmd->next;
	}
}
