/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:18:15 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/17 00:18:03 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	print_str_width(t_pf_env *e)
{
	int len;

	len = ft_strlen(e->out);
	while (e->flag.width-- > len)
		(e->flag.zero == 1 ? fill_buff('0', e) : fill_buff(' ', e));
}

void	print_null_str(t_pf_env *e)
{
	int len;

	len = (e->flag.prec < 0 ? 6 : e->flag.prec);
	while (e->flag.width-- > len)
		(e->flag.zero == 1 ? fill_buff('0', e) : fill_buff(' ', e));
	fill_sbuff("(null)", e);
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
		fill_sbuff(e->out, e);
		print_str_width(e);
	}
	else
	{
		print_str_width(e);
		fill_sbuff(e->out, e);
	}
	++e->i;
	free(e->out);
}
