/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:23:44 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/25 18:23:59 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	push_param(t_param **param, t_param *new_param)
{
	t_param *tmp;

	if (!*param)
		*param = new_param;
	else
	{
		tmp = *param;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_param;
	}
}
