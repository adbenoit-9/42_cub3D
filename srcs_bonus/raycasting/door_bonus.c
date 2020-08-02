/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_door_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:19:45 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/08 23:04:04 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	set_door_dir(t_game **game)
{
	if ((*game)->wall.side == NO)
	{
		(*game)->door.dir[X] = 0;
		(*game)->door.dir[Y] = -1;
	}
	else if ((*game)->wall.side == EA)
	{
		(*game)->door.dir[X] = 1;
		(*game)->door.dir[Y] = 0;
	}
	else if ((*game)->wall.side == SO)
	{
		(*game)->door.dir[X] = 0;
		(*game)->door.dir[Y] = 1;
	}
	else if ((*game)->wall.side == WE)
	{
		(*game)->door.dir[X] = -1;
		(*game)->door.dir[Y] = 0;
	}
}

static void	set_side_direction(t_game **game, t_wall *wall)
{
	if (wall->side_dist[X] < wall->side_dist[Y])
	{
		wall->side_dist[X] += wall->delta_dist[X];
		wall->pos[X] += wall->step[X];
		wall->side = wall->pos[X] < (*game)->player.pos[X] ? WE : EA;
	}
	else
	{
		wall->side_dist[Y] += wall->delta_dist[Y];
		wall->pos[Y] += wall->step[Y];
		wall->side = wall->pos[Y] < (*game)->player.pos[Y] ? NO : SO;
	}
}

static char	set_wall_type(t_game **game, t_wall *wall)
{
	char	type;
	int		set;

	type = 0;
	set = 0;
	while (type != WALL && type != DOOR && type != O_DOOR)
	{
		set_side_direction(game, wall);
		type = (*game)->map[(int)wall->pos[Y]][(int)wall->pos[X]];
		if (type == OPEN)
		{
			set_door_dir(game);
			set = 1;
		}
	}
	if (set == 0)
		set_door_dir(game);
	return (type);
}

void		draw_door(t_game **game)
{
	char	type;
	int		side;

	while ((*game)->screen.x < (*game)->r[X])
	{
		init_wall(game, &(*game)->wall);
		set_side_dist(game, &(*game)->wall);
		type = set_wall_type(game, &(*game)->wall);
		side = (*game)->wall.side;
		if (type == DOOR)
			draw_wall_pixel(game, &(*game)->door.img, (*game)->screen.x, side);
		else if (type == O_DOOR && side == (*game)->door.side)
			draw_wall_pixel(game, &(*game)->door.img, (*game)->screen.x, side);
		else
			draw_wall_pixel(game, &(*game)->text, (*game)->screen.x, side);
		(*game)->screen.x++;
	}
}
