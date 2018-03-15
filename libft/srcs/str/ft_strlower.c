/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:36:02 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 20:56:53 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strlower(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
}
