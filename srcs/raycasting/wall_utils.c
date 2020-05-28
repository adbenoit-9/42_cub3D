/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:21:05 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/28 16:23:55 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_wall(t_all **all, t_wall *wall)
{
	wall->pos[X] = (int)(*all)->player.map[X];
	wall->pos[Y] = (int)(*all)->player.map[Y];
	wall->camx = 2 * (*all)->screen.column / (double)((*all)->r[X]) - 1;
	wall->raydir[X] = (*all)->player.dir[X] + (*all)->screen.plane[X] * wall->camx;
	wall->raydir[Y] = (*all)->player.dir[Y] + (*all)->screen.plane[Y] * wall->camx;
	wall->delta_dist[X] = (wall->raydir[Y] == 0) ? 0 : (wall->raydir[X] == 0) ? 1 : fabs(1.0 / wall->raydir[X]);
	wall->delta_dist[Y] = (wall->raydir[X] == 0) ? 0 : (wall->raydir[Y] == 0) ? 1 :fabs(1.0 / wall->raydir[Y]);
}

double set_wall_dist(t_all **all, t_wall *wall)
{
	if (wall->side % 2 == 0)
		return ((wall->pos[X] - (*all)->player.map[X] + (1 - wall->step[X]) / 2) / wall->raydir[X]);
	else
		return ((wall->pos[Y] - (*all)->player.map[Y] + ((1 - wall->step[Y]) / 2)) / wall->raydir[Y]);
}

void set_side_dist(t_all **all, t_wall *wall)
{
	if (wall->raydir[X] < 0)
	{
		wall->step[X] = -1;
		wall->side_dist[X] = ((*all)->player.map[X] - wall->pos[X]) * wall->delta_dist[X];
	}
	else
	{
		wall->step[X] = 1;
		wall->side_dist[X] = (wall->pos[X] + 1.0 - (*all)->player.map[X]) * wall->delta_dist[X];
	}
	if (wall->raydir[Y] < 0)
	{
		wall->step[Y] = -1;
		wall->side_dist[Y] = ((*all)->player.map[Y] - wall->pos[Y]) * wall->delta_dist[Y];
	}
	else
	{
		wall->step[Y] = 1;
		wall->side_dist[Y] = (wall->pos[Y] + 1.0 - (*all)->player.map[Y]) * wall->delta_dist[Y];
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
			if ((*all)->wall.pos[X] < (*all)->player.map[X])
				(*all)->wall.side = 0;
			else
				(*all)->wall.side = 2;	
		}
		else
		{
			(*all)->wall.side_dist[Y] += (*all)->wall.delta_dist[Y];
			(*all)->wall.pos[Y] += (*all)->wall.step[Y];
			if ((*all)->wall.pos[Y] < (*all)->player.map[Y])
				(*all)->wall.side = 1;
			else
				(*all)->wall.side = 3;
		}
		if ((*all)->map[(int)(*all)->wall.pos[Y]][(int)(*all)->wall.pos[X]] == WALL)
			hit = 1;
	}
}