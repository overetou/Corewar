/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:35:00 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 05:53:51 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	add_buff(const char c, t_pf_env *e)
{
	if (e->b >= PF_BUFF_SIZE)
	{
		e->ret += write(1, e->buff, ft_strlen(e->buff));
		write(1, "|", 1);
		ft_bzero(&e->buff, PF_BUFF_SIZE);
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
			add_buff('%', &e);
//			e.ret += write(1, "%", 1);
			e.i += 2;
		}
		else
			add_buff(fmt[e.i++], &e);
//			e.ret += write(1, &fmt[e.i++], 1);
	}
	if (e.b)
		e.ret += write(1, e.buff, ft_strlen(e.buff));
	va_end(e.ap);
	return (e.ret);
}
