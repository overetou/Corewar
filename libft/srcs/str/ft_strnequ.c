/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:39:41 by kenguyen          #+#    #+#             */
/*   Updated: 2017/11/14 15:34:51 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (s1 == NULL && s2 != NULL)
		return (0);
	if (s2 == NULL && s1 != NULL)
		return (0);
	if (s1 == NULL && s2 == NULL)
		return (1);
	while (s1[i] && s2[i] && n > 0)
	{
		if (s1[i] != s2[i])
			return (0);
		if (n == 1)
			return (1);
		i++;
		n--;
	}
	if (s1[i] == s2[i])
		return (1);
	return (0);
}
