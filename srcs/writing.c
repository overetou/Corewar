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
#include <asm.h>

void    write_bin(unsigned int to_write, int fd, int len)
{
    int test;

    if (len)
    {
        write_bin((to_write / 256), fd, --len);
        test = to_write % 256;
        write(fd, &test, 1);
    }
}

int		get_cmd_size(t_cmd *cmd)
{
	int		count;
	t_param	*digger;

	count = 1;
	digger = cmd->param;
	while (digger)
	{
		count += digger->nbr_octet;
		digger = digger->next;
	}
	return (count);
}

void    print_label(t_cmd *current, t_param *p, t_label *lab, int fd)
{
    t_cmd   *digger;
    t_cmd   *floor;
    int     count;
	int		sign;

    lab = find_lab(lab, p->label);
    if (lab->cmd->index > current->index)
    {
        digger = current;
        floor = lab->cmd;
		sign = 1;
    }
    else
    {
        digger = lab->cmd;
        floor = current;
		sign = -1;
    }
    while (digger != floor)
	{
		count += get_cmd_size(digger) * sign;
		digger = digger->next;
	}
	write_bin(count, fd, p->nbr_octet);
}

int main()
{
    int fd;
    unsigned int test;

    fd = open("exemple.txt", O_WRONLY);
    write_bin( -1, fd, 2);
    close(fd);
    return (0);
}
