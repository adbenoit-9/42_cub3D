/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:21:05 by adbenoit          #+#    #+#             */
/*   Updated: 2020/03/03 18:55:07 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// u et v orthogonaux ssi <u,v> = 0

void hit_wall(t_all **all)
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

double wall_dist(t_all **all)
{
	if ((*all)->wall.side % 2 == 0)
		return (((*all)->wall.pos[X] - (*all)->player.map[X] + (1 - (*all)->wall.step[X]) / 2) / (*all)->wall.raydir[X]);
	else
		return (((*all)->wall.pos[Y] - (*all)->player.map[Y] + ((1 - (*all)->wall.step[Y]) / 2)) / (*all)->wall.raydir[Y]);
}

void complete_wall_inf(t_all **all)
{
	(*all)->wall.pos[X] = (int)(*all)->player.map[X];
	(*all)->wall.pos[Y] = (int)(*all)->player.map[Y];
	(*all)->wall.camx = 2 * (*all)->grid.column / (double)((*all)->r[X]) - 1;
	(*all)->wall.raydir[X] = (*all)->player.dir[X] + (*all)->grid.plane[X] * (*all)->wall.camx;
	(*all)->wall.raydir[Y] = (*all)->player.dir[Y] + (*all)->grid.plane[Y] * (*all)->wall.camx;
	(*all)->wall.delta_dist[X] = ((*all)->wall.raydir[Y] == 0) ? 0 : ((*all)->wall.raydir[X] == 0) ? 1 : fabs(1.0 / (*all)->wall.raydir[X]);
	(*all)->wall.delta_dist[Y] = ((*all)->wall.raydir[X] == 0) ? 0 : ((*all)->wall.raydir[Y] == 0) ? 1 :fabs(1.0 / (*all)->wall.raydir[Y]);
}

void side_dist(t_all **all)
{
	if ((*all)->wall.raydir[X] < 0)
	{
		(*all)->wall.step[X] = -1;
		(*all)->wall.side_dist[X] = ((*all)->player.map[X] - (*all)->wall.pos[X]) * (*all)->wall.delta_dist[X];
	}
	else
	{
		(*all)->wall.step[X] = 1;
		(*all)->wall.side_dist[X] = ((*all)->wall.pos[X] + 1.0 - (*all)->player.map[X]) * (*all)->wall.delta_dist[X];
	}
	if ((*all)->wall.raydir[Y] < 0)
	{
		(*all)->wall.step[Y] = -1;
		(*all)->wall.side_dist[Y] = ((*all)->player.map[Y] - (*all)->wall.pos[Y]) * (*all)->wall.delta_dist[Y];
	}
	else
	{
		(*all)->wall.step[Y] = 1;
		(*all)->wall.side_dist[Y] = ((*all)->wall.pos[Y] + 1.0 - (*all)->player.map[Y]) * (*all)->wall.delta_dist[Y];
	}
}