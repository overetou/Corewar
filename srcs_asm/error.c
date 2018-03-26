/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:26:07 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/26 17:30:20 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_error(t_champ *champ, char *message)
{
	int line;
	int i;

	line = 0;
	i = 0;
	if (champ)
	{
		line++;
		while (i < champ->i)
		{
			if (champ->file[i] == '\n')
				line++;
			i++;
		}
	}
	ft_printf("Syntax error at line %d: \"%s\"\n", line, message);
	exit (0);
}
