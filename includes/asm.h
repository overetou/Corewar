/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 02:22:30 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/21 16:44:58 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <libft.h>
# include <fcntl.h>
# include "op.h"

/*
 **				corewar
 */

typedef struct	s_op
{
	char					*short_name;
	int						param_numbers;
	int						perm[4];
	int						opcode;
	int						cycles_numbers;
	char 					*full_name;
	int						has_ocp;
	int						dir_size;
}				t_op;

typedef struct	s_param
{
	char				code;
	int					value;
	int					nbr_octet;
	struct s_param		*next;
}				t_param;

typedef struct	s_cmd
{
	t_op			*op;
	int				index;
	t_param			*param;
	struct s_cmd	*next;
}				t_cmd;

typedef struct  s_label
{
	char    *name;
	t_cmd   *cmd;
	struct	s_label   *next;
}				t_label;

typedef struct  s_champ
{
	int		i;
	char	*file;
	char	 *name;
	char	*comment;
	t_cmd	*cmd;
	t_label	*label;
}               t_champ;

t_op    g_op_tab[17];

void		parse(t_champ *champ);
void		ft_error(int line, char *message);

#endif
