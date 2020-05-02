#include "cub3d.h"

static void	print_state_sprite(t_all **all, t_sprite *sp)
{
	double	invdet;
	int		i;

	i = 0;
	add_dist(all, sp);
	add_dist(all, &(*all)->bonus.sa);
	invdet = 1.0 / ((*all)->grid.plane[X] * (*all)->player.dir[Y] - (*all)->player.dir[X] * (*all)->grid.plane[Y]);
	while (i < sp->count)
	{
		//printf("sprite %d is %d\n", i, sp->dead[i]);
		if (sp->dead[i] == 0)
			raycast_sprite(all, sp, invdet, i);
		if (sp->dead[i] == 1)
			raycast_sprite(all, &(*all)->bonus.sa, invdet, i);
		i++;
	}
}

int		create_image(t_all **all)
{
	(*all)->bonus.loop++;
	if ((*all)->img.ptr != NULL)
	{
		mlx_destroy_image((*all)->mlx, (*all)->img.ptr);
		mlx_clear_window((*all)->mlx, (*all)->win);
		(*all)->img.ptr = NULL;
	}
	(*all)->img.ptr = mlx_new_image((*all)->mlx, (*all)->r[X], (*all)->r[Y]);
	(*all)->img.bpp = 32;
	(*all)->img.size_line = (*all)->r[X] * 4;
	(*all)->img.endian = 0;
	(*all)->img.data = (int *)mlx_get_data_addr((*all)->img.ptr, &(*all)->img.bpp, &(*all)->img.size_line, &(*all)->img.endian);
	(*all)->grid.column = 0;
	raycast_wall(all);
	print_state_sprite(all, &(*all)->sp);
	print_state_sprite(all, &(*all)->bonus.sp);
	add_mini_map(all);
	print_weapon(all, (*all)->bonus.pull);
	print_hearts(all);
	mlx_put_image_to_window((*all)->mlx, (*all)->win, (*all)->img.ptr, 0, 0);
	ft_pull_weapon(all);
	ft_move(all);
	return (NO_ERR);
}
