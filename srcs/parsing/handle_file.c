/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 16:13:17 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/02 14:04:31 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_file(t_game **game)
{
	char				*line;
	static t_function	process[3] = {parse_info, parse_map};

	line = NULL;
	(*game)->ret = get_next_line((*game)->fd, &line);
	if (line[0] == 0)
	{
		if ((*game)->ret == 0 || (*game)->state == MAP)
		{
			(*game)->state = END;
			if ((*game)->ret == 0)
			{
				free(line);
				return (NO_ERR);
			}
		}
		free(line);
		read_file(game);
	}
	else if (line[0] != 0 && (*game)->state == END)
		exit_error(game, line, MAP_ERR);
	else
		process[(*game)->state](line, game);
	return (NO_ERR);
}

int	parse_file(char *arg, t_game **game, int save)
{
	if (!((*game) = (t_game *)malloc(sizeof(t_game))))
		exit_error(game, NULL, MAL_ERR);
	init_game(game);
	(*game)->save = save;
	if (((*game)->fd = open(arg, O_RDONLY)) == -1)
		exit_error(game, NULL, FILE_ERR);
	read_file(game);
	close((*game)->fd);
	return (NO_ERR);
}
