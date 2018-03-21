/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:41:32 by overetou          #+#    #+#             */
/*   Updated: 2018/03/21 15:20:33 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "corewar.h"

char	*read_file(char *file_name)
{
	int fd;
	char *str;
	int offset;

	str = NULL;
	if ((fd = open(file_name, O_RDONLY)) < 0)
        ft_error(0, "BUG OPEN FILE");
	offset = lseek(fd, 0, SEEK_END);
	if (!(str = ft_strnew(offset)))
		ft_error(0, "MALLOC FAIL");
	lseek(fd, 0, SEEK_SET);
	if (read(fd, str, offset) < 0)
		ft_error(0, "READ FAIL");
	ft_printf("%s\n", str);
	close(fd);
	return (str);
}

int main(int argc, char **argv)
{
	t_champ	champ;

    if (argc != 2)
        ft_error(0, "USAGE");
	champ.file = read_file(argv[1]);
    new_champ(&champ);
}
