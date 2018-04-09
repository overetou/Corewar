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
# include <fcntl.h>
# include "op.h"


typedef struct 			s_param
{
	char *name;
	int	*value;
}						t_param;

typedef struct 			s_cmd
{
	int 				op_code;
	int					ocp;
	int					dir_size;
	t_param 			tab[3];
	struct s_cmd		*next;
}						t_cmd;

typedef struct			s_env
{
	char		*file;
	char		*name;
	char		*comment;
	t_cmd		*cmd;
	int 		i;
	int			len;
}						t_env;

void		ft_error(t_env *e, char *message);
void		store_file(t_env *e, char *file_name);
void		ft_dasm(t_env *e, char *argv);
void		ft_check_magic(t_env *e);
void		ft_get_name(char *str, t_env *e);
void		ft_parse(t_env *e);


#endif
