/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:17:59 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/29 17:24:05 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <libft.h>
# include <op.h>
# include <ncurses.h>

typedef struct			s_process
{
	char				*name;
	char				carry;
	int					index;
	int					waitting;
	struct s_process	*next;
}						t_process;

typedef struct	s_param
{
	char				code;
	int					value;
	struct s_param		*next;
}				t_param;

typedef struct			s_arena
{
	unsigned char		tab[MEM_SIZE];
	int					cycles;
	void				(*f[17])(t_param, struct s_arena, t_process);
	t_process			*process;
}						t_arena;

void		ft_live(t_param *param, t_arena *arena, t_process *process);
void		ft_ld(t_param *param);
void		ft_st(t_param *param);
void		ft_add(t_param *param);
void		ft_sub(t_param *param);
void		ft_and(t_param *param);
void		ft_or(t_param *param);
void		ft_xor(t_param *param);
void		ft_zjmp(t_param *param);
void		ft_ldi(t_param *param);
void		ft_sti(t_param *param);
void		ft_fork(t_param *param);
void		ft_lld(t_param *param);
void		ft_sti(t_param *param);
void		ft_fork(t_param *param);
void		ft_lld(t_param *param);
void		ft_lldi(t_param *param);
void		ft_lfork(t_param *param);
void		ft_aff(t_param *param);

#endif
