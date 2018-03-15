/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:36:19 by kenguyen          #+#    #+#             */
/*   Updated: 2018/02/14 01:32:03 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	if (!(s = (char*)malloc(size + 1)))
		return (NULL);
	i = -1;
	while (++i < size)
		s[i] = '\0';
	s[i] = '\0';
	return (s);
}
