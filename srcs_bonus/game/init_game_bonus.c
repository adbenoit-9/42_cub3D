/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:27:48 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/09 15:25:23 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_bonus(t_game **game)
{
	int i;

	i = -1;
	if (!((*game)->path_bonus = malloc(sizeof(char *) * (NB_BON + 1))))
		exit_error(game, NULL, MAL_ERR);
	while (++i <= NB_BON)
		(*game)->path_bonus[i] = NULL;
	i = 0;
	while (i < 4)
	{
		(*game)->door.img.ptr[i] = NULL;
		(*game)->weap.img.ptr[i] = NULL;
		i++;
	}
	(*game)->heart.ptr = NULL;
	(*game)->lose_game.ptr = NULL;
	(*game)->win_game.ptr = NULL;
	(*game)->nb_foe = 0;
	(*game)->map_c = 0;
}

void		init_game(t_game **game)
{
	int i;

	(*game)->ret = 1;
	(*game)->state = INFO;
	(*game)->r[X] = -1;
	(*game)->r[Y] = -1;
	(*game)->c = -1;
	(*game)->f = -1;
	(*game)->map_size = 0;
	(*game)->map = NULL;
	(*game)->player.start_pos = 0;
	(*game)->wall.dist = NULL;
	(*game)->win = NULL;
	(*game)->img.ptr = NULL;
	if (!((*game)->path = malloc(sizeof(char *) * 6)))
		exit_error(game, NULL, MAL_ERR);
	i = -1;
	while (++i < 6)
		(*game)->path[i] = NULL;
	i = -1;
	while (++i < 4)
		(*game)->text.ptr[i] = NULL;
	init_sprite(game);
	init_bonus(game);
}

void		finish_init(t_game **game, t_sprite *sp)
{
	int i;

	(*game)->loop[0] = 0;
	(*game)->hit = 0;
	(*game)->life = 5;
	(*game)->weap.state = 3;
	if (!((*game)->wall.dist = malloc(sizeof(double) * (*game)->r[X])))
		exit_error(game, NULL, MAL_ERR);
	if (!(sp->pos = malloc(sizeof(double *) * sp->count)))
		exit_error(game, NULL, MAL_ERR);
	if (!(sp->dead = malloc(sizeof(int) * sp->count)))
		exit_error(game, NULL, MAL_ERR);
	if (!(sp->see = malloc(sizeof(int) * sp->count)))
		exit_error(game, NULL, MAL_ERR);
	if (!(sp->dist = malloc(sizeof(double) * sp->count)))
		exit_error(game, NULL, MAL_ERR);
	i = 0;
	while (i < sp->count)
	{
		if (!(sp->pos[i] = malloc(sizeof(double) * 2)))
			exit_error(game, NULL, MAL_ERR);
		sp->dead[i] = 0;
		sp->see[i] = 0;
		i++;
	}
}
