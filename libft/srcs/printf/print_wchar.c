/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:40:41 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 09:34:27 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	put_wchar(t_pf_env *e, char c)
{
	put_buff(c, e);
//	write(1, &c, 1);
}

void	put_wc(t_pf_env *e, wchar_t c)
{
	if (c <= 0x7F)
		put_wchar(e, c);
	else if (c <= 0x7FF)
	{
		put_wchar(e, (c >> 6) + 0xC0);
		put_wchar(e, (c & 0x3F) + 0x80);
		e->ret -= 1;
	}
	else if (c <= 0xFFFF)
	{
		put_wchar(e, ((c >> 12) + 0xE0));
		put_wchar(e, ((c >> 6) & 0x3F) + 0x80);
		put_wchar(e, (c & 0x3F) + 0x80);
		e->ret -= 2;
	}
	else if (c <= 0x10FFFF)
	{
		put_wchar(e, (c >> 18) + 0xF0);
		put_wchar(e, ((c >> 12) & 0x3F) + 0x80);
		put_wchar(e, ((c >> 6) & 0x3F) + 0x80);
		put_wchar(e, (c & 0x3F) + 0x80);
		e->ret -= 3;
	}
//	++e->ret;
}

void	print_wchar_minus(t_pf_env *e, wchar_t wc)
{
	put_wc(e, wc);
	while (e->flag.width-- > 1)
		put_buff(' ', e);
//		e->ret += write(1, " ", 1);
}

void	print_wchar(t_pf_env *e, wchar_t wc)
{
	if (e->flag.minus)
		print_wchar_minus(e, wc);
	else
	{
		while (e->flag.width-- > 1)
			(e->flag.zero ?
			put_buff('0', e) : put_buff(' ', e));
//			write(1, "0", 1) : write(1, " ", 1));
		put_wc(e, wc);
	}
	++e->i;
}
