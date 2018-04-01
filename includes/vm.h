/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:17:59 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/29 21:34:21 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <libft.h>
# include <op.h>
# include <ncurses.h>

typedef struct			s_player
{
	int					nbr;
	char				*name;
	char				*comment;
	int					nbr_live;
	int					last_live;
	struct s_player		*next;
}						t_player;

typedef struct			s_process
{
	int					reg[REG_NUMBER];
	char				carry;
	int					index;
	int					waitting;
	int					player_nbr;
	struct s_process	*next;
}						t_process;

typedef struct			s_op
{
	int					opcode;
	int					ind_option;
	struct s_op			*next;
}						t_op;

typedef struct			s_param
{
	char				code;
	int					value;
	struct s_param		*next;
}						t_param;

typedef struct			s_arena
{
	unsigned char		board[MEM_SIZE];
	int					cycles;
	int					winner;
	void				(*f[17])(t_param, struct s_arena, t_process);
	t_process			*process;
	t_player			*players;
	t_op				*op;
}						t_arena;

void		ft_live(t_param *param, t_arena *arena, t_process *process);
void		ft_ld(t_param *param, t_arena *arena, t_process *process);
void		ft_st(t_param *param, t_arena *arena, t_process *process);
void		ft_add(t_param *param, t_arena *arena, t_process *process);
void		ft_sub(t_param *param, t_arena *arena, t_process *process);
void		ft_and(t_param *param, t_arena *arena, t_process *process);
void		ft_or(t_param *param, t_arena *arena, t_process *process);
void		ft_xor(t_param *param, t_arena *arena, t_process *process);
void		ft_zjmp(t_param *param, t_arena *arena, t_process *process);
void		ft_ldi(t_param *param, t_arena *arena, t_process *process);
void		ft_sti(t_param *param, t_arena *arena, t_process *process);
void		ft_fork(t_param *param, t_arena *arena, t_process *process);
void		ft_lld(t_param *param, t_arena *arena, t_process *process);
void		ft_sti(t_param *param, t_arena *arena, t_process *process);
void		ft_fork(t_param *param, t_arena *arena, t_process *process);
void		ft_lld(t_param *param, t_arena *arena, t_process *process);
void		ft_lldi(t_param *param, t_arena *arena, t_process *process);
void		ft_lfork(t_param *param, t_arena *arena, t_process *process);
void		ft_aff(t_param *param, t_arena *arena, t_process *process);
void		load_params(t_param *param, unsigned char *board, int index, t_op *op);

#endif
