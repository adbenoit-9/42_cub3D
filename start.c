
#include "cub3d.h"

int		ft_rgb(int r, int g, int b)
{
	return ((256 * 256 * r) + (256 * g) + b);
}

void	ft_putdir(t_all **all, char o)
{

	(*all)->player.dir[X] = 0;
	if (o == 'N')
		(*all)->player.dir[Y] = -1;
	else if (o == 'S')
		(*all)->player.dir[Y] = 1;
	else
	{

		(*all)->player.dir[Y] = 0;
		if (o == 'E')
			(*all)->player.dir[X] = -1;
		else if (o == 'W')
			(*all)->player.dir[X] = 1;
	}
}

int		raycast_wall(t_all **all)
{
	int end;
	int start;
	int i;
	double step;
	double textpos;

	if (!((*all)->wall.dist = malloc(sizeof(double) * (*all)->r[X])))
		return (MAL_ERR);
	while ((*all)->grid.column < (*all)->r[X])
	{
		i = 0;
		complete_wall_inf(all);
		side_dist(all);
		hit_wall(all);
		complete_text(all);
		(*all)->wall.slice_h = (*all)->r[Y] / (*all)->wall.dist[(*all)->grid.column];
		start = -1 * (*all)->wall.slice_h / 2 + (*all)->r[Y] / 2;
		if (start < 0)
			start = 0;
		end = (*all)->wall.slice_h / 2 + (*all)->r[Y] / 2;
		if (end >= (*all)->r[Y])
			end = (*all)->r[Y] - 1;

		step = 1.0 * (*all)->text.dim[Y] / (*all)->wall.slice_h;
		textpos = (start - (*all)->r[Y] / 2 + (*all)->wall.slice_h / 2) * step;
		while (i < start)
		{
			(*all)->img.data[(*all)->grid.column + (*all)->r[X] * i] = (*all)->c;
			i++;
		}
		while (start < end)
		{
			(*all)->text.pos[Y] = (int)textpos;
			textpos += step;
			(*all)->img.data[(*all)->grid.column + (*all)->r[X] * start] = (*all)->text.data[(*all)->wall.side][(int)((*all)->text.dim[Y] * (*all)->text.pos[Y] + (*all)->text.pos[X])];
			start++;
		}
		i = start;
		while (i < (*all)->r[Y])
	{
		(*all)->img.data[(*all)->grid.column + (*all)->r[X] * i] = (*all)->f;
		i++;
	}
		(*all)->grid.column++;
	}
	return (NO_ERR);
}

int	create_image(t_all **all)
{
	if ((*all)->img.ptr != NULL)
		mlx_destroy_image((*all)->mlx, (*all)->img.ptr);
	(*all)->img.ptr = mlx_new_image((*all)->mlx, (*all)->r[X], (*all)->r[Y]);
	(*all)->img.bpp = 32;
	(*all)->img.size_line = (*all)->r[X] * 4;
	(*all)->img.endian = 0;
	(*all)->img.data = (int *)mlx_get_data_addr((*all)->img.ptr, &(*all)->img.bpp, &(*all)->img.size_line, &(*all)->img.endian);
	(*all)->grid.column = 0;
	put_text(all);
	put_sprite(all);
	raycast_wall(all);
	raycast_sprite(all);
	mlx_put_image_to_window((*all)->mlx, (*all)->win, (*all)->img.ptr, 0, 0);
	return (NO_ERR);
}

int start(t_all **all)
{
	ft_putdir(all, (*all)->player.o);
	(*all)->img.ptr = NULL;
	(*all)->grid.plane[X] = ((*all)->player.dir[X] == 0) ? 0.66 : 0;
	(*all)->grid.plane[Y] = ((*all)->player.dir[Y] == 0) ? 0.66 : 0;
	return (NO_ERR);
}
