/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:28:28 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/21 14:38:19 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strcspn(const char *str1, const char *str2)
{
	int i;

	i = 0;
	while (str1[i] && !ft_strchr(str2, str1[i]))
		i++;
	return (i);
}
