/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:33:31 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/17 01:04:24 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **lst, void (*del)(void *, size_t))
{
	if (lst && *lst)
	{
		(*del)((*lst)->content, (*lst)->content_size);
		if ((*lst)->next)
			ft_lstdel(&(*lst)->next, del);
		free(*lst);
		*lst = NULL;
	}
}
