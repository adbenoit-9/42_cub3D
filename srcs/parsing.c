/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:45:43 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/28 14:46:03 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (FALSE);
		i++;
	}
	if (i != n)
		return (FALSE);
	return (TRUE);
}

int		ft_parsing(t_all **all)
{
	char				*line;
	static t_function	process[3] = {info, bonus, map};

	line = NULL;
	(*all)->ret = get_next_line((*all)->fd, &line);
	if (line[0] == 0)
	{
		if ((*all)->ret == 0)
		{
			free(line);
			(*all)->state = END;
			check_line_border(all);
			return (NO_ERR);
		}
		free(line);
		ft_parsing(all);
	}
	else if (line[0] != 0 && (*all)->state == END)
		exit_error(all, line, MAP_ERR);
	else
		process[(*all)->state](line, all);
	return (NO_ERR);
}

int		open_f(char *arg, t_all **all, int save)
{
	if (!((*all) = (t_all *)malloc(sizeof(t_all))))
		exit_error(all, NULL, MAL_ERR);
	init_game(all);
	(*all)->save = save;
	if (((*all)->fd = open(arg, O_RDONLY)) == -1)
		exit_error(all, NULL, FILE_ERR);
	ft_parsing(all);
	close((*all)->fd);
	return (NO_ERR);
}