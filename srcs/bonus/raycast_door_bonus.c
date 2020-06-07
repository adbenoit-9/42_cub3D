/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_door_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:19:45 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/07 23:17:35 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	set_door_dir(t_all **all)
{
	if ((*all)->wall.side == NO)
	{
		(*all)->bonus.door.dir[X] = 0;
		(*all)->bonus.door.dir[Y] = -1;
	}
	else if ((*all)->wall.side == EA)
	{
		(*all)->bonus.door.dir[X] = 1;
		(*all)->bonus.door.dir[Y] = 0;
	}
	else if ((*all)->wall.side == SO)
	{
		(*all)->bonus.door.dir[X] = 0;
		(*all)->bonus.door.dir[Y] = 1;
	}
	else if ((*all)->wall.side == WE)
	{
		(*all)->bonus.door.dir[X] = -1;
		(*all)->bonus.door.dir[Y] = 0;
	}
}

static void	set_side_direction(t_all **all, t_wall *wall)
{
	if (wall->side_dist[X] < wall->side_dist[Y])
	{
		wall->side_dist[X] += wall->delta_dist[X];
		wall->pos[X] += wall->step[X];
		wall->side = wall->pos[X] < (*all)->player.pos[X] ? WE : EA;
	}
	else
	{
		wall->side_dist[Y] += wall->delta_dist[Y];
		wall->pos[Y] += wall->step[Y];
		wall->side = wall->pos[Y] < (*all)->player.pos[Y] ? NO : SO;
	}
}

static char	set_wall_type(t_all **all, t_wall *wall)
{
	char	type;
	int		set;

	type = 0;
	set = 0;
	while (type != WALL && type != DOOR && type != O_DOOR)
	{
		set_side_direction(all, wall);
		type = (*all)->map[(int)wall->pos[Y]][(int)wall->pos[X]];
		if (type == OPEN)
		{
			set_door_dir(all);
			set = 1;
		}
	}
	if (set == 0)
		set_door_dir(all);
	return (type);
}

void		draw_door(t_all **all)
{
	char type;

	while ((*all)->screen.x < (*all)->r[X])
	{
		init_wall(all, &(*all)->wall);
		set_side_dist(all, &(*all)->wall);
		type = set_wall_type(all, &(*all)->wall);
		if (type == DOOR)
			draw_wall_pixel(all, &(*all)->bonus.door.img, (*all)->screen.x);
		else if (type == O_DOOR && (*all)->wall.side == (*all)->bonus.door.side)
			draw_wall_pixel(all, &(*all)->bonus.door.img, (*all)->screen.x);
		else
			draw_wall_pixel(all, &(*all)->text, (*all)->screen.x);
		(*all)->screen.x++;
	}
}
