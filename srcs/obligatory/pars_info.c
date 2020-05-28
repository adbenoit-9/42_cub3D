/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:21:57 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/28 14:19:49 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_path(char *line, t_all **all, int i)
{
	int j;

	j = 0; 
	if ((*all)->path[i])
		exit_error(all, line, IMG_ERR);
	if (!((*all)->path[i] = malloc(sizeof(char) * (ft_strlen(line) + 1))))
		exit_error(all, line, IMG_ERR);
	while (line[j])
	{
		(*all)->path[i][j] = line[j];
		j++;
	}
	(*all)->path[i][j] = 0;
	free(line);
	return (ft_parsing(all));
}

int	info(char *line, t_all **all)
{
	static char *str_info[NB_INFO] = {INF_EA, INF_SO, INF_WE, INF_NO, INF_S, INF_R, INF_F, INF_C};
	int			i;
	int			size;

	i = -1;
	while (++i < NB_INFO)
	{
		size = i < 4 ? 3 : 2;
		if (ft_strncmp(str_info[i], line, size) == TRUE)
		{
			line = ft_strtrim(line, " ", size);
			if (i < 5)
				return (parse_path(line, all, i));
			else if (i == 5)
				return (parse_res(all, line));
			else
				return (parse_color(all, line, i));
		}
	}
	i = -1;
	while (++i < 5)
	{
		if ((*all)->path[i] == NULL)
			exit_error(all, line, IMG_ERR);
	}
	(*all)->state = MAP;
	return (map(line, all));
}
