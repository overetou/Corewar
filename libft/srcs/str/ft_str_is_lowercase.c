/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:01:26 by kenguyen          #+#    #+#             */
/*   Updated: 2017/11/14 17:02:25 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_str_is_lowercase(char *str)
{
	int		i;
	char	cur;

	i = 0;
	while (str[i])
	{
		cur = str[i];
		if (!(cur >= 'a' && cur <= 'z'))
			return (0);
		i++;
	}
	return (1);
}
