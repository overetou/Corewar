/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 20:20:40 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/24 20:22:15 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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

t_player	*add_player(t_player *player, char *file_name, char *player_number,
	t_arena *arena)
{
	t_player	*new;

	new = (t_player*)malloc(sizeof(t_player));
	if (new == NULL)
		ft_error("Could not allocate memory for a player.\n", arena);
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
