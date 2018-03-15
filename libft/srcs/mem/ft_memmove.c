/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:35:15 by kenguyen          #+#    #+#             */
/*   Updated: 2017/11/14 15:37:52 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (s < d)
	{
		s = s + len;
		d = d + len;
		while (len-- > 0)
			*(--d) = *(--s);
	}
	else
	{
		while (len-- > 0)
			*d++ = *s++;
	}
	return (dst);
}
