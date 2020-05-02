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
	(*all)->bonus.pull = 4;
	(*all)->bonus.life = 5;
}

void ft_putdir(t_all **all, char o)
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
	int i;

	i = 0;
	(*all)->bonus.loop = 0;
	(*all)->bonus.col = 0;
	if (!((*all)->bonus.sp.dead = malloc(sizeof(int) * (*all)->bonus.sp.count)))
		ft_error(all, NULL, MAL_ERR);
	if (!((*all)->bonus.sa.dead = malloc(sizeof(int) * (*all)->bonus.sa.count)))
		ft_error(all, NULL, MAL_ERR);
	if (!((*all)->sp.dead = malloc(sizeof(int) * (*all)->sp.count)))
		ft_error(all, NULL, MAL_ERR);
	if (!((*all)->bonus.sp.see = malloc(sizeof(int) * (*all)->bonus.sp.count)))
		ft_error(all, NULL, MAL_ERR);
	if (!((*all)->sp.see = malloc(sizeof(int) * (*all)->sp.count)))
		ft_error(all, NULL, MAL_ERR);
	if (!((*all)->bonus.sa.see = malloc(sizeof(int) * (*all)->bonus.sa.count)))
		ft_error(all, NULL, MAL_ERR);
	while (i < (*all)->sp.count)
	{
		(*all)->sp.see[i] = 0;
		(*all)->bonus.sa.see[i] = 0;
		(*all)->sp.dead[i] = 0;
		(*all)->bonus.sa.dead[i] = 1;
		i++;
	}
	i = 0;
	while (i < (*all)->bonus.sp.count)
	{
		(*all)->bonus.sp.see[i] = 0;
		(*all)->bonus.sp.dead[i] = 0;
		i++;
	}
	ft_putdir(all, (*all)->player.o);
	(*all)->grid.plane[X] = ((*all)->player.dir[X] == 0) ? 0.66 : 0;
	(*all)->grid.plane[Y] = ((*all)->player.dir[Y] == 0) ? 0.66 : 0;
	put_text(all);
	put_sprite(all, &(*all)->sp, (*all)->info[S]);
	put_sprite(all, &(*all)->bonus.sp, (*all)->bonus.path[S1]);
	put_sprite(all, &(*all)->bonus.sa, (*all)->bonus.path[SA]);
	put_weapon(all);
	put_img(all, &(*all)->bonus.heart, "./xpm/heart.xpm");
	put_img(all, &(*all)->bonus.dead, "./xpm/play_again_button.xpm");
	create_image(all);
	if ((*all)->save == 1)
		save_bmp(all);
}