/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 01:19:16 by pkeita            #+#    #+#             */
/*   Updated: 2018/04/23 01:19:19 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATOR_H
# define CREATOR_H

# include <libft.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "op.h"
# define VOWELS	"aeiouy"
# define CONSONANTS "qw rt ps df ghj klz xcvb n m"

typedef struct		s_op
{
	char			*short_name;
	int				param_numbers;
	int				perm[4];
	int				opcode;
	int				cycles_numbers;
	char			*full_name;
	int				has_ocp;
	int				dir_size;
}					t_op;

t_op g_op_tab[17];

typedef struct		s_env
{
	char			file_name[1024];
	char			name[256];
	char			comment[4096];
	int				champ_size;
	int				fd;
}					t_env;

void				ft_random(t_env *env, t_op op, int rand, int i);
void				ft_name_comment(char str[], int length);
void				ft_error(char *message);

#endif
