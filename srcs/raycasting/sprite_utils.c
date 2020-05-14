#include "cub3d.h"

void	put_sprite(t_all **all, t_sprite *sp, char *path)
{
	sp->dim[X] = 0;
	sp->dim[Y] = 0;
	add_dim_xpm(all, path, &sp->dim[X], &sp->dim[Y]);
	sp->bpp = 32;
	sp->size_line = sp->dim[X] * 4;
	sp->endian = 0;
	if ((sp->ptr = mlx_xpm_file_to_image((*all)->mlx, path, &sp->dim[X], &sp->dim[Y])) == NULL)
		ft_error(all, NULL, PARS_ERR);
	sp->data = (int *)mlx_get_data_addr(sp->ptr, &sp->bpp, &sp->size_line, &sp->endian);
}

void	sort_sprite(t_sprite *sp)
{
	double tmp;
	int i;
	int j;

	j = 0;
	while (j < sp->count)
	{
		i = 0;
		while (i < sp->count - 1)
		{
			if (sp->dist[i] < sp->dist[i + 1])
			{
				tmp = sp->dist[i];
				sp->dist[i] = sp->dist[i + 1];
				sp->dist[i + 1] = tmp;
				tmp = sp->coor[i][X];
				sp->coor[i][X] = sp->coor[i + 1][X];
				sp->coor[i + 1][X] = tmp;
				tmp = sp->coor[i][Y];
				sp->coor[i][Y] = sp->coor[i + 1][Y];
				sp->coor[i + 1][Y] = tmp;
			}
			i++;
		}
		j++;
	}
}

void	add_dist(t_all **all, t_sprite *sp, void (*sort)(t_sprite *))
{
	int i;

	i = 0;
	while (i < sp->count)
	{
		sp->dist[i] = pow((*all)->player.map[X] - sp->coor[i][X], 2) +
					pow((*all)->player.map[Y] - sp->coor[i][Y], 2);
		i++;
	}
	sort(sp);
}