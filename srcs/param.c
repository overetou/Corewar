/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:51:26 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/22 17:15:11 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	push_param(t_param **param, t_param *new_param)
{
	t_param *tmp;

	if (!*param)
		*param = new_param;
	else
	{
		tmp = *param;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_param;
	}
}

void	set_int_param(char *str, t_param *param, int code)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i])
		ft_error(0, "SYNTAX ERROR");
	param->value = ft_atoi(str);
	param->code = code;
	param->label = NULL;
}

void	set_label_param(char *str, t_param *param, t_champ *champ, int code)
{
	int i;

	i = ft_strspn(str, LABEL_CHARS);
	if (str[i])
		ft_error(0, "SYNTAX ERROR");
	if (!find_label(champ->label, str))
		ft_error(0, "LABEL UNKNOW");
	param->value = 0;
	param->code = code;
	param->label = str;
}

void	set_direct_param(char *str, t_param *param, t_champ *champ, t_cmd *cmd)
{
	if (!cmd->op->dir_size)
		param->nbr_octet = 4;
	if (str[0] == LABEL_CHAR)
		set_label_param(&str[1], param, champ, DIR_CODE);
	else
		set_int_param(str, param, DIR_CODE);
}

void	set_registre_param(char *str, t_param *param)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i])
		ft_error(0, "SYNTAX ERROR");
	param->value = ft_atoi(str);
	if (param->value > REG_NUMBER)
		ft_error(0, "ERROR REG_NUMBER");
	param->code = REG_CODE;
	param->nbr_octet = 1;
	param->label = NULL;
}

t_param	*new_param(char *str, t_champ *champ, t_cmd *cmd)
{
	int i;
	t_param	*param;

	if (!(param = (t_param*)malloc(sizeof(t_param))))
		ft_error(0, "ERROR MALLOC PARAM");
	i = 0;
	param->nbr_octet = 2;
	if (str[i] == 'r')
		set_registre_param(&str[i + 1], param);
	else if (str[i] == DIRECT_CHAR)
		set_direct_param(&str[i + 1], param, champ, cmd);
	else if (str[i] == LABEL_CHAR)
		set_label_param(&str[i + 1], param, champ, IND_CODE);
	else
		set_int_param(str, param, IND_CODE);
	return (param);
}
