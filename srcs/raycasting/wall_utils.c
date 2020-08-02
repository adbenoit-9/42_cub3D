/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:21:05 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/16 19:50:07 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_wall(t_game **game, t_wall *w)
{
	w->pos[X] = (int)(*game)->player.pos[X];
	w->pos[Y] = (int)(*game)->player.pos[Y];
	w->camx = 2 * (*game)->screen.x / (double)((*game)->r[X]) - 1;
	w->raydir[X] = (*game)->player.dir[X] + (*game)->screen.plane[X] * w->camx;
	w->raydir[Y] = (*game)->player.dir[Y] + (*game)->screen.plane[Y] * w->camx;
	w->delta_dist[X] = 0;
	if (w->raydir[Y] != 0)
	{
		if (w->raydir[X] == 0)
			w->delta_dist[X] = 1;
		else
			w->delta_dist[X] = fabs(1.0 / w->raydir[X]);
	}
	w->delta_dist[Y] = 0;
	if (w->raydir[X] != 0)
	{
		if (w->raydir[Y] == 0)
			w->delta_dist[Y] = 1;
		else
			w->delta_dist[Y] = fabs(1.0 / w->raydir[Y]);
	}
}

double	set_wall_dist(t_game **game, t_wall *w)
{
	if (w->side % 2 == 0)
		return ((w->pos[X] - (*game)->player.pos[X] + (1 - w->step[X]) / 2)
				/ w->raydir[X]);
	else
		return ((w->pos[Y] - (*game)->player.pos[Y] + ((1 - w->step[Y]) / 2))
				/ w->raydir[Y]);
}

void	set_side_dist(t_game **game, t_wall *w)
{
	if (w->raydir[X] < 0)
	{
		w->step[X] = -1;
		w->side_dist[X] = ((*game)->player.pos[X] - w->pos[X]) *
						w->delta_dist[X];
	}
	else
	{
		w->step[X] = 1;
		w->side_dist[X] = (w->pos[X] + 1.0 - (*game)->player.pos[X]) *
						w->delta_dist[X];
	}
	if (w->raydir[Y] < 0)
	{
		w->step[Y] = -1;
		w->side_dist[Y] = ((*game)->player.pos[Y] - w->pos[Y]) *
						w->delta_dist[Y];
	}
	else
	{
		w->step[Y] = 1;
		w->side_dist[Y] = (w->pos[Y] + 1.0 - (*game)->player.pos[Y]) *
						w->delta_dist[Y];
	}
}

void	set_wall_side(t_game **game)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if ((*game)->wall.side_dist[X] < (*game)->wall.side_dist[Y])
		{
			(*game)->wall.side_dist[X] += (*game)->wall.delta_dist[X];
			(*game)->wall.pos[X] += (*game)->wall.step[X];
			(*game)->wall.side = (*game)->wall.pos[X]
							< (*game)->player.pos[X] ? 0 : 2;
		}
		else
		{
			(*game)->wall.side_dist[Y] += (*game)->wall.delta_dist[Y];
			(*game)->wall.pos[Y] += (*game)->wall.step[Y];
			(*game)->wall.side = (*game)->wall.pos[Y]
							< (*game)->player.pos[Y] ? 1 : 3;
		}
		if ((*game)->map[(int)(*game)->wall.pos[Y]]
				[(int)(*game)->wall.pos[X]] == WALL)
			hit = 1;
	}
}
