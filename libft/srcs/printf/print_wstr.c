/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:40:50 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/05 00:07:53 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	put_wstr_c(t_pf_env *e, char c)
{
	e->ret += write(1, &c, 1);
}

void	put_wstr(t_pf_env *e, wchar_t c)
{
	if (c <= 0x7F)
		put_wstr_c(e, c);
	else if (c <= 0x7FF)
	{
		put_wstr_c(e, (c >> 6) + 0xC0);
		put_wstr_c(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		put_wstr_c(e, ((c >> 12) + 0xE0));
		put_wstr_c(e, ((c >> 6) & 0x3F) + 0x80);
		put_wstr_c(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		put_wstr_c(e, (c >> 18) + 0xF0);
		put_wstr_c(e, ((c >> 12) & 0x3F) + 0x80);
		put_wstr_c(e, ((c >> 6) & 0x3F) + 0x80);
		put_wstr_c(e, (c & 0x3F) + 0x80);
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
		e->ret += (e->flag.zero == 1 ?
		write(1, "0", 1) : write(1, " ", 1));
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
			e->ret += (e->flag.zero == 1 ?
			write(1, "0", 1) : write(1, " ", 1));
		if (e->flag.prec >= 0)
			while (wc[++i] != 0 && i * 4 < e->flag.prec)
				put_wstr(e, wc[i]);
		else
			while (wc[++i] != 0)
				put_wstr(e, wc[i]);
	}
	++e->i;
}
