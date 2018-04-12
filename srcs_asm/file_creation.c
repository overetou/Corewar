/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:20:09 by overetou          #+#    #+#             */
/*   Updated: 2018/04/12 15:25:34 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		create_cor_file(char *file_name)
{
	int		fd;
	char	*name;
	int		name_size;

	name_size = ft_strlen(file_name) + 2;
	name = ft_strnew(name_size);
	ft_strncpy(name, file_name, name_size - 4);
	ft_strcpy(name + name_size - 4, ".cor");
	fd = open(name, O_TRUNC | O_CREAT | O_WRONLY, 0600);
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
	while (param)
	{
		if (param->label)
			print_label(cmd, param, champ->label, fd);
		else
			write_bin(param->value, fd, param->nbr_octet);
		param = param->next;
	}
}

void	print_cmd(int fd, t_cmd *cmd, t_champ *champ)
{
	while (cmd)
	{
		ft_putchar_fd(cmd->op->opcode, fd);
		if (cmd->op->has_ocp)
			write_bin(assemble_ocp(cmd), fd, 1);
		print_params(cmd->param, cmd, fd, champ);
		cmd = cmd->next;
	}
}

void	manage_file_creation(t_champ *champ, char *filename)
{
	int		fd;
	char	*tmp;

	fd = create_cor_file(filename);
	print_header(fd, champ);
	print_cmd(fd, champ->cmd, champ);
	tmp = ft_strsub(filename, 0, ft_strlen(filename) - 2);
	ft_printf("\x1b[32mWriting output program to %s.cor\n\x1b[0m", tmp);
	free(tmp);
	close(fd);
}
