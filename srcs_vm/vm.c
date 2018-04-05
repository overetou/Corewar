/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:56:40 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/05 16:39:03 by ysingaye         ###   ########.fr       */
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

int		check_availability_player_number(t_player *player, char player_number)
{
	while(player)
	{
		if (player->nbr == player_number)
			exit(0);
		player = player->next;
	}
	return (player_number);
}

int			find_lowest_player_number(t_player *player)
{
	char	lowest_number;

	lowest_number = 0;
	if (player)
	{
		lowest_number = player->nbr;
		while(player)
		{
			if (player->nbr < lowest_number)
				lowest_number = player->nbr;
		}
		player = player->next;
	}
	return (lowest_number);
}

t_player	*add_player(t_player *player, char *file_name, char	*player_number)
{
	t_player	*new;

	new = (t_player*)malloc(sizeof(t_player));
	new->file_name = file_name;
	if (*player_number < 0)
		player->nbr = find_lowest_player_number(player);
	else
	{
		player->nbr = check_availability_player_number(player, *player_number);
		*player_number = -1;
	}
	new->next = player;
	return (new);
}

void		check_arg_create_players(int argc, char **argv, t_arena *arena)
{
	int			i;
	char		player_number;

	i = 0;
	player_number = -1;
	if (argc < 2)
		exit(0);
	while (argv[++i])
	{
		if (!ft_strcmp(argv[i], "-v"))
			arena->aff = NCURSE;
		if (!ft_strcmp(argv[i], "-a"))
			arena->aff = AFF;
		else if (!ft_strcmp(argv[i], "-dump"))
		{
			arena->aff = DUMP;
			if (!ft_str_is_numeric(argv[++i]) || (arena->end_cycle = ft_atoi(argv[i])) < 0)
				exit(0);
		}
		else
		{
			if (!ft_strcmp(argv[i], "-n"))
			{
				if (argc <= i + 2)
					exit(0);
				if (!ft_str_is_numeric(argv[++i]) || (player_number = ft_atoi(argv[i])) <= 0)
					exit(0);
				i++;
			}
			ft_strendcmp(argv[i], ".cor");
			arena->players = add_player(arena->players, argv[i], &player_number);
			arena->number_of_players++;
		}
	}
}

int			main(int argc, char **argv)
{
	t_arena		*arena;
	t_param		*param;

	arena = new_arena();
	return (0);
	param = create_three_params();
	check_arg_create_players(argc, argv, arena);
	fill_players(arena);
	execute_vm(arena, param);
	ft_printf("ok");
	return (0);
}
