/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:51:26 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/25 19:08:18 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	set_int_param(char *str, t_param *param, int code, t_champ *champ)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	i < 1 ? ft_error(champ, "Invalid parameter") : 0;
	str[i - 1] == '-' ? ft_error(champ, "Invalid parameter") : 0;
	if (str[i])
		ft_error(champ, "Invalid parameter");
	param->value = ft_atoi(str);
	param->code = code;
	param->label = NULL;
}

void	set_label_param(char *str, t_param *param, int code, t_champ *champ)
{
	int i;

	i = ft_strspn(str, LABEL_CHARS);
	if (str[i])
		ft_error(champ, "Invalid parameter");
	param->value = 0;
	param->code = code;
	param->label = ft_strdup(str);
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
	i < 1 ? ft_error(champ, "Invalid parameter") : 0;
	str[i - 1] == '-' ? ft_error(champ, "Invalid parameter") : 0;
	if (str[i])
		ft_error(champ, "Invalid parameter");
	param->value = ft_atoi(str);
	if (param->value > REG_NUMBER || param->value < 1)
		ft_error(champ, "Invalid regiter number");
	param->code = REG_CODE;
	param->nbr_octet = 1;
	param->label = NULL;
}

t_param	*new_param(char *str, t_cmd *cmd, t_champ *champ)
{
	t_param	*param;

	param = NULL;
	if (!(param = (t_param*)malloc(sizeof(t_param))))
		ft_error(champ, "Memory could not be allocated");
	param->label = NULL;
	param->nbr_octet = 2;
	param->next = NULL;
	if (!str || !*str)
	{
		if (str)
			free(str);
		ft_error(champ, "Invalid parameter");
	}
	if (str[0] == 'r')
		set_registre_param(&str[1], param, champ);
	else if (str[0] == DIRECT_CHAR)
		set_direct_param(&str[1], param, cmd, champ);
	else if (str[0] == LABEL_CHAR)
		set_label_param(&str[1], param, IND_CODE, champ);
	else
		set_int_param(str, param, IND_CODE, champ);
	free(str);
	return (param);
}
