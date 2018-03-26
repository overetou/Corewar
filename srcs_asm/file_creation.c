/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:20:09 by overetou          #+#    #+#             */
/*   Updated: 2018/03/22 15:20:10 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		create_cor_file(char *file_name)
{
    int		fd;
    char	*name;
    int		name_size;

	name_size = 0;
	while (file_name[name_size + 3] != '.')
		name_size++;
	name = ft_strnew(name_size);
	ft_strncpy(name, file_name, name_size);
	ft_strcpy(name + name_size, "cor");
	fd = open(name, O_TRUNC | O_CREAT | O_RDWR, 777);
	return (fd);
}

void	print_header(int fd, t_champ *champ)
{
	write_bin(COREWAR_EXEC_MAGIC, 4);
	ft_putstr_fd(champ->name, fd);
	write_bin(0, fd, PROG_NAME_LENGTH - ft_strlen(champ->name) + 4);
	ft_putstr_fd(champ->comment, fd);
	write_bin(0, fd, COMMENT_LENGTH - ft_strlen(champ->comment));
}

void	print_params(t_param *param, t_cmd *cmd, int fd)
{
	while (param)
	{
		if (param->label)
			print_label(cmd, param, param->label, fd);
		else
			write_bin(param->value, param->nbr_octet);
		param = param->next;
	}
}

void	print_cmd(int fd, t_champ *champ, t_cmd *cmd)
{
	while (cmd)
	{
		ft_putchar_fd(cmd->op->opcode, fd);
		if (cmd->op->has_ocp)
			write_bin(assemble_ocp(cmd), fd);
		print_params(cmd->param, cmd, fd);
		cmd = cmd->next;
	}
}

void	manage_file_creation(t_champ *champ)
{
	int	fd;

	fd = create_core_file(champ->file);
	print_header(fd, champ);
	print_cmd(fd, champ, champ->cmd);
	close(fd);
}
