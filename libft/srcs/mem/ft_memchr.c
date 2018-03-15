/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:25:46 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 19:28:57 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ctmp;

	str = (unsigned char *)s;
	ctmp = (unsigned char)c;
	while (n--)
	{
		if (*str == ctmp)
			return (str);
		++str;
	}
	return (NULL);
}
