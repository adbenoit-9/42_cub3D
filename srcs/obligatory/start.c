#include "cub3d.h"

static void ft_putdir(t_all **all, char o)
{
	if (o == 'N')
	{
		(*all)->player.dir[X] = 0;
		(*all)->player.dir[Y] = -1;

	}
	else if (o == 'S')
	{
		(*all)->player.dir[X] = 0;
		(*all)->player.dir[Y] = 1;

	}
	else if (o == 'E')
	{
		(*all)->player.dir[X] = 1;
		(*all)->player.dir[Y] = 0;

	}
	else if (o == 'W')
	{
		(*all)->player.dir[X] = -1;
		(*all)->player.dir[Y] = 0;

	}
}

void	start(t_all **all)
{
	complete_all(all, &(*all)->sp);
	ft_putdir(all, (*all)->player.o);
	(*all)->grid.plane[X] = ((*all)->player.dir[X] == 0) ? 0.66 : 0;
	(*all)->grid.plane[Y] = ((*all)->player.dir[Y] == 0) ? 0.66 : 0;
	put_text(all);
	put_sprite(all, &(*all)->sp, (*all)->info[S]);
	create_image(all);
	if ((*all)->save == 1)
		save_bmp(all);
}