/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:47:41 by overetou          #+#    #+#             */
/*   Updated: 2018/03/20 17:54:33 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_champ *parse(int fd)
{
	char *line;

	while (get_next_line(fd, &line) > 0)
	{
		ft_printf("%s\n", line);
	}
	return (NULL);
}
