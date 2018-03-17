/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:18:21 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/17 00:20:29 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	put_wchar(t_pf_env *e, wchar_t c)
{
	if (c <= 0x7F)
		fill_buff(c, e);
	else if (c <= 0x7FF)
	{
		fill_buff((c >> 6) + 0xC0, e);
		fill_buff((c & 0x3F) + 0x80, e);
		e->ret -= 1;
	}
	else if (c <= 0xFFFF)
	{
		fill_buff((c >> 12) + 0xE0, e);
		fill_buff(((c >> 6) & 0x3F) + 0x80, e);
		fill_buff((c & 0x3F) + 0x80, e);
		e->ret -= 2;
	}
	else if (c <= 0x10FFFF)
	{
		fill_buff((c >> 18) + 0xF0, e);
		fill_buff(((c >> 12) & 0x3F) + 0x80, e);
		fill_buff(((c >> 6) & 0x3F) + 0x80, e);
		fill_buff((c & 0x3F) + 0x80, e);
		e->ret -= 3;
	}
}

void	print_wchar_minus(t_pf_env *e, wchar_t wc)
{
	put_wchar(e, wc);
	while (e->flag.width-- > 1)
		fill_buff(' ', e);
}

void	print_wchar(t_pf_env *e, wchar_t wc)
{
	if (e->flag.minus)
		print_wchar_minus(e, wc);
	else
	{
		while (e->flag.width-- > 1)
			(e->flag.zero ? fill_buff('0', e) : fill_buff(' ', e));
		put_wchar(e, wc);
	}
	++e->i;
}
