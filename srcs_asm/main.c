/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:41:32 by overetou          #+#    #+#             */
/*   Updated: 2018/03/26 18:03:58 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*read_file(char *file_name)
{
	int fd;
	char *str;
	int offset;

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

int main(int argc, char **argv)
{
	t_champ	champ;

	bzero(&champ, sizeof(champ));
    if (argc != 2)
        ft_error(NULL, "USAGE");
	champ.file = read_file(argv[1]);
	champ.i = 0;
	parse(&champ);
	manage_file_creation(&champ, argv[1]);
}
