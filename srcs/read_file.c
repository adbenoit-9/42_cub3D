/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 16:13:17 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/05 16:13:18 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_file(char *arg, t_all **all, int save)
{
	if (!((*all) = (t_all *)malloc(sizeof(t_all))))
		exit_error(all, NULL, MAL_ERR);
	init_game(all);
	(*all)->save = save;
	if (((*all)->fd = open(arg, O_RDONLY)) == -1)
		exit_error(all, NULL, FILE_ERR);
	read_file(all);
	close((*all)->fd);
	return (NO_ERR);
}

int	read_file(t_all **all)
{
	char				*line;
	static t_function	process[3] = {parse_info, parse_bonus, parse_map};

	line = NULL;
	(*all)->ret = get_next_line((*all)->fd, &line);
	if (line[0] == 0)
	{
		if ((*all)->ret == 0 || (*all)->state == MAP)
		{
			(*all)->state = END;
			check_map_end(all, (*all)->map, (*all)->map_size);
			if ((*all)->ret == 0)
			{
				free(line);
				return (NO_ERR);
			}
		}
		free(line);
		read_file(all);
	}
	else if (line[0] != 0 && (*all)->state == END)
		exit_error(all, line, MAP_ERR);
	else
		process[(*all)->state](line, all);
	return (NO_ERR);
}
