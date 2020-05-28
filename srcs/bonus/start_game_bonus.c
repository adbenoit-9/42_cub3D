#include "cub3d_bonus.h"

void init_player(t_all **all, char o)
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

void	start_game(t_all **all)
{
	if(!((*all)->mlx_ptr = mlx_init()))
		exit_error(all, NULL, MLX_ERR);
	if(!((*all)->win_ptr = mlx_new_window((*all)->mlx_ptr, (*all)->r[X], (*all)->r[Y], "Cub3D")))
		exit_error(all, NULL, MLX_ERR);
	check_door(all);
	finish_init(all, &(*all)->sp);
	init_player(all, (*all)->player.start_o);
	(*all)->screen.plane[X] = ((*all)->player.dir[X] == 0) ? 0.66 : 0;
	(*all)->screen.plane[Y] = ((*all)->player.dir[Y] == 0) ? 0.66 : 0;
	load_tab_of_image(all, &(*all)->text, (*all)->path, 0);
	load_tab_of_image(all, &(*all)->bonus.weap, (*all)->bonus.path, 0);
	load_tab_of_image(all, &(*all)->bonus.door, (*all)->bonus.path, DN);
	load_image(all, &(*all)->sp.img, (*all)->path[S]);
	load_image(all, &(*all)->bonus.s1.img, (*all)->bonus.path[S1]);
	load_image(all, &(*all)->bonus.sa.img, (*all)->bonus.path[SA]);
	load_image(all, &(*all)->bonus.heart, (*all)->bonus.path[LIFE]);
	load_image(all, &(*all)->bonus.dead, (*all)->bonus.path[LOSE]);
	load_image(all, &(*all)->bonus.win, (*all)->bonus.path[WIN]);
	create_image(all);
	if ((*all)->save == TRUE)
		save_bmp(all);
}