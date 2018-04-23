/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:56:40 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/16 19:11:04 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	ft_strendcmp(const char *s1, const char *s2)
{
	int	i;

	i = ft_strlen(s1) - ft_strlen(s2);
	if (ft_strcmp(s1 + i, s2))
		exit(ft_printf("ERROR STRENDCMP\n"));
}

int		check_availability_player_number(t_player *player, char player_number)
{
	while(player)
	{
		if (player->nbr == player_number)
			exit(ft_printf("ERROR check_availability_player_number\n"));
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
			player = player->next;
		}
	}
	return (lowest_number);
}

t_player	*add_player(t_player *player, char *file_name, char	*player_number)
{
	t_player	*new;

	new = (t_player*)malloc(sizeof(t_player));
	new->file_name = file_name;
	new->name = NULL;
	new->comment = NULL;
	new->last_live = 0;
	new->file_size = 0;
	new->next = player;
	if (*player_number < 0)
		new->nbr = find_lowest_player_number(player) - 1;
	else
	{
		new->nbr = check_availability_player_number(player, *player_number);
		*player_number = -1;
	}
	return (new);
}

void		check_arg_create_players(int argc, char **argv, t_arena *arena)
{
	int			i;
	char		player_number;

	i = 0;
	player_number = -1;
	if (argc < 2)
		exit(ft_printf("ERROR check_arg_create_players 1\n"));
	while (argv[++i])
	{
		if (!ft_strcmp(argv[i], "-v"))
			arena->aff = NCURSE;
		else if (!ft_strcmp(argv[i], "-a"))
			arena->aff = AFF;
		else if (!ft_strcmp(argv[i], "-dump"))
		{
			arena->aff = DUMP;
			if (!ft_str_is_numeric(argv[++i]) || (arena->end_cycle = ft_atoi(argv[i])) < 0)
				ft_error("No dump end cycle detected", arena);
		}
		else if (!ft_strcmp(argv[i], "-debug"))
			arena->debug = 1;
		else
		{
			if (!ft_strcmp(argv[i], "-n"))
			{
				if (argc <= i + 2)
					exit(ft_printf("ERROR check_arg_create_players 3\n"));
				if (!ft_str_is_numeric(argv[++i]) || (player_number = ft_atoi(argv[i])) <= 0)
					exit(ft_printf("ERROR check_arg_create_players 4\n"));
				i++;
			}
			ft_strendcmp(argv[i], ".cor");
			arena->players = add_player(arena->players, argv[i], &player_number);
			arena->number_of_players++;
		}
	}
}

char		*get_winner(t_player *player, int winner)
{
	while (player)
	{
		if (player->nbr == winner)
			return(player->name);
		player = player->next;
	}
	return (NULL);
}

int			main(int argc, char **argv)
{
	t_arena		*arena;

	arena = new_arena();
	check_arg_create_players(argc, argv, arena);
	fill_players(arena);
	execute_vm(arena);
	ft_printf("And the winner is... %s!\n", get_winner(arena->players, arena->winner));
	free_arena(arena);
	return (0);
}
