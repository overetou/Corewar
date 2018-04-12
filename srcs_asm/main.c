/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:41:32 by overetou          #+#    #+#             */
/*   Updated: 2018/04/12 18:38:57 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void		parse_args(t_champ *champ)
{
	champ->name = NULL;
	champ->comment = NULL;
	champ->cmd = NULL;
	champ->label = NULL;
	set_name_comment(champ);
	parse_instruct(champ);
	valid_labels(champ);
}

char	*read_file(char *file_name)
{
	int		fd;
	char	*str;
	int		offset;

	str = NULL;
	if ((fd = open(file_name, O_RDONLY)) < 0)
		ft_error(NULL, "BUG OPEN FILE");
	offset = lseek(fd, 0, SEEK_END);
	if (!(str = ft_strnew(offset)))
		ft_error(NULL, "MALLOC FAIL");
	lseek(fd, 0, SEEK_SET);
	if (read(fd, str, offset) < 0)
		ft_error(NULL, "READ FAIL");
	close(fd);
	return (str);
}

int		main(int argc, char **argv)
{
	t_champ	champ;
	int		i;

	i = 0;
	if (argc < 2)
		ft_error(NULL, "Usage");
	while (++i < argc)
	{
		if (!ft_strcmp(&argv[i][ft_strlen(argv[i]) - 2], ".s"))
		{
			ft_bzero(&champ, sizeof(champ));
			champ.file = read_file(argv[i]);
			parse_args(&champ);
			file_creation(&champ, argv[i]);
			free_env(&champ);
		}
		else
			ft_error(NULL, "ERROR on NAME");
	}
	return (0);
}
