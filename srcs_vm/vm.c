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
	if (player)
	{
		lowest_number = player->nbr;
		while(player)
		{
			if (player->nbr < lowest_number)
				lowest_number = player_number;
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
		player->nb = find_lowest_player_number(player);
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
		else
		{
			if (!ft_strcmp(argv[i], "-n"))
			{
				if (argc <= i + 2)
					exit(0);
				player_number = mini_atoi(argc[++i]);
				i++;
			}
			ft_strendcmp(argv[i], ".cor");
			arena->players = add_player(arena->players, argv[i], &player_number);
		}
	}
}

int			main(int argc, char **argv)
{
	t_arena		*arena;
	t_param		*param;
	t_op		op[15];

	arena = new_arena();
	param = create_three_params();
	check_arg_create_players(argc, argv, arena);
	fill_players(arena);
	ft_printf("ok");
	return (0);
}
