/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:38:35 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 04:48:25 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	print_char_width(t_pf_env *e)
{
	while (e->flag.width-- > 1)
		e->ret += (e->flag.zero == 1 ?
		write(1, "0", 1) : write(1, " ", 1));
}

void	print_null_char(t_pf_env *e)
{
	while (e->flag.width-- > 1)
		e->ret += (e->flag.zero == 1 ?
		write(1, "0", 1) : write(1, " ", 1));
	e->ret += write(1, "\0", 1);
	++e->i;
}

void	print_char(t_pf_env *e, char c)
{
	if (e->flag.minus)
	{
		e->ret += write(1, &c, 1);
		print_char_width(e);
	}
	else
	{
		print_char_width(e);
		e->ret += write(1, &c, 1);
	}
	++e->i;
}
