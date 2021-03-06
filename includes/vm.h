/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:17:59 by kenguyen          #+#    #+#             */
/*   Updated: 2018/04/24 20:47:03 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <libft.h>
# include <op.h>
# include <ncurses.h>
# include <fcntl.h>

# define DIRTWO 2
# define DIRFOR 4
# define NCURSE 1
# define AFF	2
# define DUMP	3

typedef struct			s_player
{
	char				*file_name;
	char				nbr;
	char				*name;
	char				*comment;
	int					last_live;
	int					file_size;
	struct s_player		*next;
}						t_player;

typedef struct			s_param
{
	char				code;
	int					value;
	struct s_param		*next;
}						t_param;

typedef struct			s_process
{
	int					nbr;
	int					nbr_param;
	int					opcode;
	int					reg[REG_NUMBER];
	char				carry;
	int					index;
	int					next_index;
	int					waitting;
	char				did_live;
	unsigned char		color;
	t_param				*param;
	struct s_process	*next;
}						t_process;

typedef struct			s_op
{
	int					ind_option;
	int					has_ocp;
	int					hardcode;
	int					nbr_param;
	int					perm[4];
}						t_op;

typedef struct			s_arena
{
	unsigned char		*board;
	char				debug;
	int					cycles;
	int					executed_cycles;
	int					winner;
	void				(*f[17])(t_param*, struct s_arena*, t_process*);
	t_process			*process;
	t_player			*players;
	int					nbr_live;
	t_op				op[17];
	int					aff;
	int					end_cycle;
	int					nbr_of_playr;
	int					nbr_process;
	int					process_cpt;
}						t_arena;

void					ft_void(t_param *prm, t_arena *arena, t_process *proc);
void					ft_live(t_param *prm, t_arena *arena, t_process *proc);
void					ft_ld(t_param *prm, t_arena *arena, t_process *proc);
void					ft_st(t_param *prm, t_arena *arena, t_process *proc);
void					ft_add(t_param *prm, t_arena *arena, t_process *proc);
void					ft_sub(t_param *prm, t_arena *arena, t_process *proc);
void					ft_and(t_param *prm, t_arena *arena, t_process *proc);
void					ft_or(t_param *prm, t_arena *arena, t_process *proc);
void					ft_xor(t_param *prm, t_arena *arena, t_process *proc);
void					ft_zjmp(t_param *prm, t_arena *arena, t_process *proc);
void					ft_ldi(t_param *prm, t_arena *arena, t_process *proc);
void					ft_sti(t_param *prm, t_arena *arena, t_process *proc);
void					ft_fork(t_param *prm, t_arena *arena, t_process *proc);
void					ft_lld(t_param *prm, t_arena *arena, t_process *proc);
void					ft_lldi(t_param *prm, t_arena *arena, t_process *proc);
void					ft_lfork(t_param *prm, t_arena *arena, t_process *proc);
void					ft_aff(t_param *prm, t_arena *arena, t_process *proc);

int						load_params(t_param *param, unsigned char *board,
							t_process *process, t_op *op);
void					execute_cycle(t_arena *arena);
t_arena					*new_arena(void);
t_process				*new_process(int player_nbr, int index, t_arena *arena);
t_process				*dup_process(t_process *old_process, t_arena *arena);
void					add_process(t_process **process, t_process *new_proc);
void					dump_tab(t_arena *arena);
void					ft_init_color(t_player *players, t_arena *arena);
void					refresh_arena(t_arena *arena, int index, int len,
							unsigned char color);
void					refresh_status2(int *x, int *y, t_player *player);

void					execute_vm(t_arena *arena);
int						get_param_value(t_param *param, t_process *process,
							t_arena *arena, int has_mod);
int						validate_reg_nbr(t_param *param);
int						get_adr_value(t_arena *arena, int index, int nbr_oct);
void					write_tab(unsigned int to_write, t_arena *arena,
							int adr, int len);
t_param					*create_three_params(void);
void					fill_players(t_arena *arena);
char					*get_winner(t_player *player, int winner);
void					execute_process(t_process *process, t_arena *arena);
int						get_valide_adr(int adr);
void					push_process(t_process **process, t_process *new_proc);
int						validate_all_reg_nbr(t_param *param);
void					ft_error(char *message, t_arena *arena);
void					ft_usage(char *path, t_arena *arena);
void					free_arena(t_arena *arena);
void					refresh_status(t_arena *arena, int ctd, int finish);
void					free_param(t_param *param);
void					set_reg_value(int reg, int value, t_process *process);
void					hardcode_op(t_op *op);
void					free_process(t_process *process);
void					free_player(t_player *players);
t_player				*add_player(t_player *player, char *file_name,
							char *player_number, t_arena *arena);
void					ft_strendcmp(const char *s1, const char *s2,
							t_arena *arena);
void					check_arg_create_players(int argc, char **argv,
							t_arena *arena);
void					do_processes_checks(t_arena *arena, int *no_nbr_live,
							int *ctd);
char					*get_comment(int fd);
int						get_file_size(int fd);
char					*get_name(int fd, t_arena *arena);

#endif
