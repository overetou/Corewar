/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:35:00 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 18:04:52 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	fill_buff(const char c, t_pf_env *e)
{
	e->buff[e->b++] = c;
	if (e->b == PF_BUFF_SIZE)
		print_buff(e);
}

void	fill_sbuff(const char *str, t_pf_env *e)
{
	while (*str)
		fill_buff(*str++, e);
}

void	print_buff(t_pf_env *e)
{
		e->ret += write(1, e->buff, e->b);
		ft_bzero(&e->buff, PF_BUFF_SIZE);
		e->b = 0;
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
			fill_buff('%', &e);
			e.i += 2;
		}
		else
			fill_buff(fmt[e.i++], &e);
	}
	print_buff(&e);
	va_end(e.ap);
	return (e.ret);
}
