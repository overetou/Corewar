/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:35:00 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 03:23:35 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	add_buff(const char c, t_pf_env *e)
{
	if (e->b > 4096)
	{
		e->ret = write(1, e->buff, ft_strlen(e->buff));
		ft_bzero(&e->buff, 4096);
		e->b = 0;
	}
	e->buff[e->b++] = c;
}

void	add_sbuff(const char *str, t_pf_env *e)
{
	while (*str)
		add_buff(*str++, e);
}

int		ft_printf(const char *restrict fmt, ...)
{
	t_pf_env	e;

	ft_bzero(&e, sizeof(e));
	va_start(e.ap, fmt);
//	while (fmt[e.i])
//	{
/*		if (fmt[e.i] == '%' && fmt[e.i + 1] != '%')
		{
			++e.i;
			get_flag(fmt, &e);
			get_spec(fmt, &e);
		}
		else if (fmt[e.i] == '%' && fmt[e.i + 1] == '%')
		{
			e.ret += write(1, "%", 1);
			e.i += 2;
		}
		else
			e.ret += write(1, &fmt[e.i++], 1);*/
//		add_buff(fmt[e.i++], &e);
//	}
	add_sbuff("salut", &e);
	if (e.b)
		e.ret = write(1, e.buff, ft_strlen(e.buff));
	va_end(e.ap);
	return (e.ret);
}
