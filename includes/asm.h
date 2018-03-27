/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 02:22:30 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/27 14:40:56 by ysingaye         ###   ########.fr       */
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

 # define HAS_REG_PERM(x) ((x | T_DIR | T_IND) == (T_REG | T_DIR | T_IND))
 # define HAS_DIR_PERM(x) ((T_REG | x | T_IND) == (T_REG | T_DIR | T_IND))
 # define HAS_IND_PERM(x) ((T_REG | T_DIR | x) == (T_REG | T_DIR | T_IND))

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
	char				*label;
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
	char	*name;
	char	*comment;
	t_cmd	*cmd;
	t_label	*label;
}               t_champ;

t_op    g_op_tab[17];

void		parse(t_champ *champ);
void		ft_error(t_champ *champ, char *message);
void		store_hash(t_champ *champ);
t_cmd		*new_cmd(t_op *op, t_champ *champ, int index);
void		push_cmd(t_cmd **cmd, t_cmd *new_cmd);
void		add_label(t_label **label, t_label *new_label);
t_label		*new_label(char *str, t_champ *champ);
t_label		*find_label(t_label *label, char *str);
void		push_param(t_param **param, t_param *new_param);
t_param		*new_param(char *str, t_cmd *cmd, t_champ *champ);
void		parse_instruct(t_champ *champ);

void		write_bin(unsigned int to_write, int fd, int len);
void		print_label(t_cmd *current, t_param *p, t_label *lab, int fd);
int			create_cor_file(char *file_name);
int			assemble_ocp(t_cmd *cmd);
void		manage_file_creation(t_champ *champ, char *filename);
void		valid_labels(t_champ *champ);

#endif
