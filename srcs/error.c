/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:26:07 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/21 15:03:29 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_error_bk(int nbr_line, char **line)
{
	ft_printf("Syntax error at line %d: \"%s\"\n", nbr_line, *line);
	ft_strdel(line);
	exit (0);
}

void	ft_error(int line, char *message)
{
	ft_printf("Syntax error at line %d: \"%s\"\n", line, message);
	exit (0);
}
