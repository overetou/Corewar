/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:17:40 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/17 00:16:25 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	print_base_pre(t_pf_env *e, char type, long val)
{
	if (e->flag.hash && e->out[0] != '\0' && val != 0)
	{
		(type == 'o' || type == 'O') ? fill_buff('0', e) : 0;
		(type == 'x') ? fill_sbuff("0x", e) : 0;
		(type == 'X') ? fill_sbuff("0X", e) : 0;
		type == 'a' || type == 'A' ? e->flag.width -= 2 : 0;
	}
	else if ((type == 'o' || type == 'O') && e->flag.hash && e->flag.prec >= 0)
		fill_buff('0', e);
	else if (type == 'a' || type == 'A')
	{
		if (e->flag.plus || e->flag.sp)
		{
			e->flag.sp ? fill_buff(' ', e) : fill_buff('+', e);
			e->flag.width--;
		}
		type == 'a' ? fill_sbuff("0x", e) : fill_sbuff("0X", e);
		e->flag.width -= 2;
	}
}

void	print_base_width(t_pf_env *e, char type)
{
	int	i;
	int len;

	i = -1;
	len = ft_strlen(e->out);
	if (e->flag.hash && (e->out[0] != '\0' && e->out[0] != '0'))
	{
		e->flag.width -= ((type == 'o' || type == 'O') ? 1 : 0);
		e->flag.width -= ((type == 'x' || type == 'X') ? 2 : 0);
	}
	if (e->flag.prec >= 0)
	{
		while (e->flag.width > e->flag.prec + ++i && e->flag.width > len + i)
			fill_buff(' ', e);
		while (e->flag.width > len + i++)
			fill_buff('0', e);
	}
	else
	{
		while (e->flag.width > len + ++i)
			(e->flag.zero == 1 ? fill_buff('0', e) : fill_buff(' ', e));
	}
}

void	check_base_prec(t_pf_env *e, char type)
{
	char	*tmp;
	char	*res;
	int		len;
	int		i;

	len = (int)ft_strlen(e->out);
	if (e->flag.prec == 0 && e->out[0] == '0')
		e->out[0] = '\0';
	else if (e->flag.prec > len)
	{
		if ((type == 'o' || type == 'O') && e->flag.hash)
			e->flag.prec--;
		i = e->flag.prec - len;
		tmp = ft_strnew(i);
		while (--i >= 0)
			tmp[i] = '0';
		res = ft_strjoin(tmp, e->out);
		free(tmp);
		free(e->out);
		e->out = res;
	}
}

void	print_base(t_pf_env *e, char type, long val)
{
	check_base_prec(e, type);
	if (e->flag.zero)
	{
		print_base_pre(e, type, val);
		print_base_width(e, type);
		fill_sbuff(e->out, e);
	}
	else if (e->flag.minus)
	{
		print_base_pre(e, type, val);
		fill_sbuff(e->out, e);
		print_base_width(e, type);
	}
	else
	{
		print_base_width(e, type);
		print_base_pre(e, type, val);
		fill_sbuff(e->out, e);
	}
	++e->i;
	free(e->out);
}
