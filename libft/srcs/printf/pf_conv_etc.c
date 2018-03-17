/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_etc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:14:56 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/17 00:01:04 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	conv_ptraddr(t_pf_env *e, char type)
{
	long			tmp;
	unsigned long	addr;

	tmp = va_arg(e->ap, long);
	addr = (unsigned long)tmp;
	if (e->flag.prec == 0)
		e->out = ft_strdup("\0");
	else
		e->out = ft_ltoa_base(addr, 16);
	print_ptraddr(e, type);
}

void	conv_wchar(t_pf_env *e, char type)
{
	wchar_t *ws;
	wchar_t wc;

	e->flag.minus ? e->flag.zero = 0 : 0;
	if (type == 's' || type == 'S')
	{
		ws = va_arg(e->ap, wchar_t *);
		if (ws == NULL)
			return (print_null_str(e));
		print_wstr(e, ws);
	}
	else if (type == 'c' || type == 'C')
	{
		wc = va_arg(e->ap, wchar_t);
		if (wc == 0)
			return (print_null_char(e));
		print_wchar(e, wc);
	}
}

void	conv_percent(t_pf_env *e)
{
	if (e->flag.minus)
	{
		fill_buff('%', e);
		while (e->flag.width-- > 1)
			fill_buff(' ', e);
	}
	else
	{
		while (e->flag.width-- > 1)
			(e->flag.zero ? fill_buff('0', e) : fill_buff(' ', e));
		fill_buff('%', e);
	}
	++e->i;
}
