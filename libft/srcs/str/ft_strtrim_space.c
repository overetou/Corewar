/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:00:09 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/22 16:01:07 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim_space(char const *s)
{
	unsigned int	i;
	size_t			len;
	char			*ret;

	i = 0;
	if (!s)
		return (0);
	while (ft_isspace(s[i]))
		i++;
	len = ft_strlen(s) - 1;
	while (len > i && ft_isspace(s[len]))
		len--;
	if (len < i)
		return (ret = ft_strdup(""));
	return (ret = ft_strsub(s, i, len - (size_t)i + 1));
}
