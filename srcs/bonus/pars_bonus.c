/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 23:52:05 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/02 23:32:36 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int  add_path(char *line, t_all **all, int i)
{
    int j;

	j = 0; 
	if (!((*all)->bonus.path[i] = malloc(sizeof(char) * (ft_strlen(line) + 1))))
		ft_error(all, line, MAL_ERR);
	while (line[j])
	{
		(*all)->bonus.path[i][j] = line[j];
		j++;
	}
	(*all)->bonus.path[i][j] = 0;
	free(line);
	return (ft_parsing(all));
}

int     bonus(char *line, t_all **all)
{
	static char *str_info[NB_BON] = {BON_P0, BON_P1, BON_P2, BON_P3, BON_P4, BON_S1, BON_SA, BON_D};
	int			i;
	int			size;

	i = 0;
	while (i < NB_BON)
	{
		size = i < 7 ? 2 : 1;
		if (ft_strncmp(str_info[i], line, size) == 1)
		{
			line = ft_strtrim(line, " ", size);
			return (add_path(line, all, i));
		}
		i++;
	}
	i = 0;
	while (i < NB_BON)
	{
		if ((*all)->bonus.path[i] == NULL)
			ft_error(all, line, PARS_ERR);
		i++;
	}
	(*all)->state = MAP;
	return (map(line, all));
}