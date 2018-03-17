/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:17:53 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/17 00:18:36 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	print_digit_sign(t_pf_env *e)
{
	if (e->flag.plus || e->flag.sp)
		(e->flag.plus == 1 ? fill_buff('+', e) : fill_buff(' ', e));
	else if (e->flag.neg)
		fill_buff('-', e);
}

void	print_digit_width(t_pf_env *e)
{
	int i;
	int len;

	i = -1;
	len = ((int)ft_strlen(e->out) > e->flag.prec ?
	(int)ft_strlen(e->out) : e->flag.prec);
	(e->flag.plus + e->flag.sp + e->flag.neg) >= 1 ? e->flag.width-- : 0;
	if (e->flag.prec >= 0)
	{
		while (e->flag.width - ++i > len)
			fill_buff(' ', e);
		i = -1;
		while ((int)ft_strlen(e->out) < len - ++i)
			fill_buff('0', e);
	}
	else
		while (e->flag.width - ++i > len)
			(e->flag.zero == 1 ? fill_buff('0', e) : fill_buff(' ', e));
}

void	check_digit_sign(t_pf_env *e)
{
	char *tmp;

	if (e->out[0] == '-')
	{
		tmp = ft_strdup(e->out + 1);
		free(e->out);
		e->out = tmp;
		e->flag.sp = 0;
		e->flag.plus = 0;
		e->flag.neg = 1;
	}
}

void	check_digit_prec(t_pf_env *e)
{
	char	*tmp;
	char	*res;
	int		len;
	int		i;

	check_digit_sign(e);
	len = (int)ft_strlen(e->out);
	if (e->flag.prec == 0 && e->out[0] == '0')
		e->out[0] = '\0';
	else if (e->flag.prec > len)
	{
		i = e->flag.prec - len;
		tmp = ft_strnew(i);
		while (i-- > 0)
			tmp[i] = '0';
		res = ft_strjoin(tmp, e->out);
		free(tmp);
		free(e->out);
		e->out = res;
	}
}

void	print_digit(t_pf_env *e)
{
	check_digit_prec(e);
	if (e->flag.zero)
	{
		print_digit_sign(e);
		print_digit_width(e);
		fill_sbuff(e->out, e);
	}
	else if (e->flag.minus)
	{
		print_digit_sign(e);
		fill_sbuff(e->out, e);
		print_digit_width(e);
	}
	else
	{
		print_digit_width(e);
		print_digit_sign(e);
		fill_sbuff(e->out, e);
	}
	++e->i;
	free(e->out);
}
