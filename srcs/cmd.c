/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:11:29 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/22 14:46:46 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse_param(t_cmd *cmd, t_champ *champ)
{
	int len;
	char *tmp;
	t_param *param;

	while (ft_isspace(champ->file[champ->i]))
		champ->i++;
	len = ft_charcspn(&champ->file[champ->i], SEPARATOR_CHAR);
	tmp = ft_strsub(champ->file, champ->i, len);
	champ->i += len;
	param = NULL;
	push_param(&param, new_param(tmp, champ, cmd));
}

t_cmd	*new_cmd(t_op *op, t_champ *champ, int index)
{
	t_cmd	*cmd;

	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		ft_error("ERROR MALLOC CMD", 0);
	cmd->op = op;
	cmd->index = index;
	cmd->next = NULL;
	parse_param(cmd, champ);
}
