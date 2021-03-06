/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:41:32 by overetou          #+#    #+#             */
/*   Updated: 2018/04/25 18:25:41 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	ft_asm(t_champ *champ)
{
	champ->name = NULL;
	champ->comment = NULL;
	champ->cmd = NULL;
	champ->label = NULL;
	champ->comment_char[0] = ';';
	champ->comment_char[1] = COMMENT_CHAR;
	champ->comment_char[2] = '\0';
	store_header(champ);
	parse_args(champ);
	if (!champ->cmd)
		ft_error(champ, "No params");
	valid_labels(champ);
}

void	read_file(t_champ *champ, char *file_name)
{
	int		fd;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		ft_error(champ, "BUG OPEN FILE");
	if (!(champ->file_len = lseek(fd, 0, SEEK_END)))
		ft_error(champ, "Empty file");
	if (!(champ->file = ft_strnew(champ->file_len)))
		ft_error(champ, "MALLOC FAIL");
	lseek(fd, 0, SEEK_SET);
	if (read(fd, champ->file, champ->file_len) < 0)
		ft_error(champ, "READ FAIL");
	if (close(fd) < 0)
		ft_error(champ, "CLOSE FAIL");
}

int		main(int argc, char **argv)
{
	t_champ	champ;
	int		arg;
	int		len;

	arg = 0;
	if (argc < 2)
	{
		ft_printf("Usage : ./asm *.s ...");
		return (0);
	}
	while (++arg < argc)
	{
		len = ft_strlen(argv[arg]) - 1;
		if (len > 1 && argv[arg][len] == 's' && argv[arg][len - 1] == '.')
		{
			ft_bzero(&champ, sizeof(champ));
			read_file(&champ, argv[arg]);
			ft_asm(&champ);
			file_creation(&champ, argv[arg]);
			free_champ(&champ);
		}
		else
			ft_printf("File %d is invalid\n", arg);
	}
	return (0);
}
