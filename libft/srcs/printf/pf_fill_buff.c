/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:28:25 by kenguyen          #+#    #+#             */
/*   Updated: 2018/04/08 23:46:34 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	fill_buff(const char c, t_pf_env *e)
{
	e->buff[e->b++] = c;
	if (e->b == PF_BUFF_SIZE)
		print_buff(e);
}

void	fill_sbuff(const char *str, t_pf_env *e)
{
	while (*str)
		fill_buff(*str++, e);
}

void	print_buff(t_pf_env *e)
{
	e->ret += write(e->fd, e->buff, e->b);
	e->b = 0;
}
