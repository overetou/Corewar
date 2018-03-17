/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:14:26 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/16 23:14:51 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	conv_base(t_pf_env *e, char type)
{
	long			tmp;
	unsigned long	val;

	val = 0;
	tmp = va_arg(e->ap, long);
	if (type == 'O' || e->mod == pf_z || e->mod == pf_ll ||
		e->mod == pf_j || e->mod == pf_l)
		val = (unsigned long)tmp;
	else if (e->mod == pf_hh)
		val = (unsigned char)tmp;
	else if (e->mod == pf_h)
		val = (unsigned short)tmp;
	else if (e->mod == pf_nomod)
		val = (unsigned int)tmp;
	(type == 'b' || type == 'B') ? e->out = ft_ultoa_base(val, 2) : 0;
	(type == 'o' || type == 'O') ? e->out = ft_ultoa_base(val, 8) : 0;
	(type == 'x' || type == 'X') ? e->out = ft_ultoa_base(val, 16) : 0;
	if (type == 'b' || type == 'o' || type == 'x')
		ft_strlower(e->out);
	e->flag.minus == 1 ? e->flag.zero = 0 : 0;
	print_base(e, type, (long)val);
}

void	conv_char(t_pf_env *e, char type)
{
	char	*stmp;
	int		ctmp;

	e->flag.minus ? e->flag.zero = 0 : 0;
	if (type == 's')
	{
		stmp = va_arg(e->ap, char *);
		if (stmp == NULL)
			return (print_null_str(e));
		e->out = ft_strdup((char*)stmp);
		print_str(e);
	}
	else if (type == 'c')
	{
		ctmp = va_arg(e->ap, int);
		print_char(e, ctmp);
	}
}

void	conv_unsint(t_pf_env *e, char type)
{
	long tmp;

	e->flag.sp = 0;
	e->flag.plus = 0;
	tmp = va_arg(e->ap, long);
	if (tmp == LLONG_MIN || tmp == LONG_MIN)
		e->out = ft_strdup("-9223372036854775808");
	else if (type == 'D' || type == 'U' || e->mod == pf_z || e->mod == pf_l ||
			e->mod == pf_j || e->mod == pf_ll)
		e->out = ft_ultoa((unsigned long)tmp);
	else if (e->mod == pf_h)
		e->out = ft_ultoa((unsigned short)tmp);
	else if (e->mod == pf_hh)
		e->out = ft_ultoa((unsigned char)tmp);
	else if (e->mod == pf_nomod && type != 'U')
		e->out = ft_ultoa((unsigned int)tmp);
	print_digit(e);
}

void	conv_int(t_pf_env *e)
{
	long tmp;
	long i;

	tmp = va_arg(e->ap, long);
	i = (long long)tmp;
	e->flag.minus == 1 ? e->flag.zero = 0 : 0;
	e->flag.prec >= 0 ? e->flag.zero = 0 : 0;
	if (tmp == LLONG_MIN || tmp == LONG_MIN)
		e->out = ft_strdup("-9223372036854775808");
	else if (e->mod == pf_hh)
		e->out = ft_itoa((char)i);
	else if (e->mod == pf_h)
		e->out = ft_itoa((short)i);
	else if (e->mod == pf_nomod)
		e->out = ft_itoa((int)i);
	else if (e->mod == pf_l || e->mod == pf_j ||
			e->mod == pf_ll)
		e->out = ft_ltoa((long)i);
	print_digit(e);
}
