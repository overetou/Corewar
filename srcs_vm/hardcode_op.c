/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:45:24 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/24 20:03:56 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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

int		*create_perms_array(int v1, int v2, int v3, t_op op)
{
	int *array;

	array = op.perm;
	array[0] = v1;
	array[1] = v2;
	array[2] = v3;
	array[3] = 0;
	return (array);
}

void	hardcode_op2(t_op *op)
{
	op[8] = set_op(DIRFOR, 1, 0, create_perms_array(T_REG | T_IND | T_DIR,
		T_REG | T_IND | T_DIR, T_REG, op[8]));
	op[9] = set_op(DIRTWO, 0, DIR_CODE, create_perms_array(T_DIR, 0, 0, op[9]));
	op[10] = set_op(DIRTWO, 1, 0, create_perms_array(T_REG | T_DIR | T_IND,
		T_DIR | T_REG, T_REG, op[10]));
	op[11] = set_op(DIRTWO, 1, 0, create_perms_array(T_REG,
		T_REG | T_DIR | T_IND, T_DIR | T_REG, op[11]));
	op[12] = set_op(DIRTWO, 0, DIR_CODE,
		create_perms_array(T_DIR, 0, 0, op[12]));
	op[13] = set_op(DIRFOR, 1, 0,
		create_perms_array(T_DIR | T_IND, T_REG, 0, op[13]));
	op[14] = set_op(DIRTWO, 1, 0, create_perms_array(T_REG | T_DIR | T_IND,
		T_DIR | T_REG, T_REG, op[14]));
	op[15] = set_op(DIRTWO, 0, DIR_CODE,
		create_perms_array(T_DIR, 0, 0, op[15]));
	op[16] = set_op(DIRFOR, 1, 0, create_perms_array(T_REG, 0, 0, op[16]));
}

void	hardcode_op(t_op *op)
{
	op[0] = set_op(DIRFOR, 0, 0, create_perms_array(0, 0, 0, op[0]));
	op[1] = set_op(DIRFOR, 0, DIRFOR, create_perms_array(T_DIR, 0, 0, op[1]));
	op[2] = set_op(DIRFOR, 1, 0,
		create_perms_array(T_DIR | T_IND, T_REG, 0, op[2]));
	op[3] = set_op(DIRFOR, 1, 0,
		create_perms_array(T_REG, T_IND | T_REG, 0, op[3]));
	op[4] = set_op(DIRFOR, 1, 0,
		create_perms_array(T_REG, T_REG, T_REG, op[4]));
	op[5] = set_op(DIRFOR, 1, 0,
		create_perms_array(T_REG, T_REG, T_REG, op[5]));
	op[6] = set_op(DIRFOR, 1, 0, create_perms_array(T_REG | T_DIR | T_IND,
		T_REG | T_IND | T_DIR, T_REG, op[6]));
	op[7] = set_op(DIRFOR, 1, 0, create_perms_array(T_REG | T_IND | T_DIR,
		T_REG | T_IND | T_DIR, T_REG, op[7]));
	hardcode_op2(op);
}
