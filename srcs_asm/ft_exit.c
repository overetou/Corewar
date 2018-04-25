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
// free a corriger : pointer being freed was not allocated
/*
void	creat_check(t_champ *champ, void *check)
{
	static int i = 0;

	ft_dprintf(champ->fd_check, "malloc numero %d : %p\n", ++i, check);
}

void	free_check(t_champ *champ, void *check)
{
	static int i = 0;

	ft_dprintf(champ->fd_check, "free numero %d : %p\n", ++i, check);
}
*/

void	free_param(t_param *param)
{
	int i = 1;
	t_param *tmp;

	while (param)
	{
		printf("\n%d param will be free\n{", i);
		tmp = param->next;
		free(param);
		printf("\n%d param has been freed\n}", i++);
		param = tmp;
	}
}

void	free_cmd(t_cmd *cmd)
{
	int i = 0;
	t_cmd *tmp;

	while (cmd)
	{
		printf("\n%d cmd will be free\n{", i);
		// printf("\n%d cmd parameter be free\n{", i);
		if (cmd->param)
			free_param(cmd->param);
		// printf("\n%d cmd parameter has  been freed\n}", i);
		tmp = cmd->next;
		free(cmd);
		printf("\n%d cmd has  been freed\n}", i++);
		cmd = tmp;
	}
}

void	free_champ(t_champ *champ)
{
	int i = 0;
	t_label *tmp;

	ft_strdel(&(champ->file));
	ft_strdel(&(champ->name));
	ft_strdel(&(champ->comment));
	free_cmd(champ->cmd);
	// exit(0);
	while (champ->label)
	{
		printf("\n%d label will be free\n{", i);
		tmp = champ->label->next;
		// printf("\n%d label cmd will be free\n{", i);
		free_cmd(champ->label->cmd);
		// printf("\n%d label cmd has been freed\n}", i);
		printf("\n%d label name will be free{\n", i);
		if (champ->label->name)
			ft_strdel(&(champ->label->name));
		printf("\n%d label name has been freed\n}", i);
		free(champ->label);
		printf("\n%d label cmd has been freed\n}", i++);
		champ->label = tmp;
	}
	
}

void	ft_error(t_champ *champ, char *message)
{
	int 	i;
	int		nb_line;
	int 	coll;

	i = 0;
	nb_line = 0;
	coll = 0;
	while (i < champ->i)
	{
		coll++;
		if (champ->file[i] == '\n')
		{
			coll = 0;
			nb_line++;
		}
		i++;
	}
	/*
	while (i > 0 && champ->file[i] != '\n' && champ->file[i] != ' ' &&
		champ->file[i] != '\t')
	{
		i--;
		coll--;
	}
	*/
	// free_champ(champ);
	ft_printf("Syntax error at  Line %d column %d :%s\n", nb_line,
		coll, message);
	exit(EXIT_FAILURE);
}
