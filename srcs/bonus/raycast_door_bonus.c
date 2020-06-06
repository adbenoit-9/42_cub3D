/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_door_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:19:45 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/06 22:07:25 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static char	set_side_type(t_all **all, t_wall *wall)
{
	char type;

	type = 0;
	while (type != WALL && type != DOOR && type != O_DOOR)
	{
		if (wall->side_dist[X] < wall->side_dist[Y])
		{
			wall->side_dist[X] += wall->delta_dist[X];
			wall->pos[X] += wall->step[X];
			wall->side = wall->pos[X] < (*all)->player.pos[X] ? 0 : 2;
		}
		else
		{
			wall->side_dist[Y] += wall->delta_dist[Y];
			wall->pos[Y] += wall->step[Y];
			if (wall->pos[Y] < (*all)->player.pos[Y])
				wall->side = 1;
			else
				wall->side = 3;
		}
		type = (*all)->map[(int)wall->pos[Y]][(int)wall->pos[X]];
	}
	return (type);
}

void		draw_door(t_all **all)
{
	char type;

	if (!((*all)->wall.dist = malloc(sizeof(double) * (*all)->r[X])))
		exit_error(all, NULL, MAL_ERR);
	while ((*all)->screen.column < (*all)->r[X])
	{
		init_wall(all, &(*all)->wall);
		set_side_dist(all, &(*all)->wall);
		type = set_side_type(all, &(*all)->wall);
		if (type == DOOR)
			draw_wall_pixel(all, &(*all)->bonus.door, (*all)->screen.column);
		else if (type == O_DOOR && (*all)->wall.side == (*all)->bonus.door_side)
			draw_wall_pixel(all, &(*all)->bonus.door, (*all)->screen.column);
		else
			draw_wall_pixel(all, &(*all)->text, (*all)->screen.column);
		(*all)->screen.column++;
	}
}
