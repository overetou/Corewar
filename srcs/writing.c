/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:58:53 by overetou          #+#    #+#             */
/*   Updated: 2018/03/21 15:58:54 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void    write_bin(int to_write, int fd)
{
    int test;

    if (to_write)
    {
        write_bin((to_write / 256), fd);
        test = to_write % 256;
        write(fd, &test, 1);
    }
}

int main()
{
    int fd;

    fd = open("exemple.txt", O_WRONLY);
    write_bin(64251, fd);
    close(fd);
    return (0);
}
