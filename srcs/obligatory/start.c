#include "cub3d.h"

void	all_null(t_all **all)
{
	(*all)->map = NULL;
	(*all)->info = NULL;
	(*all)->wall.dist = NULL;
	(*all)->img.ptr = NULL;
	//(*all)->img.data = NULL;
	(*all)->text.ptr = NULL;
	//(*all)->text.data[0] = NULL;
	(*all)->img.ptr = NULL;
	(*all)->mlx = NULL;
	(*all)->win = NULL;
	(*all)->sp.pos = NULL;
	(*all)->sp.coor = NULL;
	(*all)->sp.ptr = NULL;
	//(*all)->sp.data = NULL;
	(*all)->sp.dist = NULL;
}

static void ft_putdir(t_all **all, char o)
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

void	start(t_all **all)
{
	ft_putdir(all, (*all)->player.o);
	(*all)->grid.plane[X] = ((*all)->player.dir[X] == 0) ? 0.66 : 0;
	(*all)->grid.plane[Y] = ((*all)->player.dir[Y] == 0) ? 0.66 : 0;
	put_text(all);
	put_sprite(all, &(*all)->sp, (*all)->info[S]);
	create_image(all);
	if ((*all)->save == 1)
		save_bmp(all);
}