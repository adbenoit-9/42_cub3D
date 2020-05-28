#include "cub3d_bonus.h"

static void	set_close_side(t_all **all, int *dirx, int *diry)
{
	if ((*all)->wall.side == NO)
	{
		*dirx = 0;
		*diry = -1;
	}
	else if ((*all)->wall.side == EA)
	{
		*dirx = 1;
		*diry = 0;
	}
	else if ((*all)->wall.side == SO)
	{	
		*dirx = 0;
		*diry = 1;
	}
	else if ((*all)->wall.side == WE)
	{
		*dirx = -1;
		*diry = 0;
	}
}

static void	set_open_side(t_all **all, int *newx, int *newy)
{
	if ((*all)->wall.side == NO)
	{
		*newx = 1;
		*newy = -1;
	}
	else if ((*all)->wall.side == EA)
	{
		*newx = 1;
		*newy = -1;
	}
	else if ((*all)->wall.side == SO)
	{
		*newx = 1;
		*newy = 1;
	}
	else if ((*all)->wall.side == WE)
	{
		*newx = -1;
		*newy = -1;
	}
}

void open_door(t_all **all)
{
	int x;
	int y;
	int dir[2];
	int	new[2];

	set_close_side(all, &dir[X], &dir[Y]);
	set_open_side(all, &new[X], &new[Y]);
	x = (*all)->player.map[X];
	y = (*all)->player.map[Y];
	if ((*all)->map[y + dir[Y]][x + dir[X]] == OPEN)
	{
		(*all)->map[y + dir[Y]][x + dir[X]] = DOOR;
		(*all)->map[y + new[Y]][x + new[X]] = (*all)->bonus.door_tmp;
	}
	else if ((*all)->map[y + dir[Y]][x + dir[X]] == DOOR)
	{
		if ((*all)->wall.side == NO)
			(*all)->bonus.door_side = EA;
		else if ((*all)->wall.side == SO)
			(*all)->bonus.door_side = EA;
		else if ((*all)->wall.side == EA)
			(*all)->bonus.door_side = NO;
		else if ((*all)->wall.side == WE)
			(*all)->bonus.door_side = NO;
		(*all)->map[y + dir[Y]][x + dir[X]] = OPEN;
		(*all)->bonus.door_tmp = (*all)->map[y + new[Y]][x + new[X]];
		(*all)->map[y + new[Y]][x + new[X]] = OPEN_DOOR;
	}
}