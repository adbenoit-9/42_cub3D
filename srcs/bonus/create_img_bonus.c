#include "cub3d.h"

int		create_image(t_all **all)
{
	int i;

	(*all)->bonus.loop2++;
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
	ft_door(all);
	print_all_sprites(all, &(*all)->sp);
	add_mini_map(all);
	print_weapon(all, (*all)->bonus.pull);
	print_hearts(all);
	ft_pull_weapon(all);
	lose_life(all, (*all)->bonus.c);
	free((*all)->wall.dist);
	(*all)->wall.dist = NULL;
	mlx_put_image_to_window((*all)->mlx, (*all)->win, (*all)->img.ptr, 0, 0);
	ft_move(all);
	i = 0;
	while (i < (*all)->sp.count)
	{
		(*all)->sp.see[i] = 0;
		i++;
	}
	return (NO_ERR);
}
