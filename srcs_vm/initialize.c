/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:32:48 by overetou          #+#    #+#             */
/*   Updated: 2018/04/23 16:55:48 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vm.h"

t_param	*create_three_params(void)
{
	t_param	*new;
	t_param *old;
	int		i;

	old = NULL;
	i = 0;
	while (i != 3)
	{
		new = (t_param*)malloc(sizeof(t_param));
		if (new == NULL)
		{	
			if (old)
				free_param(old);
			return (NULL);
		}
		new->next = old;
		old = new;
		i++;
	}
	return (new);
}

t_op	set_op(int ind_option, int has_ocp, int hardcode, int *perm)
{
	t_op	op;
	int		i;
	int		nbr_param;

	op.hardcode = hardcode;
	op.has_ocp = has_ocp;
	op.ind_option = ind_option;
	i = 0;
	nbr_param = 0;
	while (i < 4)
	{
		op.perm[i] = perm[i];
		if (perm[i])
			nbr_param++;
		i++;
	}
	op.nbr_param = nbr_param;
	return (op);
}

int 	*create_perms_array(int v1, int v2, int v3, t_op op)
{
	int *array;

	array = op.perm;
	array[0] = v1;
	array[1] = v2;
	array[2] = v3;
	array[3] = 0;
	return (array);
}

void	hardcode_op(t_op *op)
{
	op[0] = set_op(DIRFOR, 0, 0, create_perms_array(0, 0, 0, op[0]));
	op[1] = set_op(DIRFOR, 0, DIRFOR, create_perms_array(T_DIR, 0, 0, op[1]));
	op[2] = set_op(DIRFOR, 1, 0, create_perms_array(T_DIR | T_IND, T_REG, 0, op[2]));
	op[3] = set_op(DIRFOR, 1, 0, create_perms_array(T_REG, T_IND | T_REG, 0, op[3]));
	op[4] = set_op(DIRFOR, 1, 0, create_perms_array(T_REG, T_REG, T_REG, op[4]));
	op[5] = set_op(DIRFOR, 1, 0, create_perms_array(T_REG, T_REG, T_REG, op[5]));
	op[6] = set_op(DIRFOR, 1, 0, create_perms_array(T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG, op[6]));
	op[7] = set_op(DIRFOR, 1, 0, create_perms_array(T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG, op[7]));
	op[8] = set_op(DIRFOR, 1, 0, create_perms_array(T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG, op[8]));
	op[9] = set_op(DIRTWO, 0, DIR_CODE, create_perms_array(T_DIR, 0, 0, op[9]));
	op[10] = set_op(DIRTWO, 1, 0, create_perms_array(T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG, op[10]));
	op[11] = set_op(DIRTWO, 1, 0, create_perms_array(T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG, op[11]));
	op[12] = set_op(DIRTWO, 0, DIR_CODE, create_perms_array(T_DIR, 0, 0, op[12]));
	op[13] = set_op(DIRFOR, 1, 0, create_perms_array(T_DIR | T_IND, T_REG, 0, op[13]));
	op[14] = set_op(DIRTWO, 1, 0, create_perms_array(T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG, op[14]));
	op[15] = set_op(DIRTWO, 0, DIR_CODE, create_perms_array(T_DIR, 0, 0, op[15]));
	op[16] = set_op(DIRFOR, 1, 0, create_perms_array(T_REG, 0, 0, op[16]));
}

void hardcode_func(t_arena *arena)
{
	arena->f[0] = ft_void;
	arena->f[1] = ft_live;
	arena->f[2] = ft_ld;
	arena->f[3] = ft_st;
	arena->f[4] = ft_add;
	arena->f[5] = ft_sub;
	arena->f[6] = ft_and;
	arena->f[7] = ft_or;
	arena->f[8] = ft_xor;
	arena->f[9] = ft_zjmp;
	arena->f[10] = ft_ldi;
	arena->f[11] = ft_sti;
	arena->f[12] = ft_fork;
	arena->f[13] = ft_lld;
	arena->f[14] = ft_lldi;
	arena->f[15] = ft_lfork;
	arena->f[16] = ft_aff;
}

t_arena	*new_arena()
{
	t_arena	*arena;

	if (!(arena = (t_arena*)malloc(sizeof(t_arena))))
		exit(ft_printf("ERROR MALLOC ARENA\n"));
	if (!(arena->board = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE)))
		ft_error("Memory could not be allocated.", arena);
	bzero(arena->board, MEM_SIZE);
	arena->cycles = 0;
	arena->debug = 0;
	arena->executed_cycles = 0;
	arena->winner = 0;
	hardcode_op(arena->op);
	hardcode_func(arena);
	arena->aff = 0;
	arena->end_cycle = 0;
	arena->number_of_players = 0;
	arena->nbr_process = 0;
	arena->nbr_live = 0;
	arena->process_cpt = 0;
	arena->process = NULL;
	arena->players = NULL;
	return (arena);
}
