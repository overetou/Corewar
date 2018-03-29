/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:41:32 by overetou          #+#    #+#             */
/*   Updated: 2018/03/29 20:39:23 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

void	ft_strendcmp(const char *s1, const char *s2)
{
	int	i;

	i = ft_strlen(s1) - ft_strlen(s2);
	if (ft_strcmp(s1 + i, s2))
		ft_error(NULL, "ERROR on NAME");
}

int		main(int argc, char **argv)
{
	t_champ	champ;

	ft_bzero(&champ, sizeof(champ));
	if (argc-- < 2)
		ft_error(NULL, "Usage");
	ft_strendcmp(argv[argc], ".s");
	champ.file = read_file(argv[argc]);
	parse(&champ);
	manage_file_creation(&champ, argv[argc]);
	return (0);
}
