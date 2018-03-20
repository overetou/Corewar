/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:58:57 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/20 20:44:22 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// void	add_champ_name(t_champ *champ, int fd, char **line)
// {
// 	char *trim;
//
// 	trim = NULL;
// 	while (get_next_line(fd, line) > 0)
// 	{
// 		trim = ft_strtrim(*line);
// 		ft_strdel(line);
// 		if (!ft_strncmp(trim, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
// 		{
// 			if (champ->name)
// 				exit(0);
// 			if (trim[ft_strlen(trim) - 1] != '"')
// 				exit(0);
// 			champ->name = ft_strndup(trim + 7 + ft_strlen(), (ft_strlen(trim + 7) - 1));
// 		}
// 		else if (!ft_strncmp(trim, ".comment \"", 10))
// 		{
// 			if (champ->comment)
// 				exit(0);
// 			if (trim[ft_strlen(trim) - 1] != '"')
// 				exit(0);
// 			champ->comment = ft_strndup(trim + 10, (ft_strlen(trim + 10) - 1));
// 		}
// 		else if (*trim == COMMENT_CHAR)
// 			continue ;
// 		else if (*trim && (!champ->comment || !champ->name))
// 			exit(0);
// 		else if (!ft_strequ(trim, ""))
// 			break ;
// 		ft_strdel(&trim);
// 	}
// 	*line = trim;
// }

void	add_champ_name(t_champ *champ, int fd, char **line)
{
	int i;

	while (get_next_line(fd, line) > 0)
	{
		i = 0;
		while (ft_isblank((*line)[i]))
			++i;
		if (!ft_strncmp((*line) + i, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		{
			i += ft_strlen(NAME_CMD_STRING);
			while (ft_isblank((*line)[i]))
				++i;
			champ->name = ft_strndup((*line) + i + 1, ft_strlen((*line) + i + 1) - 1);
		}
		else if (!ft_strncmp((*line) + i, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		{
			i += ft_strlen(COMMENT_CMD_STRING);
			while (ft_isblank((*line)[i]))
				++i;
			champ->comment = ft_strndup((*line) + i + 1, ft_strlen((*line) + i + 1) - 1);
		}
		else if (!ft_strchr("#\0", (*line)[i]))
		{
			ft_printf("%s\n", *line);
			exit (0);
		}
		ft_strdel(line);
		if (champ->name && champ->comment)
			break ;
	}
}


// void	add_champ_cmd(t_champ *champ, int fd, char **line)
// {
//
// }

t_champ	*new_champ(int fd)
{
	char *line;
	t_champ	*champ;

	if (!(champ = (t_champ*)malloc(sizeof(t_champ))))
		exit (0);
	champ->name = NULL;
	champ->comment = NULL;
	champ->cmd = NULL;
	champ->label = NULL;
	line = NULL;
	add_champ_name(champ, fd, &line);
	ft_printf("%s\n%s\n%s\n", champ->name, champ->comment, line);
	//add_champ_cmd(champ, fd, &line);
	return (NULL);
}
