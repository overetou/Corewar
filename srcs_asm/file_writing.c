/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_writing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:58:53 by overetou          #+#    #+#             */
/*   Updated: 2018/04/18 18:10:37 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	write_bin(unsigned int to_write, int fd, int len)
{
	int c;

	if (len)
	{
		write_bin((to_write / 256), fd, --len);
		c = to_write % 256;
		write(fd, &c, 1);
	}
}

int		get_cmd_size(t_cmd *cmd)
{
	int		count;
	t_param	*digger;

	count = 1;
	if (cmd == NULL)
		return (1);
	digger = cmd->param;
	if (cmd->op->has_ocp)
		count++;
	while (digger)
	{
		count += digger->nbr_octet;
		digger = digger->next;
	}
	return (count);
}

void	print_label(t_cmd *current, t_param *p, t_label *lab, int fd)
{
	t_cmd	*digger;
	t_cmd	*floor;
	int		count;
	int		sign;

	count = 0;
	lab = find_label(lab, p->label);
	if (lab->cmd == NULL)
	{
		digger = current;
		floor = lab->cmd;
		sign = 1;
	}
	if (lab->cmd && (lab->cmd->index > current->index))
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
	if (digger == NULL)
		count += get_cmd_size(digger) * sign;
	while (digger && digger != floor)
	{
		count += get_cmd_size(digger) * sign;
		digger = digger->next;
	}
	write_bin(count, fd, p->nbr_octet);
}
