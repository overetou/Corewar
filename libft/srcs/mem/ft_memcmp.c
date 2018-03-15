/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:15:11 by kenguyen          #+#    #+#             */
/*   Updated: 2017/11/14 15:33:22 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *src1;
	const unsigned char *src2;

	src1 = s1;
	src2 = s2;
	while (n--)
	{
		if (*src1 != *src2)
			return (*src1 - *src2);
		else
		{
			src1++;
			src2++;
		}
	}
	return (0);
}
