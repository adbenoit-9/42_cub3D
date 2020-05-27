#include "cub3d.h"

void open_door(t_all **all)
{
	int x;
	int y;
	int dir[2];
	int	new[2];

	x = (*all)->player.map[X];
	y = (*all)->player.map[Y];
	if ((*all)->wall.side == NO)
	{
		dir[X] = 0;
		dir[Y] = -1;
		new[X] = 1;
		new[Y]= -1;
	}
	if ((*all)->wall.side == EA)
	{
		dir[X] = 1;
		dir[Y] = 0;
		new[X] = 1;
		new[Y]= -1;
	}
	if ((*all)->wall.side == SO)
	{
		new[X] = 1;
		new[Y]= 1;
		dir[X] = 0;
		dir[Y] = 1;
	}
	if ((*all)->wall.side == WE)
	{
		new[X] = -1;
		new[Y]= -1;
		dir[X] = -1;
		dir[Y] = 0;
	}
	if ((*all)->map[y + dir[Y]][x + dir[X]] == OPEN)
	{
		(*all)->map[y + dir[Y]][x + dir[X]] = DOOR;
		(*all)->map[y + new[Y]][x + new[X]] = (*all)->bonus.door_tmp;
	}
	else if ((*all)->map[y + dir[Y]][x + dir[X]] == DOOR)
	{
		if ((*all)->wall.side == NO)
			(*all)->bonus.door_side = EA;
		if ((*all)->wall.side == SO)
			(*all)->bonus.door_side = EA;
		if ((*all)->wall.side == EA)
			(*all)->bonus.door_side = NO;
		if ((*all)->wall.side == WE)
			(*all)->bonus.door_side = NO;
		(*all)->map[y + dir[Y]][x + dir[X]] = OPEN;
		(*all)->bonus.door_tmp = (*all)->map[y + new[Y]][x + new[X]];
		(*all)->map[y + new[Y]][x + new[X]] = WALL_DOOR;
	}
}