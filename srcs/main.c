/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 02:18:00 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 09:52:58 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <stdio.h>

int			main(void)
{
	int ret;
	unsigned char test = 0;
	unsigned char test1 = USHRT_MAX;
	printf("real printf = %hhO, %hhO", test, test1);
	printf("\n");
	ret = ft_printf("fake printf = %hhO, %hhO", test, test1);
//	printf("\nret = %d\n", ret);
	return (0);
}
