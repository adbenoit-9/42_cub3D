#include "cub3d.h"

void	put_door(t_all **all)
{
	int i;

	i = 0;
	(*all)->bonus.door.bpp = 32;
	(*all)->bonus.door.endian = 0;
	while (i < 4)
	{
		(*all)->bonus.door.dim[i][X] = 0;
		(*all)->bonus.door.dim[i][Y] = 0;
		add_dim_xpm(all, (*all)->bonus.path[DN + i], &(*all)->bonus.door.dim[i][X], &(*all)->bonus.door.dim[i][Y]);
		(*all)->bonus.door.size_line = (*all)->bonus.door.dim[i][X] * 4;
		if (((*all)->bonus.door.ptr = mlx_xpm_file_to_image((*all)->mlx, (*all)->bonus.path[DN + i], &(*all)->bonus.door.dim[i][X], &(*all)->bonus.door.dim[i][Y])) == NULL)
			ft_error(all, NULL, PARS_ERR);
		(*all)->bonus.door.data[i] = (int *)mlx_get_data_addr((*all)->bonus.door.ptr, &(*all)->bonus.door.bpp, &(*all)->bonus.door.size_line, &(*all)->bonus.door.endian);
		i++;
	}
}

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
	if ((*all)->key.f == 1 && (*all)->map[y + dir[Y]][x + dir[X]] == OPEN)
	{
		(*all)->map[y + dir[Y]][x + dir[X]] = DOOR;
		(*all)->map[y + new[Y]][x + new[X]] = (*all)->bonus.door.tmp;
	}
	else if ((*all)->key.f == 1 && (*all)->map[y + dir[Y]][x + dir[X]] == DOOR)
	{
		if ((*all)->wall.side == NO)
			(*all)->bonus.door.side = EA;
		if ((*all)->wall.side == SO)
			(*all)->bonus.door.side = EA;
		if ((*all)->wall.side == EA)
			(*all)->bonus.door.side = NO;
		if ((*all)->wall.side == WE)
			(*all)->bonus.door.side = NO;
		(*all)->map[y + dir[Y]][x + dir[X]] = OPEN;
		(*all)->bonus.door.tmp = (*all)->map[y + new[Y]][x + new[X]];
		(*all)->map[y + new[Y]][x + new[X]] = WALL_DOOR;
	}
}