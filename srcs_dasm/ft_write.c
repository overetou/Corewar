/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:41:07 by pkeita            #+#    #+#             */
/*   Updated: 2018/04/11 15:41:08 by pkeita           ###   ########.fr       */
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

void	ft_write(t_env *e)
{
	ft_strcpy(e->head.prefix_name, ".name\t\t\t\"");
	ft_strcpy(e->head.prog_name, e->name);
	ft_strcpy(e->head.prefix_comment, "\"\n.comment\t\"");
	ft_strcpy(e->head.comment, e->comment);
	ft_strcpy(e->head.pad, "\"\n\n");
	write(1, (char*)(&e->head), sizeof(e->head));
}

