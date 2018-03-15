/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:39:05 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 09:00:17 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	print_digit_sign(t_pf_env *e)
{
	if (e->flag.plus || e->flag.sp)
		(e->flag.plus == 1 ?
		put_buff('+', e) : put_buff(' ', e));
//		write(1, "+", 1) : write(1, " ", 1));
	else if (e->flag.neg)
		put_buff('-', e);
//		e->ret += write(1, "-", 1);
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
			put_buff(' ', e);
//			e->ret += write(1, " ", 1);
		i = -1;
		while ((int)ft_strlen(e->out) < len - ++i)
			put_buff('0', e);
//			e->ret += write(1, "0", 1);
	}
	else
		while (e->flag.width - ++i > len)
			(e->flag.zero == 1 ?
			put_buff('0', e) : put_buff(' ', e));
//			write(1, "0", 1) : write(1, " ", 1));
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
		put_sbuff(e->out, e);
//		e->ret += write(1, e->out, ft_strlen(e->out));
	}
	else if (e->flag.minus)
	{
		print_digit_sign(e);
		put_sbuff(e->out, e);
//		e->ret += write(1, e->out, ft_strlen(e->out));
		print_digit_width(e);
	}
	else
	{
		print_digit_width(e);
		print_digit_sign(e);
		put_sbuff(e->out, e);
//		e->ret += write(1, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}
