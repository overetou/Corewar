/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_invalid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:18:01 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/17 00:18:15 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	print_invalid_width(t_pf_env *e)
{
	while (e->flag.width-- > 1)
		(e->flag.zero == 1 ? fill_buff('0', e) : fill_buff(' ', e));
}

void	print_invalid_spec(t_pf_env *e, char c)
{
	if (e->flag.minus)
	{
		fill_buff(c, e);
		print_invalid_width(e);
	}
	else
	{
		print_invalid_width(e);
		fill_buff(c, e);
	}
	++e->i;
}
