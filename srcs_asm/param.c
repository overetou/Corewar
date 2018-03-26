/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:51:26 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/26 17:28:50 by ysingaye         ###   ########.fr       */
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

void	set_int_param(char *str, t_param *param, int code, t_champ *champ)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i])
		ft_error(champ, "SYNTAX ERROR1");
	param->value = ft_atoi(str);
	param->code = code;
	param->label = NULL;
}

void	set_label_param(char *str, t_param *param, int code, t_champ *champ)
{
	int i;

	i = ft_strspn(str, LABEL_CHARS);
	if (str[i])
		ft_error(champ, "SYNTAX ERROR2");
	param->value = 0;
	param->code = code;
	param->label = str;
}

void	set_direct_param(char *str, t_param *param, t_cmd *cmd, t_champ *champ)
{
	if (!cmd->op->dir_size)
		param->nbr_octet = 4;
	if (str[0] == LABEL_CHAR)
		set_label_param(&str[1], param, DIR_CODE, champ);
	else
		set_int_param(str, param, DIR_CODE, champ);
}

void	set_registre_param(char *str, t_param *param, t_champ *champ)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i])
		ft_error(champ, "SYNTAX ERROR3");
	param->value = ft_atoi(str);
	if (param->value > REG_NUMBER)
		ft_error(champ, "ERROR REG_NUMBER");
	param->code = REG_CODE;
	param->nbr_octet = 1;
	param->label = NULL;
}

t_param	*new_param(char *str, t_cmd *cmd, t_champ *champ)
{
	t_param	*param;

	if (!(param = (t_param*)malloc(sizeof(t_param))))
		ft_error(champ, "ERROR MALLOC PARAM");
	param->nbr_octet = 2;
	if (!str || !*str)
		ft_error(champ, "PARAM NULL");
	if (str[0] == 'r')
		set_registre_param(&str[1], param, champ);
	else if (str[0] == DIRECT_CHAR)
		set_direct_param(&str[1], param, cmd, champ);
	else if (str[0] == LABEL_CHAR)
		set_label_param(&str[1], param, IND_CODE, champ);
	else
		set_int_param(str, param, IND_CODE, champ);
	return (param);
}
