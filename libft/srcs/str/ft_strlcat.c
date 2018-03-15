/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:41:38 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 21:01:55 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;

	i = ft_strlen(dst);
	j = 0;
	while (src[j] && i + j < size - 1 && size > 0)
	{
		dst[i + j] = src[j];
		++j;
	}
	dst[i + j] = '\0';
	if (size < i + j)
		return (size + ft_strlen(src));
	return (i + ft_strlen(src));
}
