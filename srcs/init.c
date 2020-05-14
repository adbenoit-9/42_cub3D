#include "cub3d.h"


void	init_all(t_all **all)
{
	int i;

	(*all)->ret = 1;
	(*all)->state = INFO;
	if (!((*all)->info = malloc(sizeof(char *) * (NB_INFO + 1))))
		ft_error(all, NULL, MAL_ERR);
	i = 0;
	while (i < NB_INFO)
	{
		(*all)->info[i] = NULL;
		i++;
	}
	(*all)->r[X] = -1;
	(*all)->r[Y] = -1;
	(*all)->c = -1;
	(*all)->f = -1;
	(*all)->i_map = 0;
	(*all)->pos = 0;
	(*all)->map = NULL;
	(*all)->sp.count = 0;
	(*all)->sp.coor = NULL;
	(*all)->sp.pos = NULL;
	(*all)->sp.dead = NULL;
	(*all)->sp.see = NULL;
	(*all)->sp.dist = NULL;
	(*all)->sp.type = NULL;
	(*all)->wall.dist = NULL;
	(*all)->bonus.path = NULL;
	(*all)->bonus.foe = 0;
	(*all)->img.ptr = NULL;
	(*all)->img.ptr = NULL;
	(*all)->text.ptr = NULL;
	(*all)->sp.ptr = NULL;
	(*all)->bonus.s1.ptr = NULL;
	(*all)->bonus.sa.ptr = NULL;
	(*all)->bonus.heart.ptr = NULL;
	(*all)->bonus.dead.ptr = NULL;
	(*all)->bonus.win.ptr = NULL;
	(*all)->bonus.door.ptr = NULL;
	(*all)->bonus.weap.ptr = NULL;
	(*all)->win = NULL;
}

void    complete_all(t_all **all, t_sprite *sp)
{
    int i;

	i = 0;
	(*all)->bonus.loop = 0;
	(*all)->bonus.col = 0;
	(*all)->bonus.life = 5;
	(*all)->bonus.pull = 4;
	if (!(sp->pos = malloc(sizeof(double *) * sp->count)))
		ft_error(all, NULL, MAL_ERR);
	if (!(sp->dead = malloc(sizeof(int) * sp->count)))
		ft_error(all, NULL, MAL_ERR);
	if (!(sp->see = malloc(sizeof(int) * sp->count)))
		ft_error(all, NULL, MAL_ERR);
	if (!(sp->dist = malloc(sizeof(double) * sp->count)))
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