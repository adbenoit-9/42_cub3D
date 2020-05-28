
#include "cub3d.h"

static void	complete_door(t_all **all, t_wall *wall)
{
	wall->dist[(*all)->screen.column] = wall_dist(all, wall);
	if (wall->side % 2 == 0)
		wall->hit = (*all)->player.map[Y] + wall->dist[(*all)->screen.column] * wall->raydir[Y];
	else
		wall->hit = (*all)->player.map[X] + wall->dist[(*all)->screen.column] * wall->raydir[X];
	wall->hit -= (int)wall->hit;
	(*all)->bonus.door.pos[X] = (int)(wall->hit * (double)(*all)->bonus.door.dim[(*all)->wall.side][X]);
	if(wall->side == 0 && wall->raydir[X] > 0)
		(*all)->bonus.door.pos[X] = (*all)->bonus.door.dim[(*all)->wall.side][X] - (*all)->bonus.door.pos[X] - 1;
	if(wall->side == 1 && wall->raydir[Y] < 0)
		(*all)->bonus.door.pos[X] = (*all)->bonus.door.dim[(*all)->wall.side][X] - (*all)->bonus.door.pos[X] - 1;
}


static void	raycast_door(t_all **all, int column)
{
	int end;
	int start;
	double step;
	double doorpos;
	int		i;

	i = 0;
	complete_door(all, &(*all)->wall);
	(*all)->wall.slice_h = (*all)->r[Y] / (*all)->wall.dist[column];
	start = -1 * (*all)->wall.slice_h / 2 + (*all)->r[Y] / 2;
	if (start < 0)
		start = 0;
	end = (*all)->wall.slice_h / 2 + (*all)->r[Y] / 2;
	if (end >= (*all)->r[Y] || end < 0)
		end = (*all)->r[Y] - 1;

	step = 1.0 * (*all)->bonus.door.dim[(*all)->wall.side][Y] / (*all)->wall.slice_h;
	doorpos = (start - (*all)->r[Y] / 2 + (*all)->wall.slice_h / 2) * step;
	while (i < start)
	{
		(*all)->img.data[column + (*all)->r[X] * i] = (*all)->c + (*all)->bonus.col;
		i++;
	}
	while (start < end)
	{
		(*all)->bonus.door.pos[Y] = (int)doorpos;
		doorpos += step;
		(*all)->img.data[column + (*all)->r[X] * start] = 
				(*all)->bonus.door.data[(*all)->wall.side][(int)((*all)->bonus.door.dim[(*all)->wall.side][X] * (*all)->bonus.door.pos[Y] + (*all)->bonus.door.pos[X])] + (*all)->bonus.col;
		start++;
	}
	i = start;
	while (i < (*all)->r[Y])
	{
		(*all)->img.data[column + (*all)->r[X] * i] = (*all)->f + (*all)->bonus.col;
		i++;
	}
}

static int hit_door(t_all **all, t_wall *wall)
{
	int hit;

	hit = 0;
	while (hit == 0)
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
		if ((*all)->map[(int)wall->pos[Y]][(int)wall->pos[X]] == WALL)
			hit = 1;
		if ((*all)->map[(int)wall->pos[Y]][(int)wall->pos[X]] == DOOR)
			hit = 2;
		if ((*all)->map[(int)wall->pos[Y]][(int)wall->pos[X]] == WALL_DOOR)
			hit = 3;
	}
	return (hit);
}

void	ft_door(t_all **all)
{
	int hit;
	if (!((*all)->wall.dist = malloc(sizeof(double) * (*all)->r[X])))
		exit_error(all, NULL, MAL_ERR);
	while ((*all)->screen.column < (*all)->r[X])
	{
		complete_wall_inf(all, &(*all)->wall);
		side_dist(all, &(*all)->wall);
		hit = hit_door(all, &(*all)->wall);
		if (hit == 2)
			raycast_door(all, (*all)->screen.column);
		else if (hit == 3 && (*all)->wall.side == (*all)->bonus.door_side)
			raycast_door(all, (*all)->screen.column);
		else
			raycast_wall(all, (*all)->screen.column);
		(*all)->screen.column++;
	}
}