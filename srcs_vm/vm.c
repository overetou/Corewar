/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:56:40 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/29 20:41:15 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	ft_strendcmp(const char *s1, const char *s2)
{
	int	i;

	i = ft_strlen(s1) - ft_strlen(s2);
	if (ft_strcmp(s1 + i, s2))
		exit(0);
}

void	check_param()

int			main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc < 2)
		exit(0);
	while (argv[++i])
	{
		if (!ft_strcmp(argv[i], "-n"))
			printf("vm");
		else
		{
			ft_strendcmp(argv[i], ".cor");
			add_player(argv[i]);
		}
	}
	initialize()
	ft_printf("ok");
	return (0);
}
