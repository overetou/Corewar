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

void		ft_free_everything(t_env *e)
{
	t_cmd 	*tmp;

	free(e->file);
	free(e->name);
	free(e->comment);
	while (e->cmd)
	{
		tmp = e->cmd->next;
		free(e->cmd);
		e->cmd = tmp;
	}
}


void		ft_error(t_env *e, char *message)
{
	ft_free_everything(e);
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void		ft_iter(t_env *e, char *message, int check, t_cmd *cmd)
{
	int 	i;

	++(e->j); 
	++(e->i);
	i = e->j + PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
	if (e->j != e->champ_size && e->i != e->len)
		return ;
	if (e->j == e->champ_size || e->i == e->len)
	{
		check == 1 ? ft_error(e, message) : 0;
		cmd->index != cmd->nb_params ? ft_error(e, "Don't fuck with me") : 0;
		i != e->len ? ft_error(e, message) : 0;
		e->i != e->len ? ft_error(e, message) : 0;
		e->j != e->champ_size ? ft_error(e, message) : 0;
	}
}

void		store_file(t_env *e, char *file_name)
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

int			main(int argc, char **argv)
{
	t_env 	e;
	int 	arg;
	int 	len;

	if (argc < 1)
		ft_error(&e, "Usage : ./dasm *.cor ...\n");
	arg = 0;
	ft_bzero(&e, sizeof(e));
	while (++arg < argc)
	{
		len = ft_strlen(argv[arg]) - 1;
		if (len > 3 && argv[arg][len] == 'r' && argv[arg][len - 1] == 'o' &&
			argv[arg][len - 2] == 'c' && argv[arg][len - 3] == '.')
		{
			store_file(&e, argv[arg]);
			ft_parse(&e);
			ft_creat_fill_file(&e, argv[arg], len);
			ft_free_everything(&e);
		}
		else
			ft_printf("File %d is invalid\n", arg++);
	}

	return (0);
}
