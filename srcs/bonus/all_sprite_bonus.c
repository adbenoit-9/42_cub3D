/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_sprite_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:10:15 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/07 16:01:00 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		put_all_sprites(t_all **all)
{
	int i;
	int j;

	if (!((*all)->bonus.all_sp.dist = malloc(sizeof(double) * (*all)->bonus.all_sp.count)))
		ft_error(all, NULL, MAL_ERR);
	if (!((*all)->bonus.all_sp.pos = malloc(sizeof(double *) * (*all)->bonus.all_sp.count)))
		ft_error(all, NULL, MAL_ERR);
	if (!((*all)->bonus.all_sp.coor = malloc(sizeof(double *) * (*all)->bonus.all_sp.count)))
		ft_error(all, NULL, MAL_ERR);
	if (!((*all)->bonus.all_sp.type = malloc(sizeof(double *) * ((*all)->bonus.all_sp.count + 1))))
		ft_error(all, NULL, MAL_ERR);
	i = 0;
	while (i < (*all)->bonus.all_sp.count)
	{
		if (!((*all)->bonus.all_sp.coor[i] = malloc(sizeof(double) * 2)))
			ft_error(all, NULL, MAL_ERR);
		if (!((*all)->bonus.all_sp.pos[i] = malloc(sizeof(double) * 2)))
			ft_error(all, NULL, MAL_ERR);
		i++;
	}
	j = 0;
	i = 0;
	while (i < (*all)->sp.count)
	{
		(*all)->bonus.all_sp.coor[j][X] = (*all)->sp.coor[i][X];
		(*all)->bonus.all_sp.coor[j][Y] = (*all)->sp.coor[i][Y];
		(*all)->bonus.all_sp.type[j] = OBJ;
		i++;
		j++;
	}
	i = 0;
	while (i < (*all)->bonus.sp.count)
	{
		(*all)->bonus.all_sp.coor[j][X] = (*all)->bonus.sp.coor[i][X];
		(*all)->bonus.all_sp.coor[j][Y] = (*all)->bonus.sp.coor[i][Y];
		(*all)->bonus.all_sp.type[j] = OBJ1;
		i++;
		j++;
	}
	(*all)->bonus.all_sp.type[j] = 0;
}

static void	sort_all_sprite(t_sprite *sp)
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
				tmp = sp->pos[i][X];
				sp->pos[i][X] = sp->pos[i + 1][X];
				sp->pos[i + 1][X] = tmp;
				tmp = sp->pos[i][Y];
				sp->pos[i][Y] = sp->pos[i + 1][Y];
				sp->pos[i + 1][Y] = tmp;
				// tmp = sp->type[i];
				// sp->type[i] = sp->type[i + 1];
				// sp->type[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}

static void	add_all_dist(t_all **all, t_sprite *sp1, t_sprite *sp2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < sp1->count)
	{
		(*all)->bonus.all_sp.dist[j] = pow((*all)->player.map[X] - sp1->coor[i][X], 2) + pow((*all)->player.map[Y] - sp1->coor[i][Y], 2);
		i++;
		j++;
	}
	i = 0;
	while (i < sp2->count)
	{
		(*all)->bonus.all_sp.dist[j] = pow((*all)->player.map[X] - sp2->coor[i][X], 2) + pow((*all)->player.map[Y] - sp2->coor[i][Y], 2);
		i++;
		j++;
	}
	sort_all_sprite(&(*all)->bonus.all_sp);
}

void	print_all_sprites(t_all **all, t_sprite *sp1, t_sprite *sp2)
{
	double	invdet;
	int		i;

	i = 0;
	add_all_dist(all, sp1, sp2);
	invdet = 1.0 / ((*all)->grid.plane[X] * (*all)->player.dir[Y] - (*all)->player.dir[X] * (*all)->grid.plane[Y]);
	while (i < (*all)->bonus.all_sp.count)
	{
		if ((*all)->bonus.all_sp.dead[i] == 0 && (*all)->bonus.all_sp.type[i] == OBJ)
			raycast_sprite(all, &(*all)->bonus.all_sp, sp1, invdet, i);
		else if ((*all)->bonus.all_sp.dead[i] == 0 && (*all)->bonus.all_sp.type[i] == OBJ1)
			raycast_sprite(all, &(*all)->bonus.all_sp, sp2, invdet, i);
		else if ((*all)->bonus.all_sp.dead[i] == 1 && (*all)->bonus.all_sp.type[i] == OBJ1)
			raycast_sprite(all,  &(*all)->bonus.all_sp, &(*all)->bonus.sa, invdet, i);
		i++;
	}
}