/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:40:03 by kenguyen          #+#    #+#             */
/*   Updated: 2017/11/14 15:40:33 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *d;

	d = dst;
	while (len > 0 && *src)
	{
		*d++ = *src++;
		--len;
	}
	while (len > 0)
	{
		*d++ = '\0';
		--len;
	}
	return (dst);
}
