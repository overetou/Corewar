/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:12:44 by kenguyen          #+#    #+#             */
/*   Updated: 2018/04/09 11:34:24 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dasm.h>


/* remplacer les ft_error par un solve pour faire comme dans lem lin des qu'il y 
a une faute on resoud avec ce qu'on a. si on a pas tout tant pis. c'est le mieux
je pense plutot que de checker si on a toutess les infos ou pas c casse couilles 
pour rien. vu que c'est un bonus on peut choisir de le faire comme ca oklm
*/
void	ft_error(t_env *e, char *message)
{
	if (e->file)
		free(e->file);
	ft_printf("%s\n", message);
	exit (0);
}

void	store_file(t_env *e, char *file_name)
{
	int		fd;

	if ((fd = open(file_name, O_RDONLY)) < 0)
        ft_error(e, "BUG OPEN FILE");
	e->len = lseek(fd, 0, SEEK_END);
	if (!(e->file = ft_strnew(e->len)))
		ft_error(e, "MALLOC FAIL");
	lseek(fd, 0, SEEK_SET);
	if (read(fd, e->file, e->len) < 0)
		ft_error(e, "READ FAIL");
	close(fd);
}

void		ft_dasm(t_env *e, char *argv)
{
	store_file(e, argv);
//	ft_printf("%d\n", e->len);
	ft_parse(e);

}

int			main(int argc, char **argv)
{
	t_env e;
	
	ft_bzero(&e, sizeof(e));
	if (argc == 2 && !ft_strcmp(&argv[1] [ft_strlen(argv[1]) - 4], ".cor"))
		ft_dasm(&e, argv[1]);
	else
		ft_error(&e, "yo c pa un .cor");
	return (0);
}
