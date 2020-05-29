/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:21:05 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/29 17:14:28 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_wall(t_all **all, t_wall *w)
{
	w->pos[X] = (int)(*all)->player.map[X];
	w->pos[Y] = (int)(*all)->player.map[Y];
	w->camx = 2 * (*all)->screen.column / (double)((*all)->r[X]) - 1;
	w->raydir[X] = (*all)->player.dir[X] + (*all)->screen.plane[X] * w->camx;
	w->raydir[Y] = (*all)->player.dir[Y] + (*all)->screen.plane[Y] * w->camx;
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

double	set_wall_dist(t_all **all, t_wall *w)
{
	if (w->side % 2 == 0)
		return ((w->pos[X] - (*all)->player.map[X] + (1 - w->step[X]) / 2)
				/ w->raydir[X]);
	else
		return ((w->pos[Y] - (*all)->player.map[Y] + ((1 - w->step[Y]) / 2))
				/ w->raydir[Y]);
}

void	set_side_dist(t_all **all, t_wall *w)
{
	if (w->raydir[X] < 0)
	{
		w->step[X] = -1;
		w->side_dist[X] = ((*all)->player.map[X] - w->pos[X]) *
						w->delta_dist[X];
	}
	else
	{
		w->step[X] = 1;
		w->side_dist[X] = (w->pos[X] + 1.0 - (*all)->player.map[X]) *
						w->delta_dist[X];
	}
	if (w->raydir[Y] < 0)
	{
		w->step[Y] = -1;
		w->side_dist[Y] = ((*all)->player.map[Y] - w->pos[Y]) *
						w->delta_dist[Y];
	}
	else
	{
		w->step[Y] = 1;
		w->side_dist[Y] = (w->pos[Y] + 1.0 - (*all)->player.map[Y]) *
						w->delta_dist[Y];
	}
}

void	set_wall_side(t_all **all)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if ((*all)->wall.side_dist[X] < (*all)->wall.side_dist[Y])
		{
			(*all)->wall.side_dist[X] += (*all)->wall.delta_dist[X];
			(*all)->wall.pos[X] += (*all)->wall.step[X];
			(*all)->wall.side = (*all)->wall.pos[X]
							< (*all)->player.map[X] ? 0 : 2;
		}
		else
		{
			(*all)->wall.side_dist[Y] += (*all)->wall.delta_dist[Y];
			(*all)->wall.pos[Y] += (*all)->wall.step[Y];
			(*all)->wall.side = (*all)->wall.pos[Y]
							< (*all)->player.map[Y] ? 1 : 3;
		}
		if ((*all)->map[(int)(*all)->wall.pos[Y]]
				[(int)(*all)->wall.pos[X]] == WALL)
			hit = 1;
	}
}
