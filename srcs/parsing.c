/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:45:43 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/12 13:27:32 by Adeline          ###   ########.fr       */
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
			return (0);
		i++;
	}
	if (i != n)
		return (0);
	return (1);
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
			(*all)->state = END;
			map_error(all);
			return (NO_ERR);
		}
		free(line);
		ft_parsing(all);
	}
	else if (line[0] != 0 && (*all)->state == END)
		ft_error(all, line, PARS_ERR);
	else
		process[(*all)->state](line, all);
	return (NO_ERR);
}

int		open_f(char *arg, t_all **all, int save)
{
	if (!((*all) = (t_all *)malloc(sizeof(t_all))))
		ft_error(all, NULL, MAL_ERR);
	init_all(all);
	(*all)->save = save;
	if (((*all)->fd = open(arg, O_RDONLY)) == -1)
		ft_error(all, NULL, FILE_ERR);
	ft_parsing(all);
	close((*all)->fd);
	return (NO_ERR);
}