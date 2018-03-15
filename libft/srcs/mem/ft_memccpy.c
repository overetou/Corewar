/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:32:54 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 19:34:57 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	char *dst1;
	char *src1;

	dst1 = (char*)dst;
	src1 = (char*)src;
	while (len--)
	{
		*(dst1++) = *src1;
		if (*(src1++) == (char)c)
			return (dst1);
	}
	return (NULL);
}
