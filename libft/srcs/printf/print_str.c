/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:40:35 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/15 05:53:11 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	print_str_width(t_pf_env *e)
{
	int len;

	len = ft_strlen(e->out);
	while (e->flag.width-- > len)
		e->ret += (e->flag.zero == 1 ?
		write(1, "0", 1) : write(1, " ", 1));
}

void	print_null_str(t_pf_env *e)
{
	int len;

	len = (e->flag.prec < 0 ? 6 : e->flag.prec);
	while (e->flag.width-- > len)
		(e->flag.zero == 1 ?
		add_sbuff("0", e) : add_sbuff(" ", e));
	add_sbuff("(null)", e);
//		write(1, "0", 1) : write(1, " ", 1));
//	e->ret += write(1, "(null)", len);
	++e->i;
}

void	print_str(t_pf_env *e)
{
	char	*tmp;

	if (e->flag.prec >= 0 && e->flag.prec < (int)ft_strlen(e->out))
	{
		tmp = ft_strsub(e->out, 0, (e->flag.prec));
		free(e->out);
		e->out = tmp;
	}
	if (e->flag.minus)
	{
		add_sbuff(e->out, e);
//		e->ret += write(1, e->out, ft_strlen(e->out));
		print_str_width(e);
	}
	else
	{
		print_str_width(e);
		add_sbuff(e->out, e);
//		e->ret += write(1, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}
