/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:26:07 by ysingaye          #+#    #+#             */
/*   Updated: 2018/04/12 19:16:25 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	free_param(t_param *param)
{
	t_param *tmp;

	while (param)
	{
		tmp = param->next;
		if (param->label)
			free(param->label);
		free(param);
		param = tmp;
	}
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd *tmp;

	while (cmd)
	{
		if (cmd->param)
			free_param(cmd->param);
		tmp = cmd->next;
		free(cmd);
		cmd = tmp;
	}
}

void	free_champ(t_champ *champ)
{
	t_label *tmp;

	ft_strdel(&(champ->file));
	ft_strdel(&(champ->name));
	ft_strdel(&(champ->comment));
	free_cmd(champ->cmd);
	while (champ->label)
	{
		tmp = champ->label->next;
		if (champ->label->name)
			ft_strdel(&(champ->label->name));
		free(champ->label);
		champ->label = tmp;
	}
}

void	ft_error(t_champ *champ, char *m)
{
	int		i;
	int		nb_line;
	int		coll;

	i = -1;
	nb_line = 1;
	coll = 1;
	while (++i < champ->i)
	{
		coll++;
		if (champ->file[i] == '\n')
		{
			coll = 1;
			nb_line++;
		}
	}
	free_champ(champ);
	ft_printf("Syntax error at  Line %d column %d :%s\n", nb_line, coll, m);
	exit(EXIT_FAILURE);
}

void	ft_error_label(t_champ *champ, char *m, char *label)
{
	int		i;
	int		nb_line;
	int		coll;

	i = -1;
	nb_line = 1;
	coll = 1;
	while (++i < champ->i)
	{
		if (champ->file[i] == '\n')
		{
			coll = 0;
			nb_line++;
		}
		if (label && ft_strnequ(&(champ->file[i]), label, ft_strlen(label)))
			break ;
		coll++;
	}
	free_champ(champ);
	ft_printf("Syntax error at  Line %d column %d :%s\n", nb_line, coll, m);
	exit(EXIT_FAILURE);
}
