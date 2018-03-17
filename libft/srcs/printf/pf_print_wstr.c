/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_wstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:18:28 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/17 00:15:13 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	put_wstr(t_pf_env *e, wchar_t c)
{
	if (c <= 0x7F)
		fill_buff(c, e);
	else if (c <= 0x7FF)
	{
		fill_buff((c >> 6) + 0xC0, e);
		fill_buff((c & 0x3F) + 0x80, e);
	}
	else if (c <= 0xFFFF)
	{
		fill_buff((c >> 12) + 0xE0, e);
		fill_buff(((c >> 6) & 0x3F) + 0x80, e);
		fill_buff((c & 0x3F) + 0x80, e);
	}
	else if (c <= 0x10FFFF)
	{
		fill_buff((c >> 18) + 0xF0, e);
		fill_buff(((c >> 12) & 0x3F) + 0x80, e);
		fill_buff(((c >> 6) & 0x3F) + 0x80, e);
		fill_buff((c & 0x3F) + 0x80, e);
	}
}

int		get_wstr_len(wchar_t *wc)
{
	int i;
	int len;

	i = -1;
	len = 0;
	while (wc[++i] != 0)
	{
		if (wc[i] <= 0x7F)
			len++;
		else if (wc[i] <= 0x7FF)
			len += 2;
		else if (wc[i] <= 0xFFFF)
			len += 3;
		else if (wc[i] <= 0x10FFFF)
			len += 4;
	}
	return (len);
}

void	print_wstr_minus(t_pf_env *e, wchar_t *wc, int len)
{
	int i;

	i = -1;
	if (e->flag.prec >= 0)
	{
		while (wc[++i] != 0 && i < e->flag.prec)
			put_wstr(e, wc[i]);
	}
	else
	{
		while (wc[++i] != 0)
			put_wstr(e, wc[i]);
	}
	while (e->flag.width-- > len)
		(e->flag.zero == 1 ? fill_buff('0', e) : fill_buff(' ', e));
}

void	print_wstr(t_pf_env *e, wchar_t *wc)
{
	int i;
	int len;

	i = -1;
	len = (e->flag.prec < 0 ? get_wstr_len(wc) : e->flag.prec);
	if (e->flag.minus)
		print_wstr_minus(e, wc, len);
	else
	{
		while (e->flag.width-- > len)
			(e->flag.zero == 1 ? fill_buff('0', e) : fill_buff(' ', e));
		if (e->flag.prec >= 0)
			while (wc[++i] != 0 && i * 4 < e->flag.prec)
				put_wstr(e, wc[i]);
		else
			while (wc[++i] != 0)
				put_wstr(e, wc[i]);
	}
	++e->i;
}
