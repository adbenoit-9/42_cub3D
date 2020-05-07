#include "cub3d.h"

void	init_all(t_all **all)
{
	int i;

	(*all)->map = NULL;
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
	(*all)->ret = 1;
	(*all)->i_map = 0;
	(*all)->state = INFO;
	(*all)->pos = 0;
	if (!((*all)->info = malloc(sizeof(char *) * (NB_INFO + 1))))
		ft_error(all, NULL, MAL_ERR);
	if (!((*all)->bonus.path = malloc(sizeof(char *) * (NB_BON + 1))))
		ft_error(all, NULL, MAL_ERR);
	i = 0;
	(*all)->map = 0;
	(*all)->r[0] = -1;
	(*all)->r[1] = -1;
	(*all)->c = -1;
	(*all)->f = -1;
	(*all)->sp.count = 0;
	(*all)->bonus.sp.count = 0;
	while (i <= NB_INFO)
	{
		(*all)->info[i] = 0;
		i++;
	}
}

void    complete_all(t_all **all, t_sprite *sp)
{
    int i;

	i = 0;
	(*all)->bonus.loop = 0;
	(*all)->bonus.col = 0;
	(*all)->bonus.life = 5;
	(*all)->bonus.pull = 4;
	(*all)->bonus.foe = (*all)->bonus.sp.count;
	(*all)->bonus.all_sp.count = (*all)->sp.count + (*all)->bonus.sp.count;
	if (!(sp->pos = malloc(sizeof(double *) * sp->count)))
		ft_error(all, NULL, MAL_ERR);
	if (!(sp->dead = malloc(sizeof(int) * sp->count)))
		ft_error(all, NULL, MAL_ERR);
	if (!(sp->see = malloc(sizeof(int) * sp->count)))
		ft_error(all, NULL, MAL_ERR);
	while (i < sp->count)
	{
		if (!(sp->pos[i] = malloc(sizeof(double) * 2)))
			ft_error(all, NULL, MAL_ERR);
		sp->see[i] = 0;
		sp->dead[i] = 0;
		i++;
	}
}