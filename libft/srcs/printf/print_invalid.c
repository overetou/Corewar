/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:39:17 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 08:15:13 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	print_invalid_width(t_pf_env *e)
{
	while (e->flag.width-- > 1)
		(e->flag.zero == 1 ?
		put_buff('0', e) : put_buff(' ', e));
//		write(1, "0", 1) : write(1, " ", 1));
}

void	print_invalid_spec(t_pf_env *e, char c)
{
	if (e->flag.minus)
	{
		put_buff(c, e);
//		e->ret += write(1, &c, 1);
		print_invalid_width(e);
	}
	else
	{
		print_invalid_width(e);
		put_buff(c, e);
//		e->ret += write(1, &c, 1);
	}
	++e->i;
}
