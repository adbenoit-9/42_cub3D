#include "cub3d.h"

void	ft_putdir(t_all **all, char o)
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
	if(!((*all)->mlx = mlx_init()))
		exit_game(all, NULL, MLX_ERR);
	if(!((*all)->win = mlx_new_window((*all)->mlx, (*all)->r[X], (*all)->r[Y], "Cub3D")))
		exit_game(all, NULL, MLX_ERR);
	complete_all(all, &(*all)->sp);
	ft_putdir(all, (*all)->player.o);
	(*all)->grid.plane[X] = ((*all)->player.dir[X] == 0) ? 0.66 : 0;
	(*all)->grid.plane[Y] = ((*all)->player.dir[Y] == 0) ? 0.66 : 0;
	put_tab_img(all, &(*all)->text, (*all)->info, 0);
	put_img(all, &(*all)->sp.img, (*all)->info[S]);
	create_image(all);
	if ((*all)->save == 1)
		save_bmp(all);
}