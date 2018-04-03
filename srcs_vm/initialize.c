/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:32:48 by overetou          #+#    #+#             */
/*   Updated: 2018/04/03 14:32:51 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vm.h"

t_param	*create_three_params()
{
	int		x;
	t_param	*new;

	new = (t_param*)malloc(sizeof(t_param));
	new->next = (t_param*)malloc(sizeof(t_param));
	(new->next)->next = (t_param*)malloc(sizeof(t_param));
	((new->next)->next)->next = NULL;
	return (new);
}

void	initialize(t_arena **arena, t_param **param)
{
	ft_bzero(arena, sizeof(t_arena));
	param = create_three_params();
}