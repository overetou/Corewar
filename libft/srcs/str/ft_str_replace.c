/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 04:01:58 by pkeita            #+#    #+#             */
/*   Updated: 2018/04/28 04:02:01 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_replace(char *str, char replaced, char replace)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == replaced)
			str[i] = replace;
		++i;
	}
}
