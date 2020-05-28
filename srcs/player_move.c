
#include "cub3d.h"

void	ft_forward(t_all **all)
{
	char new_pos;

	new_pos = (*all)->map[(int)((*all)->player.map[Y] + (*all)->player.dir[Y]
		* MOVESPEED)][(int)((*all)->player.map[X] + (*all)->player.dir[X] * MOVESPEED)];
	(*all)->bonus.map_c = new_pos;
	if (new_pos != WALL && new_pos != DOOR && new_pos != WALL_DOOR && new_pos != OBJ1)
	{
		(*all)->player.map[X] += (*all)->player.dir[X] * MOVESPEED;
		(*all)->player.map[Y] += (*all)->player.dir[Y] * MOVESPEED;
	}
}

void	ft_leftward(t_all **all)
{
	char new_pos;

	new_pos = (*all)->map[(int)((*all)->player.map[Y] - (*all)->player.dir[X] *
		MOVESPEED)][(int)((*all)->player.map[X] + (*all)->player.dir[Y] * MOVESPEED)];
	(*all)->bonus.map_c = new_pos;
	if (new_pos != WALL && new_pos != DOOR && new_pos != WALL_DOOR && new_pos != OBJ1)
	{
		(*all)->player.map[X] += (*all)->player.dir[Y] * MOVESPEED;
		(*all)->player.map[Y] -= (*all)->player.dir[X] * MOVESPEED;
	}
}

void	ft_backward(t_all **all)
{
	char new_pos;

	new_pos = (*all)->map[(int)((*all)->player.map[Y] - (*all)->player.dir[Y] *
		MOVESPEED)][(int)((*all)->player.map[X] - (*all)->player.dir[X] * MOVESPEED)];
	(*all)->bonus.map_c = new_pos;
	if (new_pos != WALL && new_pos != DOOR && new_pos != WALL_DOOR && new_pos != OBJ1)
	{
		(*all)->player.map[X] -= (*all)->player.dir[X] * MOVESPEED;
		(*all)->player.map[Y] -= (*all)->player.dir[Y] * MOVESPEED;
	}
}

void	ft_rightward(t_all **all)
{
	char new_pos;

	new_pos = (*all)->map[(int)((*all)->player.map[Y] + (*all)->player.dir[X] *
		MOVESPEED)][(int)((*all)->player.map[X] - (*all)->player.dir[Y] * MOVESPEED)];
	(*all)->bonus.map_c = new_pos;
	if (new_pos != WALL && new_pos != DOOR && new_pos != WALL_DOOR && new_pos != OBJ1)
	{
		(*all)->player.map[X] -= (*all)->player.dir[Y] * MOVESPEED;
		(*all)->player.map[Y] += (*all)->player.dir[X] * MOVESPEED;
	}
}