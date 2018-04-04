/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:09:04 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/03 18:12:27 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	validate_reg_nbr(t_param *param)
{
	if (param->value < 1 || param->value > REG_NUMBER)
		exit(ft_printf("ERROR REG_NUMBER\n"));
}

int		get_adr_value(t_arena *arena, int index, int nbr_oct)
{
	int value;
	int i;

	value = 0;
	i = 0;
	while ((index + i) < MEM_SIZE && i < nbr_oct)
	{
		value << 8;
		value = value | arena->board[index + i];
		i++;
	}
}

int		get_param_value(t_param *param, t_process *process, t_arena *arena, int has_mod)
{
	int value;

	if (param->code == REG_CODE)
	{
		validate_reg_nbr(param);
		return (process->reg[param->value - 1]);
	}
	else if (arena && param->code == IND_CODE)
	{
		if (has_mod)
			value = get_adr_value(arena, process->index + (param->value % IDX_MOD), 4));
		else
			value = get_adr_value(arena, process->index + param->value, 4));
		return (value);
	}
	else
		return (param->value);
}
