/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:25:09 by pkeita            #+#    #+#             */
/*   Updated: 2018/04/12 16:25:10 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dasm.h>

void		ft_fill_cmd(t_env *e, int fd)
{
	int		i;
	t_cmd	*t;

	t = e->cmd;
	ft_dprintf(fd, ".name           \"%s\"\n.comment        \"%s\"\n\n",
		e->name, e->comment);
	while (t)
	{
		i = 0;
		ft_dprintf(fd, "\t%s\t", t->op->short_name);
		while (i < t->index)
		{
			if (t->param[i].code == REG_CODE)
				ft_dprintf(fd, "r%d", t->param[i].value);
			else if (t->param[i].code == DIR_CODE && t->param[i].nbr_octet == 2)
				ft_dprintf(fd, "%c%hd", DIRECT_CHAR, t->param[i].value);
			else if (t->param[i].code == DIR_CODE && t->param[i].nbr_octet == 4)
				ft_dprintf(fd, "%c%d", DIRECT_CHAR, t->param[i].value);
			else if (t->param[i].code == IND_CODE)
				ft_dprintf(fd, "%hd", t->param[i].value);
			++i != t->index ? write(fd, ", ", 2) : 0;
		}
		write(fd, "\n", 1);
		t = t->next;
	}
}

void		ft_creat_fill_file(t_env *e, char *file_name, int len, int arg)
{
	int		fd;
	char	*new_file_name;
	int		i;

	i = 0;
	while (file_name[i])
		i++;
	while (i > 0 && file_name[i - 1] != '/')
		i--;
	mkdir("dasm_champion", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	file_name[len - 2] = 's';
	len = ft_strlen(file_name + i) + 11;
	if (!(new_file_name = ft_strnew(len + 1)))
		ft_error(e, "Malloc failed");
	new_file_name = ft_strcat(new_file_name, "dasm_champion/");
	new_file_name = ft_strncat(new_file_name, file_name + i, len - 13);
	if ((fd = open(new_file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644)) < 0)
		ft_error(e, "Open failed");
	ft_fill_cmd(e, fd);
	if (close(fd))
		ft_error(e, "Close failed");
	ft_printf("\x1b[32m%d: Succefully created :%s\n\x1b[0m",
				arg, new_file_name);
	free(new_file_name);
}
