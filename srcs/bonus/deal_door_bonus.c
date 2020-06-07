/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_door_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:16:52 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/07 17:53:46 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	set_open_dir(t_all **all, int *open_dirx, int *open_diry)
{
	if ((*all)->wall.side == NO)
	{
		*open_dirx = 1;
		*open_diry = -1;
	}
	else if ((*all)->wall.side == EA)
	{
		*open_dirx = 1;
		*open_diry = -1;
	}
	else if ((*all)->wall.side == SO)
	{
		*open_dirx = 1;
		*open_diry = 1;
	}
	else if ((*all)->wall.side == WE)
	{
		*open_dirx = -1;
		*open_diry = -1;
	}
}

static void	set_open_side(t_all **all)
{
	if ((*all)->wall.side == NO)
		(*all)->bonus.door.side = EA;
	else if ((*all)->wall.side == SO)
		(*all)->bonus.door.side = EA;
	else if ((*all)->wall.side == EA)
		(*all)->bonus.door.side = NO;
	else if ((*all)->wall.side == WE)
		(*all)->bonus.door.side = NO;
}

void		deal_door(t_all **all)
{
	int x;
	int y;
	int door_dir[2];
	int	open_dir[2];

	door_dir[X] = (*all)->bonus.door.dir[X];
	door_dir[Y] = (*all)->bonus.door.dir[Y];
	set_open_dir(all, &open_dir[X], &open_dir[Y]);
	x = (*all)->player.pos[X];
	y = (*all)->player.pos[Y];
	if ((*all)->map[y + door_dir[Y]][x + door_dir[X]] == OPEN)
	{
		(*all)->map[y + door_dir[Y]][x + door_dir[X]] = DOOR;
		(*all)->map[y + open_dir[Y]][x + open_dir[X]] = (*all)->bonus.door.tmp;
	}
	else if ((*all)->map[y + door_dir[Y]][x + door_dir[X]] == DOOR)
	{
		set_open_side(all);
		(*all)->map[y + door_dir[Y]][x + door_dir[X]] = OPEN;
		(*all)->bonus.door.tmp = (*all)->map[y + open_dir[Y]][x + open_dir[X]];
		(*all)->map[y + open_dir[Y]][x + open_dir[X]] = O_DOOR;
	}
}
