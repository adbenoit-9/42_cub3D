/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:21:57 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/10 15:19:48 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	add_info(char *line, t_all **all, int i)
{
	int j;

	j = 0; 
	if (!((*all)->info[i] = malloc(sizeof(char) * (ft_strlen(line) + 1))))
		ft_error(all, line, PARS_ERR);
	while (line[j])
	{
		(*all)->info[i][j] = line[j];
		j++;
	}
	(*all)->info[i][j] = 0;
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
		if (ft_strncmp(str_info[i], line, size) == 1 && (*all)->info[i] == 0)
		{
			line = ft_strtrim(line, " ", size);
			if (i < 5)
				return (add_info(line, all, i));
			else if (i == 5)
				return (add_r(all, line));
			else
				return (add_col(all, line, i));
		}
	}
	i = -1;
	while (++i < 5)
	{
		if ((*all)->info[i] == NULL)
			ft_error(all, line, PARS_ERR);
	}
	(*all)->state = MAP;
	return (map(line, all));
}
