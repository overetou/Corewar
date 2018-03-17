/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:17:27 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/16 23:57:51 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	parse_mod(const char *restrict fmt, t_pf_env *e)
{
	if (fmt[e->i] == 'h' && fmt[e->i + 1] != 'h' && e->mod == pf_nomod)
		e->mod = pf_h;
	else if (fmt[e->i] == 'h' && fmt[e->i + 1] == 'h' && e->mod == pf_nomod)
	{
		e->mod = pf_hh;
		++e->i;
	}
	else if (fmt[e->i] == 'l' && fmt[e->i + 1] != 'l')
		e->mod = pf_l;
	else if (fmt[e->i] == 'l' && fmt[e->i + 1] == 'l')
	{
		e->mod = pf_ll;
		++e->i;
	}
	else if (fmt[e->i] == 'z')
		e->mod = pf_z;
	else if (fmt[e->i] == 'j')
		e->mod = pf_j;
}

void	parse_prec(const char *restrict fmt, t_pf_env *e)
{
	if (e->flag.prec >= 0)
	{
		++e->i;
		return ;
	}
	else if (fmt[e->i] == '.')
	{
		++e->i;
		e->flag.prec = ft_atoi(fmt + e->i);
		while ((fmt[e->i]) >= '0' && fmt[e->i] <= '9')
			++e->i;
	}
}

void	parse_flag(const char *restrict fmt, t_pf_env *e)
{
	ft_bzero(&e->flag, sizeof(e->flag));
	e->flag.prec = -1;
	e->mod = pf_nomod;
	while (ft_strchr(" #+-.0123456789hjlz", fmt[e->i]))
	{
		fmt[e->i] >= 'h' && fmt[e->i] <= 'z' ? parse_mod(fmt, e) : 0;
		fmt[e->i] == ' ' ? e->flag.sp = 1 : 0;
		fmt[e->i] == '-' ? e->flag.minus = 1 : 0;
		fmt[e->i] == '+' ? e->flag.plus = 1 : 0;
		fmt[e->i] == '#' ? e->flag.hash = 1 : 0;
		fmt[e->i] == '0' ? e->flag.zero = 1 : 0;
		if (fmt[e->i] == '.')
			parse_prec(fmt, e);
		else if (fmt[e->i] >= '1' && fmt[e->i] <= '9' && e->flag.prec < 0)
		{
			e->flag.width = ft_atoi(fmt + e->i);
			while (fmt[e->i] >= '0' && fmt[e->i] <= '9')
				++e->i;
		}
		else
			++e->i;
	}
}

void	parse_conv(const char *restrict fmt, t_pf_env *e)
{
	if (fmt[e->i] == '%')
		conv_percent(e);
	else if ((fmt[e->i] == 'd' || fmt[e->i] == 'i') && e->mod != pf_z)
		conv_int(e);
	else if (fmt[e->i] == 'u' || fmt[e->i] == 'U' || fmt[e->i] == 'D' ||
			((fmt[e->i] == 'd' || fmt[e->i] == 'i') && e->mod == pf_z))
		conv_unsint(e, fmt[e->i]);
	else if ((fmt[e->i] == 'c' || fmt[e->i] == 's') && e->mod != pf_l)
		conv_char(e, fmt[e->i]);
	else if (((fmt[e->i] == 'c' || fmt[e->i] == 's') && e->mod == pf_l) ||
			fmt[e->i] == 'C' || fmt[e->i] == 'S')
		conv_wchar(e, fmt[e->i]);
	else if (ft_strchr("boxBOX", fmt[e->i]))
		conv_base(e, fmt[e->i]);
	else if (fmt[e->i] == 'p' || fmt[e->i] == 'P')
		conv_ptraddr(e, fmt[e->i]);
	else if (fmt[e->i] != '\0')
		print_invalid_spec(e, fmt[e->i]);
}
