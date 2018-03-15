/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:38:19 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 20:50:08 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;

	if (!*little)
		return ((char*)big);
	i = -1;
	while (big[++i])
	{
		j = 0;
		while (little[j] == big[i + j])
			if (little[j++ + 1] == '\0')
				return (char*)(big + i);
	}
	return (NULL);
}
