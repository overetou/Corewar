/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_writing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:58:53 by overetou          #+#    #+#             */
/*   Updated: 2018/04/25 18:24:15 by ysingaye         ###   ########.fr       */
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

t_cmd	*ft_get_cmd_index(t_cmd *cmd, int index)
{
	while (cmd)
	{
		if (cmd->index == index)
			return (cmd);
		cmd = cmd->next;
	}
	return (cmd);
}

void	print_label(t_cmd *current, t_param *p, t_label *lab, t_champ *champ)
{
	t_cmd	*digger;
	t_cmd	*ground;
	int		count;
	int		sign;

	lab = find_label(champ, lab, p->label);
	if (lab->cmd == NULL)
		lab->cmd = ft_get_cmd_index(champ->cmd, lab->index);
	if (lab->index > current->index && (digger = current))
		ground = lab->cmd;
	else
	{
		digger = lab->cmd;
		ground = current;
	}
	sign = ((lab->index > current->index) ? 1 : -1);
	count = 0;
	while (digger != ground)
	{
		count += get_cmd_size(digger) * sign;
		digger = digger->next;
	}
	write_bin(count, champ->fd, p->nbr_octet);
}
