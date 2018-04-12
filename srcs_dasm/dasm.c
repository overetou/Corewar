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
dabord on check si on, a le magic si non on affiche bad header; si on a le name
sinon cas d'erreur etc...
*/
// toujours checker si le fichier est finit ou pas. via la len dans la struct env
void	ft_error(t_env *e, char *message)
{
	//if (e->file)
	//	free(e->file);
	e = (t_env*)e;
	ft_printf("%s\n", message);
	exit (0);
}

void	ft_iter(t_env *e, char *message, int check, t_cmd *cmd)
{
	int i;

	++(e->j); 
	++(e->i);
	// printf("\niter, e->i == %d\ne->len == %d\n", e->i, e->len);
	// printf("iter, e->j == %d\ne->champ_size == %d\n", e->j, e->champ_size);
	i = e->j + PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
	if (e->j != e->champ_size && e->i != e->len)
		return ;
	if (e->j == e->champ_size || e->i == e->len)
	{
		// printf("i == %d ?\n", i);
		check == 1 ? ft_error(e, message) : 0;
		cmd->index != cmd->nb_params ? ft_error(e, "BAD NB PARAM") : 0;
		i != e->len ? ft_error(e, message) : 0;
		e->i != e->len ? ft_error(e, message) : 0;
		e->j != e->champ_size ? ft_error(e, message) : 0;
		// ft_creat_file(e);
	}
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
	ft_write(e);
	printf("SUCESS1\n");


}

int			main(int argc, char **argv)
{
	t_env e;
	int arg;
	int len;

	if (argc < 1)
		ft_error(&e, "Usage : ./dasm *.cor ...\n");
	arg = 1;
	ft_bzero(&e, sizeof(e));
	while (arg < argc)
	{
		len = ft_strlen(argv[arg]) - 1;
		if (len > 3 && argv[arg][len] == 'r' && argv[arg][len - 1] == 'o' &&
			argv[arg][len - 2] == 'c' && argv[arg][len - 3] == '.')
			ft_dasm(&e, argv[arg++]);
		else
			ft_printf("File %d is invalid\n", arg++);
	}
	return (0);
}
