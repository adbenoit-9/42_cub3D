
#include "cub3d_bonus.h"

static char	set_side_type(t_all **all, t_wall *wall)
{
	char type;

	type = 0;
	while (type != WALL && type != DOOR && type != OPEN_DOOR)
	{
		if (wall->side_dist[X] < wall->side_dist[Y])
		{
			wall->side_dist[X] += wall->delta_dist[X];
			wall->pos[X] += wall->step[X];
			if (wall->pos[X] < (*all)->player.map[X])
				wall->side = 0;
			else
				wall->side = 2;	
		}
		else
		{
			wall->side_dist[Y] += wall->delta_dist[Y];
			wall->pos[Y] += wall->step[Y];
			if (wall->pos[Y] < (*all)->player.map[Y])
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
		else if (type == OPEN_DOOR && (*all)->wall.side == (*all)->bonus.door_side)
			draw_wall_pixel(all, &(*all)->bonus.door, (*all)->screen.column);
		else
			draw_wall_pixel(all, &(*all)->text, (*all)->screen.column);
		(*all)->screen.column++;
	}
}