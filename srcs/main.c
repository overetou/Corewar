/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 02:18:00 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 05:59:25 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <stdio.h>

int			main(void)
{
	int ret;
	char *test = "tinfechier";
	ret = ft_printf("%.100s", test);
	printf("\nret = %d\n", ret);
	return (0);
}
