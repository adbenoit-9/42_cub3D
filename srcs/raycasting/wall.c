
#include "cub3d.h"

void	raycast_wall(t_all **all, int column)
{
	int end;
	int start;
	int i;
	double step;
	double textpos;

	i = 0;
	complete_text(all);
	(*all)->wall.slice_h = (*all)->r[Y] / (*all)->wall.dist[column];
	start = -1 * (*all)->wall.slice_h / 2 + (*all)->r[Y] / 2;
	if (start < 0)
		start = 0;
	end = (*all)->wall.slice_h / 2 + (*all)->r[Y] / 2;
	if (end >= (*all)->r[Y] || end < 0)
		end = (*all)->r[Y] - 1;
	step = 1.0 * (*all)->text.dim[(*all)->wall.side][Y] / (*all)->wall.slice_h;
	textpos = (start - (*all)->r[Y] / 2 + (*all)->wall.slice_h / 2) * step;
	while (i < start)
	{
		(*all)->img.data[column + (*all)->r[X] * i] = (*all)->c + (*all)->bonus.col;
		i++;
	}
	while (start < end)
	{
		(*all)->text.pos[Y] = (int)textpos;
		textpos += step;
		(*all)->img.data[column + (*all)->r[X] * start] = 
				(*all)->text.data[(*all)->wall.side][(int)((*all)->text.dim[(*all)->wall.side][X] * (*all)->text.pos[Y] + (*all)->text.pos[X])] + (*all)->bonus.col;
		start++;
	}
	i = start;
	while (i < (*all)->r[Y])
	{
		(*all)->img.data[column + (*all)->r[X] * i] = (*all)->f + (*all)->bonus.col;
		i++;
	}
}

void	ft_wall(t_all **all)
{
	if (!((*all)->wall.dist = malloc(sizeof(double) * (*all)->r[X])))
		exit_error(all, NULL, MAL_ERR);
	while ((*all)->screen.column < (*all)->r[X])
	{
		complete_wall_inf(all, &(*all)->wall);
		side_dist(all, &(*all)->wall);
		hit_wall(all);
		raycast_wall(all, (*all)->screen.column);
		(*all)->screen.column++;
	}
}