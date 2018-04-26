/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 01:17:26 by pkeita            #+#    #+#             */
/*   Updated: 2018/04/26 17:07:59 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "creator.h"

void		ft_error(char *message)
{
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void		ft_cmd(t_env *env)
{
	int		ret;
	t_op	op;

	while (env->champ_size + 100 < CHAMP_MAX_SIZE)
	{
		ret = random() % 16;
		op = g_op_tab[ret];
		op.has_ocp == 1 ? env->champ_size++ : 0;
		env->champ_size++;
		ft_dprintf(env->fd, "\t%s\t", op.short_name);
		ft_random(env, op, (random() % 3) + 1, 0);
		ft_dprintf(env->fd, "\n");
	}
}

void		ft_file(t_env *env)
{
	ft_dprintf(env->fd, ".name           \"%s\"\n.comment        \"%s\"\n\n",
		env->name, env->comment);
	ft_cmd(env);
	ft_printf("\x1b[32mSuccesfully created: |%s.s|\n\x1b[0m", env->name);
}

void		ft_creator(t_env *env)
{
	int		length;

	length = (random() % 42) + 5;
	ft_name_comment(env->name, length);
	length = (random() % 85) + 15;
	ft_name_comment(env->comment, length);
	ft_strcat(env->file_name, "generated_champion/");
	ft_strcat(env->file_name, env->name);
	ft_strcat(env->file_name, ".s");
	if (((env->fd = open(env->file_name, O_CREAT | O_TRUNC | O_RDWR,
				0644)) < 0))
		ft_error("Open failed");
	ft_file(env);
	if (close(env->fd) < 0)
		ft_error("Close failed");
}

int			main(int ac, char **av)
{
	t_env	env;
	int		nb_champ;

	nb_champ = 1;
	bzero(&env, sizeof(env));
	srandom(time(NULL));
	if (ac == 2)
	{
		av[1][0] != '-' ? ft_error("bad arg") : 0;
		if ((nb_champ = ft_atoi(av[1] + 1)) < 1)
			ft_error("What do you want my nigga ?\n");
	}
	else if (ac > 2)
		ft_error("Usage ./champ_creator [-x]\n");
	mkdir("generated_champion", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	while (nb_champ > 0)
	{
		ft_creator(&env);
		bzero(&env, sizeof(env));
		--nb_champ;
	}
	return (0);
}
