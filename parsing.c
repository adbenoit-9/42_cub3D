/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:45:43 by adbenoit          #+#    #+#             */
/*   Updated: 2020/03/11 19:23:07 by adbenoit         ###   ########.fr       */
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
	static t_function	process[2] = {info, map};

	line = NULL;
	if ((*all)->ret == 0)
		return (0);
	(*all)->ret = get_next_line((*all)->fd, &line);
	if ((*all)->i_map == END_MAP && line[0] == 0)
		return (ft_error(all, line, PARS_ERR));
	else if (line[0] == 0)
	{
		if ((*all)->i_map > 0)
		{
			(*all)->state = END;
			if (map_error(all, line) != NO_ERR)
				return (0);
		}
		free(line);
		ft_parsing(all);
	}
	else if (line[0] != 0 && (*all)->state == END)
		return (ft_error(all, line, PARS_ERR));
	else
		process[(*all)->state](line, all);
	return (0);
}

int		open_f(char *arg, t_all **all, int save)
{
	int	i;

	if (!((*all) = (t_all *)malloc(sizeof(t_all))))
		return (PARS_ERR);
	(*all)->save = save;
	(*all)->ret = 1;
	(*all)->i_map = 0;
	(*all)->err = NO_ERR;
	(*all)->state = INFO;
	(*all)->pos = 0;
	if (!((*all)->info = malloc(sizeof(char *) * (NB_INFO + 1))))
		return (PARS_ERR);
	i = 0;
	(*all)->map = 0;
	(*all)->r[0] = -1;
	(*all)->r[1] = -1;
	(*all)->c = -1;
	(*all)->f = -1;
	(*all)->sp.count = 0;
	(*all)->sp.pos = NULL;
	(*all)->sp.coor = NULL;
	while (i <= NB_INFO)
	{
		(*all)->info[i] = 0;
		i++;
	}
	if (((*all)->fd = open(arg, O_RDONLY)) == -1)
		return (ft_error(all, NULL, FILE_ERR));
	ft_parsing(all);
	close((*all)->fd);
	return (1);
}