/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 03:11:27 by pkeita            #+#    #+#             */
/*   Updated: 2018/04/25 03:11:28 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "creator.h"

void		ft_ind(t_env *env, t_op op, int param_nb)
{
	int		neg;
	short	nb;

	neg = random() % 2;
	nb = random() % SHRT_MAX;
	ft_dprintf(env->fd, "%d", neg == 0 ? nb : -nb);
	param_nb < op.param_numbers - 1 ? write(env->fd, ", ", 2) : 0;
	env->champ_size += 2;
}

void		ft_dir(t_env *env, t_op op, int param_nb)
{
	char	neg;
	int		nbr;
	short	nb;

	neg = random() % 2;
	if (op.dir_size == 4)
	{
		env->champ_size += 4;
		nbr = random() % INT_MAX;
		ft_dprintf(env->fd, "%c%d", DIRECT_CHAR, neg == 0 ? nbr : -nbr);
		param_nb < op.param_numbers - 1 ? write(env->fd, ", ", 2) : 0;
		return ;
	}
	env->champ_size += 2;
	nb = random() % SHRT_MAX;
	ft_dprintf(env->fd, "%c%d", DIRECT_CHAR, neg == 0 ? nb : -nb);
	param_nb < op.param_numbers - 1 ? write(env->fd, ", ", 2) : 0;
}

void		ft_reg(t_env *env, t_op op, int param_nb)
{
	int		nb;

	nb = (random() % 16) + 1;
	ft_dprintf(env->fd, "r%d", nb);
	param_nb < op.param_numbers - 1 ? write(env->fd, ", ", 2) : 0;
	env->champ_size++;
}

void		ft_random(t_env *env, t_op op, int rand, int i)
{
	while (i < op.param_numbers)
	{
		if (op.perm[i] == 7)
		{
			rand == 1 ? ft_reg(env, op, i++) : 0;
			rand == 2 ? ft_dir(env, op, i++) : 0;
			rand == 3 ? ft_ind(env, op, i++) : 0;
		}
		else if (op.perm[i] == 6 || op.perm[i] == 5 || op.perm[i] == 3)
		{
			rand = (random() % 2) + 1;
			if (op.perm[i] == 6)
				rand == 1 ? ft_ind(env, op, i++) : ft_dir(env, op, i++);
			else if (op.perm[i] == 5)
				rand == 1 ? ft_reg(env, op, i++) : ft_ind(env, op, i++);
			else if (op.perm[i] == 3)
				rand == 1 ? ft_reg(env, op, i++) : ft_dir(env, op, i++);
		}
		else if (op.perm[i] == 4)
			ft_ind(env, op, i++);
		else if (op.perm[i] == 2)
			ft_dir(env, op, i++);
		else if (op.perm[i] == 1)
			ft_reg(env, op, i++);
	}
}

void		ft_name_comment(char str[], int length)
{
	int		max_cons;
	int		max_vow;

	max_vow = 0;
	max_cons = 0;
	while (length > -1)
	{
		if (random() % 2 && max_vow < 2)
		{
			max_cons = 0;
			str[length--] = VOWELS[random() % 6];
			max_vow++;
		}
		else if (max_cons < 2)
		{
			max_vow = 0;
			str[length--] = CONSONANTS[random() % 28];
			max_cons++;
		}
		else
		{
			max_cons = 0;
			max_vow = 0;
		}
	}
}
