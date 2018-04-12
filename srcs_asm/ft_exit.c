/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:26:07 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/12 19:16:25 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	free_champ(t_champ *champ)
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
	int column;
	int i;
	int end;

	line = 0;
	column = 0;
	i = 0;
	end = champ->i;
	if (champ)
	{
		++line;
		while (++i < champ->i)
			if (champ->file[i] == '\n')
				++line;
		while (champ->file[end] != '\n' && end > 0)
			--end;
		column = champ->i - end;
	}
//	ft_printf("%s\n", ft_strsub(champ->file, 0, champ->i));
	ft_printf("Syntax error at line ");
	ft_printf("%d, column %d: \"%s\"\n", line, column, message);
	exit(0);
}
