/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_door_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:16:52 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/08 15:26:07 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	set_open_dir(t_game **game, int *open_dirx, int *open_diry)
{
	if ((*game)->wall.side == NO)
	{
		*open_dirx = 1;
		*open_diry = -1;
	}
	else if ((*game)->wall.side == EA)
	{
		*open_dirx = 1;
		*open_diry = -1;
	}
	else if ((*game)->wall.side == SO)
	{
		*open_dirx = 1;
		*open_diry = 1;
	}
	else if ((*game)->wall.side == WE)
	{
		*open_dirx = -1;
		*open_diry = -1;
	}
}

static void	set_open_side(t_game **game)
{
	if ((*game)->wall.side == NO)
		(*game)->door.side = EA;
	else if ((*game)->wall.side == SO)
		(*game)->door.side = EA;
	else if ((*game)->wall.side == EA)
		(*game)->door.side = NO;
	else if ((*game)->wall.side == WE)
		(*game)->door.side = NO;
}

void		deal_door(t_game **game)
{
	int x;
	int y;
	int door_dir[2];
	int	open_dir[2];

	door_dir[X] = (*game)->door.dir[X];
	door_dir[Y] = (*game)->door.dir[Y];
	set_open_dir(game, &open_dir[X], &open_dir[Y]);
	x = (*game)->player.pos[X];
	y = (*game)->player.pos[Y];
	if ((*game)->map[y + door_dir[Y]][x + door_dir[X]] == OPEN)
	{
		(*game)->map[y + door_dir[Y]][x + door_dir[X]] = DOOR;
		(*game)->map[y + open_dir[Y]][x + open_dir[X]] = (*game)->door.tmp;
	}
	else if ((*game)->map[y + door_dir[Y]][x + door_dir[X]] == DOOR)
	{
		set_open_side(game);
		(*game)->map[y + door_dir[Y]][x + door_dir[X]] = OPEN;
		(*game)->door.tmp = (*game)->map[y + open_dir[Y]][x + open_dir[X]];
		(*game)->map[y + open_dir[Y]][x + open_dir[X]] = O_DOOR;
	}
}
