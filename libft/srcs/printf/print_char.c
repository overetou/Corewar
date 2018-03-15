/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:38:35 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 18:07:12 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	print_char_width(t_pf_env *e)
{
	while (e->flag.width-- > 1)
		(e->flag.zero == 1 ?
		fill_buff('0', e) : fill_buff(' ', e));
}

void	print_null_char(t_pf_env *e)
{
	while (e->flag.width-- > 1)
		(e->flag.zero == 1 ?
		fill_buff('0', e) : fill_buff(' ', e));
	fill_buff('\0', e);
	++e->i;
}

void	print_char(t_pf_env *e, char c)
{
	if (e->flag.minus)
	{
		fill_buff(c, e);
		print_char_width(e);
	}
	else
	{
		print_char_width(e);
		fill_buff(c, e);
	}
	++e->i;
}
