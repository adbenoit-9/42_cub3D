/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 23:52:05 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/14 19:12:24 by Adeline          ###   ########.fr       */
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
	static char *str_info[NB_BON] = {BON_P0, BON_P1, BON_P2, BON_P3, BON_P4, BON_S1, BON_SA, BON_DN, BON_DS, BON_DE, BON_DW, BON_LIFE, BON_LOSE, BON_WIN};
	int			i;

	i = 0;
	if (!((*all)->bonus.path = malloc(sizeof(char *) * (NB_BON + 1))))
		ft_error(all, NULL, MAL_ERR);
	while (i < NB_BON)
	{
		if (ft_strncmp(str_info[i], line, 3) == 1)
		{
			line = ft_strtrim(line, " ", 3);
			return (add_path(line, all, i));
		}
		i++;
	}
	(*all)->bonus.path[NB_BON] = 0;
	i = 0;
	while (i < NB_BON)
	{
		printf("-%d %s\n", NB_BON, (*all)->bonus.path[i]);
		if ((*all)->bonus.path[i] == NULL)
			ft_error(all, line, FIND_ERR);
		i++;
	}
	(*all)->state = MAP;
	return (map(line, all));
}