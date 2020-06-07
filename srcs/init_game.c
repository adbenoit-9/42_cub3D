/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:27:48 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/07 23:10:20 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_sprite(t_all **all)
{
	(*all)->sp.count = 0;
	(*all)->sp.coor = NULL;
	(*all)->sp.pos = NULL;
	(*all)->sp.dead = NULL;
	(*all)->sp.see = NULL;
	(*all)->sp.dist = NULL;
	(*all)->sp.type = NULL;
	(*all)->sp.img.ptr = NULL;
	(*all)->bonus.s1.img.ptr = NULL;
	(*all)->bonus.sa.img.ptr = NULL;
}

static void	init_bonus(t_all **all)
{
	int i;

	i = -1;
	if (!((*all)->bonus.path = malloc(sizeof(char *) * (NB_BON + 1))))
		exit_error(all, NULL, MAL_ERR);
	while (++i <= NB_BON)
		(*all)->bonus.path[i] = NULL;
	i = 0;
	while (i < 4)
	{
		(*all)->bonus.door.img.ptr[i] = NULL;
		(*all)->bonus.weap.img.ptr[i] = NULL;
		i++;
	}
	(*all)->bonus.heart.ptr = NULL;
	(*all)->bonus.lose_game.ptr = NULL;
	(*all)->bonus.win_game.ptr = NULL;
	(*all)->bonus.foe = 0;
	(*all)->bonus.map_c = 0;
}

void		init_game(t_all **all)
{
	int i;

	(*all)->ret = 1;
	(*all)->state = INFO;
	(*all)->r[X] = -1;
	(*all)->r[Y] = -1;
	(*all)->c = -1;
	(*all)->f = -1;
	(*all)->map_size = 0;
	(*all)->map = NULL;
	(*all)->player.start_pos = 0;
	(*all)->wall.dist = NULL;
	(*all)->win = NULL;
	(*all)->img.ptr = NULL;
	if (!((*all)->path = malloc(sizeof(char *) * 6)))
		exit_error(all, NULL, MAL_ERR);
	i = -1;
	while (++i < 6)
		(*all)->path[i] = NULL;
	i = -1;
	while (++i < 4)
		(*all)->text.ptr[i] = NULL;
	init_sprite(all);
	init_bonus(all);
}

void		finish_init(t_all **all, t_sprite *sp)
{
	int i;

	(*all)->bonus.loop[0] = 0;
	(*all)->bonus.hurt = 0;
	(*all)->bonus.life = 5;
	(*all)->bonus.weap.state = 3;
	if (!((*all)->wall.dist = malloc(sizeof(double) * (*all)->r[X])))
		exit_error(all, NULL, MAL_ERR);
	if (!(sp->pos = malloc(sizeof(double *) * sp->count)))
		exit_error(all, NULL, MAL_ERR);
	if (!(sp->dead = malloc(sizeof(int) * sp->count)))
		exit_error(all, NULL, MAL_ERR);
	if (!(sp->see = malloc(sizeof(int) * sp->count)))
		exit_error(all, NULL, MAL_ERR);
	if (!(sp->dist = malloc(sizeof(double) * sp->count)))
		exit_error(all, NULL, MAL_ERR);
	i = 0;
	while (i < sp->count)
	{
		if (!(sp->pos[i] = malloc(sizeof(double) * 2)))
			exit_error(all, NULL, MAL_ERR);
		sp->dead[i] = 0;
		sp->see[i] = 0;
		i++;
	}
}

void		init_player(t_all **all, char o)
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
