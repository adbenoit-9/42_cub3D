/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 23:52:05 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/28 21:13:36 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int  parse_bonus(char *line, t_all **all, int i)
{
    int j;

	j = 0; 
	if (!((*all)->bonus.path[i] = malloc(sizeof(char) * (ft_strlen(line) + 1))))
		exit_error(all, line, MAL_ERR);
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
	static char *str_info[NB_BON] = {BON_W0, BON_W1, BON_W2, BON_W3, BON_S1,
					BON_SA, BON_DN, BON_DS, BON_DE, BON_DW, BON_LIFE, BON_LOSE, BON_WIN};
	int			i;

	i = 0;
	while (i < NB_BON)
	{
		if (ft_strncmp(str_info[i], line, 3) == TRUE)
		{
			line = ft_strtrim(line, " ", 3);
			return (parse_bonus(line, all, i));
		}
		i++;
	}
	i = 0;
	while (i < NB_BON)
	{
		if ((*all)->bonus.path[i] == NULL)
			exit_error(all, line, IMG_ERR);
		i++;
	}
	(*all)->state = MAP;
	return (map(line, all));
}

void 	check_door(t_all **all)
{
	int	i;
	int	j;

	i = 0;
	while ((*all)->map[i])
	{
		j = 0;
		while ((*all)->map[i][j])
		{
			if ((*all)->map[i][j] == DOOR)
			{
				if (((*all)->map[i - 1][j] != WALL || (*all)->map[i + 1][j] != WALL) &&
								((*all)->map[i][j - 1] != WALL || (*all)->map[i][j + 1] != WALL))
					exit_error(all, NULL, MAP_ERR);
			}
			j++;
		}
		i++;
	}
}