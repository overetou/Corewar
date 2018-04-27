/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:13:26 by kenguyen          #+#    #+#             */
/*   Updated: 2018/04/09 11:31:10 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DASM_H
# define DASM_H

# include <libft.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "op.h"

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

typedef struct		s_param
{
	char			code;
	int				value;
	int				nbr_octet;
	char			*label;
}					t_param;

typedef struct		s_cmd
{
	t_op			*op;
	unsigned int	ocp;
	int				nb_params;
	int				index;
	t_param			param[4];
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_env
{
	char			*file;
	char			*name;
	char			*comment;
	int				champ_size;
	t_cmd			*cmd;
	int				i;
	int				j;
	int				len;
}					t_env;

t_op				g_op_tab[17];

t_cmd				*creat_cmd(t_env *e);
void				ft_add_cmd(t_cmd **cmd, t_cmd *new_cmd);
void				ft_error(t_env *e, char *message);
void				store_file(t_env *e, char *file_name);
void				ft_dasm(t_env *e, char *argv);
void				ft_check_magic(t_env *e);
void				ft_parse(t_env *e);
void				ft_get_reg(t_env *e, t_cmd *cmd);
void				ft_get_dir2(t_env *e, t_cmd *cmd);
void				ft_get_dir4(t_env *e, t_cmd *cmd);
void				ft_get_ind(t_env *e, t_cmd *cmd);
void				ft_iter(t_env *e, char *message, int check, t_cmd *cmd);
void				ft_creat_fill_file(t_env *env, char *file, int l, int a);
void				ft_print_cmd(t_env *e);
void				ft_check_ocp(t_env *e, t_cmd *cmd);

#endif
