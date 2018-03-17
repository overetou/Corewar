/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:35:00 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/16 23:48:41 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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
			parse_flag(fmt, &e);
			parse_conv(fmt, &e);
		}
		else if (fmt[e.i] == '%' && fmt[e.i + 1] == '%')
		{
			fill_buff('%', &e);
			e.i += 2;
		}
		else
			fill_buff(fmt[e.i++], &e);
	}
	if (e.b)
		print_buff(&e);
	va_end(e.ap);
	return (e.ret);
}
