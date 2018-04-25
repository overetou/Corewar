/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:20:09 by overetou          #+#    #+#             */
/*   Updated: 2018/04/25 18:17:05 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		create_cor_file(t_champ *champ, char *file_name)
{
	int		fd;
	char	*name;
	int		name_size;

	name_size = ft_strlen(file_name) + 2;
	name = ft_strnew(name_size);
	ft_strncpy(name, file_name, name_size - 4);
	ft_strcpy(name + name_size - 4, ".cor");
	if ((fd = open(name, O_TRUNC | O_CREAT | O_WRONLY, 0600)) < 0)
	{
		free(name);
		ft_error(champ, "Open fail");
	}
	free(name);
	return (fd);
}

void	print_header(int fd, t_champ *champ)
{
	write_bin(COREWAR_EXEC_MAGIC, fd, 4);
	ft_putstr_fd(champ->name, fd);
	write_bin(0, fd, PROG_NAME_LENGTH + 4 - ft_strlen(champ->name));
	write_bin(champ->file_size, fd, 4);
	ft_putstr_fd(champ->comment, fd);
	write_bin(0, fd, COMMENT_LENGTH + 4 - ft_strlen(champ->comment));
}

void	print_params(t_param *param, t_cmd *cmd, int fd, t_champ *champ)
{
	t_param *tmp;

	tmp = param;
	while (tmp)
	{
		if (tmp->label)
			print_label(cmd, tmp, champ->label, champ);
		else
			write_bin(tmp->value, fd, tmp->nbr_octet);
		tmp = tmp->next;
	}
}

void	print_cmd(int fd, t_cmd *cmd, t_champ *champ)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		ft_putchar_fd(tmp->op->opcode, fd);
		if (tmp->op->has_ocp)
			write_bin(assemble_ocp(tmp), fd, 1);
		print_params(tmp->param, tmp, fd, champ);
		tmp = tmp->next;
	}
}

void	file_creation(t_champ *champ, char *filename)
{
	char	*tmp;

	champ->fd = create_cor_file(champ, filename);
	print_header(champ->fd, champ);
	print_cmd(champ->fd, champ->cmd, champ);
	tmp = ft_strsub(filename, 0, ft_strlen(filename) - 2);
	ft_printf("\x1b[32mWriting output program to %s.cor\n\x1b[0m", tmp);
	free(tmp);
	if (close(champ->fd) < 0)
	{
		free(tmp);
		ft_error(champ, "CLOSE FAIL");
	}
}
