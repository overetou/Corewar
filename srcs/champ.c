/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:58:57 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/21 16:40:14 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

int		set_champ_name_comment(t_champ *champ, char **line, char *str)
{
	char	*name;
	int 	i;

	name = NULL;
	if (!ft_strncmp(*line, str, ft_strlen(str)))
	{
		i = ft_strlen(str);
		while (ft_isblank((*line)[i]))
			++i;
		//ft_printf(ft_strcspn((*line) + i + 1, "\""));
		name = ft_strsub(*line, i + 1, ft_strcspn((*line) + i + 1, "\""));
	}
	if (!name)
		return (0);
	else if (ft_strequ(str, NAME_CMD_STRING))
		champ->name = name;
	else if (ft_strequ(str, COMMENT_CMD_STRING))
		champ->comment = name;
	return (1);
}

int		add_champ_name_comment(t_champ *champ, int fd, char **line)
{
	int nbr_line;
	int find;
	char	*tmp;

	nbr_line = 0;
	while (get_next_line(fd, line) > 0)
	{
		tmp = *line;
		*line = ft_strtrim(tmp);
		ft_strdel(&tmp);
		find = 0;
		nbr_line++;
		if (champ->name && (find =
			set_champ_name_comment(champ, line, NAME_CMD_STRING)))
			ft_error(nbr_line, *line);
		if (!find && champ->comment && (find =
			set_champ_name_comment(champ, line, COMMENT_CMD_STRING)))
			ft_error(nbr_line, *line);
		if (!find && !ft_strchr("#\0", **line))
			ft_error(nbr_line, *line);
		ft_strdel(line);
		if (champ->name && champ->comment)
			break ;
	}
	return (nbr_line);
}


// void	add_champ_cmd(t_champ *champ, int fd, char **line)
// {
//
// }

t_champ	*new_champ(t_champ *champ)
{
	int nbr_line;

	if (!(champ = (t_champ*)malloc(sizeof(t_champ))))
		exit (0);
	champ->name = NULL;
	champ->comment = NULL;
	champ->cmd = NULL;
	champ->label = NULL;
	nbr_line = add_champ_name_comment(champ);
	if (!champ->name || !champ->comment)
		ft_error(nbr_line, line);
	ft_printf("%s\n%s\n%s\n", champ->name, champ->comment, line);
	//add_champ_cmd(champ, fd, &line);
	return (NULL);
}
