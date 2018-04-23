/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:26:07 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/23 14:45:12 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_usage(char *path)
{
	ft_printf("Usage: %s [-dump N -degug -v] [-n N] <champ.cor> <...>\n
		\t-dump N : Dumps memory after N cycles\n
		\t-debug : Print executed operations\n
		\t-v: Ncurses visual mode\n
		\t-n: Set champ number at N\n", path);
	exit (0);
}

void	ft_error(char *message)
{
	ft_printf("Error: %s\n", message);
	exit (0);
}
