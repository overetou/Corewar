/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:09:04 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/30 15:45:29 by ysingaye         ###   ########.fr       */
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
		value = value | arena->tab[index + i];
		i++;
	}
}

int		get_param_value(t_param *param, t_process *process)
{
	if (param->code != REG_CODE)
		return (param->value);
	else
	{
		validate_reg_nbr(param);
		return (process->reg[param->value - 1]);
	}
}