#include "cub3d.h"

void ft_putdir(t_all **all, char o)
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
	check_door(all);
	complete_all(all, &(*all)->sp);
	ft_putdir(all, (*all)->player.o);
	(*all)->grid.plane[X] = ((*all)->player.dir[X] == 0) ? 0.66 : 0;
	(*all)->grid.plane[Y] = ((*all)->player.dir[Y] == 0) ? 0.66 : 0;
	put_tab_img(all, &(*all)->text, (*all)->info, 0);
	put_tab_img(all, &(*all)->bonus.weap, (*all)->bonus.path, 0);
	put_tab_img(all, &(*all)->bonus.door, (*all)->bonus.path, DN);
	put_img(all, &(*all)->sp.img, (*all)->info[S]);
	put_img(all, &(*all)->bonus.s1.img, (*all)->bonus.path[S1]);
	put_img(all, &(*all)->bonus.sa.img, (*all)->bonus.path[SA]);
	put_img(all, &(*all)->bonus.heart, (*all)->bonus.path[LIFE]);
	put_img(all, &(*all)->bonus.dead, (*all)->bonus.path[LOSE]);
	put_img(all, &(*all)->bonus.win, (*all)->bonus.path[WIN]);
	create_image(all);
	if ((*all)->save == 1)
		save_bmp(all);
}