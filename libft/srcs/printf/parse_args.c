/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:38:06 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/05 00:06:04 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	init_flag(t_pf_flag *flag)
{
	flag->sp = 0;
	flag->plus = 0;
	flag->neg = 0;
	flag->minus = 0;
	flag->hash = 0;
	flag->zero = 0;
	flag->prec = -1;
	flag->width = 0;
}

void	get_mod(const char *restrict fmt, t_pf_env *e)
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

void	get_prec(const char *restrict fmt, t_pf_env *e)
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

void	get_flag(const char *restrict fmt, t_pf_env *e)
{
	init_flag(&e->flag);
	e->mod = pf_nomod;
	while (ft_strchr(" #+-.0123456789hjlz", fmt[e->i]))
	{
		fmt[e->i] >= 'h' && fmt[e->i] <= 'z' ? get_mod(fmt, e) : 0;
		fmt[e->i] == ' ' ? e->flag.sp = 1 : 0;
		fmt[e->i] == '-' ? e->flag.minus = 1 : 0;
		fmt[e->i] == '+' ? e->flag.plus = 1 : 0;
		fmt[e->i] == '#' ? e->flag.hash = 1 : 0;
		fmt[e->i] == '0' ? e->flag.zero = 1 : 0;
		if (fmt[e->i] == '.')
			get_prec(fmt, e);
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

void	get_spec(const char *restrict fmt, t_pf_env *e)
{
	if (fmt[e->i] == '%' || !fmt[e->i])
		spec_percent(e);
	else if ((fmt[e->i] == 'd' || fmt[e->i] == 'i') && e->mod != pf_z)
		spec_int(e);
	else if (fmt[e->i] == 'u' || fmt[e->i] == 'U' || fmt[e->i] == 'D' ||
			((fmt[e->i] == 'd' || fmt[e->i] == 'i') && e->mod == pf_z))
		spec_unsint(e, fmt[e->i]);
	else if ((fmt[e->i] == 'c' || fmt[e->i] == 's') && e->mod != pf_l)
		spec_char(e, fmt[e->i]);
	else if (((fmt[e->i] == 'c' || fmt[e->i] == 's') && e->mod == pf_l) ||
			fmt[e->i] == 'C' || fmt[e->i] == 'S')
		spec_wchar(e, fmt[e->i]);
	else if (ft_strchr("boxBOX", fmt[e->i]))
		spec_base(e, fmt[e->i]);
	else if (fmt[e->i] == 'p' || fmt[e->i] == 'P')
		spec_ptraddr(e, fmt[e->i]);
	else if (fmt[e->i] != '\0')
		print_invalid_spec(e, fmt[e->i]);
}
