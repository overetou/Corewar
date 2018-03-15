/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spec_etc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:40:28 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 08:09:26 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	spec_ptraddr(t_pf_env *e, char type)
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

void	spec_wchar(t_pf_env *e, char type)
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

void	spec_percent(t_pf_env *e)
{
	if (e->flag.minus)
	{
		put_buff('%', e);
//		e->ret += write(1, "%", 1);
		while (e->flag.width-- > 1)
			put_buff(' ', e);
//			e->ret += write(1, " ", 1);
	}
	else
	{
		while (e->flag.width-- > 1)
			(e->flag.zero ?
			put_buff('0', e) : put_buff(' ', e));
//			write(1, "0", 1) : write(1, " ", 1));
		put_buff('%', e);
//		e->ret += write(1, "%", 1);
	}
	++e->i;
}
