/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_create_players.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 20:22:53 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/24 20:46:44 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		dump_param(char **argv, int *i, t_arena *arena)
{
	arena->aff = DUMP;
	if (!ft_str_is_numeric(argv[++(*i)]) ||
		(arena->end_cycle = ft_atoi(argv[*i])) < 0)
		ft_error("No dump end cycle detected", arena);
}

void		player_param(char **argv, int *i, t_arena *arena, int argc)
{
	char		player_number;

	player_number = -1;
	if (!ft_strcmp(argv[*i], "-n"))
	{
		if (argc <= *i + 2)
			ft_usage(argv[0], arena);
		if (!ft_str_is_numeric(argv[++(*i)]) ||
			(player_number = ft_atoi(argv[*i])) <= 0)
			ft_error("Invalide player number", arena);
		(*i)++;
	}
	ft_strendcmp(argv[*i], ".cor", arena);
	arena->players = add_player(arena->players, argv[*i],
		&player_number, arena);
	arena->number_of_players++;
}

void		check_arg_create_players(int argc, char **argv, t_arena *arena)
{
	int			i;

	i = 0;
	if (argc < 2)
		ft_usage(argv[0], arena);
	while (argv[++i])
	{
		if (!ft_strcmp(argv[i], "-v"))
			arena->aff = NCURSE;
		else if (!ft_strcmp(argv[i], "-a"))
			arena->aff = AFF;
		else if (!ft_strcmp(argv[i], "-dump"))
			dump_param(argv, &i, arena);
		else if (!ft_strcmp(argv[i], "-debug"))
			arena->debug = 1;
		else
			player_param(argv, &i, arena, argc);
	}
}
