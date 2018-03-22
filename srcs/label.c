/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:59:30 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/22 17:13:28 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


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

t_label	*new_label(char *str)
{
	t_label	*label;

	if (!(label = (t_label*)malloc(sizeof(t_label))))
		ft_error(0, "ERROR MALLOC LABEL");
	label->name = str;
	label->cmd = NULL;
	label->next = NULL;
	return (label);
}

void	add_label(t_label **label, t_label *new_label)
{
	new_label->next = *label;
	*label = new_label;
}
