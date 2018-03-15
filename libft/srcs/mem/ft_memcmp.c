/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:47:29 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 19:47:35 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *src1;
	unsigned char *src2;

	src1 = (unsigned char*)s1;
	src2 = (unsigned char*)s2;
	while (n--)
	{
		if (*src1 != *src2)
			return (*src1 - *src2);
		++src1;
		++src2;
	}
	return (0);
}
