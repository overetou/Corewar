/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:35:09 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/21 18:36:32 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strspn(const char *str1, const char *str2)
{
	int i;

	i = 0;
	while (str1[i] && ft_strchr(str2, str1[i]))
		i++;
	return (i);
}
