/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:35:00 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 08:45:01 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	put_buff(const char c, t_pf_env *e)
{
	e->buff[e->b++] = c;
	if (e->b == PF_BUFF_SIZE)
	{
		e->ret += write(1, e->buff, PF_BUFF_SIZE);
		ft_bzero(&e->buff, PF_BUFF_SIZE);
		e->b = 0;
	}
}

void	put_sbuff(const char *str, t_pf_env *e)
{
	while (*str)
		put_buff(*str++, e);
}

int		ft_printf(const char *restrict fmt, ...)
{
	t_pf_env	e;

	ft_bzero(&e, sizeof(e));
	va_start(e.ap, fmt);
	while (fmt[e.i])
	{
		if (fmt[e.i] == '%' && fmt[e.i + 1] != '%')
		{
			++e.i;
			get_flag(fmt, &e);
			get_spec(fmt, &e);
		}
		else if (fmt[e.i] == '%' && fmt[e.i + 1] == '%')
		{
			put_buff('%', &e);
//			e.ret += write(1, "%", 1);
			e.i += 2;
		}
		else
			put_buff(fmt[e.i++], &e);
//			e.ret += write(1, &fmt[e.i++], 1);
	}
	if (e.b)
		e.ret += write(1, e.buff, e.b);
	va_end(e.ap);
	return (e.ret);
}
