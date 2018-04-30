/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epurstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:50:35 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/02 09:02:19 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_epurstr(char *str)
{
	int		i;
	int		j;
	char	*dest;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(str) + 1;
	if (!(dest = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == ' '))
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != '\t' && str[i] != '\n' && str[i] != ' ')
			dest[j++] = str[i++];
		while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == ' '))
			i++;
		if (str[i])
			dest[j++] = ' ';
	}
	while (j < len)
		dest[j++] = '\0';
	return (dest);
}
