/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 02:18:00 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 20:53:48 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <stdio.h>

int			main(void)
{
/*
	int ret;
	unsigned char test = 0;
	int test1 = USHRT_MAX;
	printf("real printf = %hhO, %hhO", test, (unsigned char)test1);
	printf("\n");
	ret = ft_printf("\nfake printf = %hhO, %hhO\n", test, (unsigned char)test1);
//	printf("\nret = %d\n", ret);
*/
	char test[] = "123";
	printf("%s\n", ft_strrev(test));
	return (0);
}
