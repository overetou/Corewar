/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:25:09 by pkeita            #+#    #+#             */
/*   Updated: 2018/04/12 16:25:10 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dasm.h>

// entre chaque params on met ", "
// avant un direct on met DIRECT_CHAR
// avant un registre on met r
/*
void	ft_creat_file(t_env *e)
{
	int fd;
	int size;


}
*/

void	ft_print_cmd(t_env *e)
{
	int i;
	write(1, "-------------------------\n\n\n\n\n", 30);
	while (e->cmd)
	{
		i = 0;
		ft_printf("\t%s ", e->cmd->op->short_name);
		while (i < e->cmd->index)
		{
			if (e->cmd->param[i].code == REG_CODE)
				ft_printf("r%d", e->cmd->param[i].value);
			else if (e->cmd->param[i].code == DIR_CODE && 
				e->cmd->param[i].nbr_octet == 2)
				ft_printf("%c%hd", DIRECT_CHAR, e->cmd->param[i].value);
			else if (e->cmd->param[i].code == DIR_CODE && 
				e->cmd->param[i].nbr_octet == 4)
				ft_printf("%c%d", DIRECT_CHAR, e->cmd->param[i].value);
			else if (e->cmd->param[i].code == IND_CODE)
				ft_printf("r%d", e->cmd->param[i].value);
			else 
				ft_error(e, "WTF Parsing AAAAYAAAA\n\\/ \\/ \\/\n\n");
			++i != e->cmd->index ? write(1, ",", 1) : 0;
		}
		write(1, "\n", 1);
		e->cmd = e->cmd->next;
	}
}

void	ft_write(t_env *e)
{
	ft_strcpy(e->head.prefix_name, ".name\t\t\t\"");
	ft_strcpy(e->head.prog_name, e->name);
	ft_strcpy(e->head.prefix_comment, "\"\n.comment\t\"");
	ft_strcpy(e->head.comment, e->comment);
	ft_strcpy(e->head.pad, "\"\n\n");
	write(1, (char*)(&e->head), sizeof(e->head));
	ft_print_cmd(e);
}

