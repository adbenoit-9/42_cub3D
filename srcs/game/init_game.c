/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:27:48 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/01 18:36:17 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_game(t_game **game)
{
	int i;

	(*game)->ret = 1;
	(*game)->state = INFO;
	(*game)->r[X] = -1;
	(*game)->r[Y] = -1;
	(*game)->c = -1;
	(*game)->f = -1;
	(*game)->map_size = 0;
	(*game)->map = NULL;
	(*game)->player.start_pos = 0;
	(*game)->wall.dist = NULL;
	(*game)->win = NULL;
	(*game)->img.ptr = NULL;
	if (!((*game)->path = malloc(sizeof(char *) * 6)))
		exit_error(game, NULL, MAL_ERR);
	i = -1;
	while (++i < 6)
		(*game)->path[i] = NULL;
	i = -1;
	while (++i < 4)
		(*game)->text.ptr[i] = NULL;
	init_sprite(game);
}

void		finish_init(t_game **game, t_sprite *sp)
{
	int i;

	if (!((*game)->wall.dist = malloc(sizeof(double) * (*game)->r[X])))
		exit_error(game, NULL, MAL_ERR);
	if (!(sp->pos = malloc(sizeof(double *) * sp->count)))
		exit_error(game, NULL, MAL_ERR);
	if (!(sp->dist = malloc(sizeof(double) * sp->count)))
		exit_error(game, NULL, MAL_ERR);
	i = 0;
	while (i < sp->count)
	{
		if (!(sp->pos[i] = malloc(sizeof(double) * 2)))
			exit_error(game, NULL, MAL_ERR);
		i++;
	}
}
