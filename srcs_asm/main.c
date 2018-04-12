/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:41:32 by overetou          #+#    #+#             */
/*   Updated: 2018/04/10 18:02:18 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

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

	i = 1;
	ft_bzero(&champ, sizeof(champ));
	if (argc < 2)
		ft_error(NULL, "Usage");
	if (argc == 2 && !ft_strcmp(&argv[i][ft_strlen(argv[i]) - 2], ".s"))
	{
		champ.file = read_file(argv[i]);
		parse(&champ);
		manage_file_creation(&champ, argv[i]);
		free_env(&champ);
	}
	else
		ft_error(NULL, "ERROR on NAME");
	return (0);
}
