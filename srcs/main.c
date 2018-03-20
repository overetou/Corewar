/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:41:32 by overetou          #+#    #+#             */
/*   Updated: 2018/03/20 18:45:47 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "corewar.h"

int main(int argc, char **argv)
{
    int fd;

    if (argc < 1)
        return (0); //exit("u");
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (0); //exit("o");
    new_champ(fd);
}
