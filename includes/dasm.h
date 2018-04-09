/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:13:26 by kenguyen          #+#    #+#             */
/*   Updated: 2018/04/09 11:31:10 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DASM_H
# define DASM_H

# include <libft.h>
# include <fcntl.h>
# include "op.h"

typedef struct			s_env
{
	char	*file;
	int		len;
}						t_env;

#endif
