/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:26:07 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/10 18:12:39 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	free_env(t_champ *champ)
{
	if (champ->file)
		free(champ->file);
	if (champ->name)
		free(champ->name);
	if (champ->file)
		free(champ->comment);
}

void	ft_error(t_champ *champ, char *message)
{
	int line;
	int i;

	line = 0;
	i = 0;
	if (champ)
	{
		++line;
		while (++i < champ->i)
			if (champ->file[i] == '\n')
				++line;
	}
	ft_printf("Syntax error at line %d: \"%s\"\n", line, message);
//	free_env(champ);
	exit(0);
}
