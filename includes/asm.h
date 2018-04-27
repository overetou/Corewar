/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 02:22:30 by kenguyen          #+#    #+#             */
/*   Updated: 2018/04/12 19:42:38 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <libft.h>
# include <fcntl.h>
# include <op.h>

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
	struct s_param	*next;
}					t_param;

typedef struct		s_cmd
{
	t_op			*op;
	int				index;
	t_param			*param;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_label
{
	char			*name;
	int				index;
	t_cmd			*cmd;
	struct s_label	*next;
}					t_label;

typedef struct		s_champ
{
	int				i;
	int				file_size;
	char			*file;
	int				file_len;
	int				fd;
	char			*name;
	char			*comment;
	char			comment_char[3];
	t_cmd			*cmd;
	t_label			*label;
}					t_champ;

t_op				g_op_tab[17];

void				ft_asm(t_champ *champ);
void				store_header(t_champ *champ);
void				parse_args(t_champ *champ);
void				store_hash(t_champ *champ);
t_cmd				*new_cmd(t_op *op, t_champ *champ, int index);
void				push_cmd(t_cmd **cmd, t_cmd *new_cmd);
void				add_label(t_label **label, t_label *new_label);
t_label				*new_label(char *str, t_champ *champ, int index);
t_label				*find_label(t_champ *champ, t_label *label, char *str);
void				push_param(t_param **param, t_param *new_param);
t_param				*new_param(char *str, t_cmd *cmd, t_champ *champ);
void				valid_labels(t_champ *champ);

void				file_creation(t_champ *champ, char *filename);
void				write_bin(unsigned int to_write, int fd, int len);
void				print_label(t_cmd *current, t_param *p,
								t_label *lab, t_champ *champ);
int					create_cor_file(t_champ *champ, char *file_name);
int					assemble_ocp(t_cmd *cmd);

void				free_champ(t_champ *champ);
void				ft_error(t_champ *champ, char *message);
void				ft_error_label(t_champ *champ, char *m, char *label);

#endif
