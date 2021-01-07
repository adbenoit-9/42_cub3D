/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:21:45 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/02 23:49:42 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	screen_resize(t_game **game)
{
	int	x_max;
	int	y_max;

	mlx_get_screen_size((*game)->mlx, &x_max, &y_max);
	if ((*game)->r[X] > x_max)
		(*game)->r[X] = x_max;
	if ((*game)->r[Y] > y_max)
		(*game)->r[Y] = y_max;
}

void		start_game(t_game **game)
{
	if (!((*game)->mlx = mlx_init()))
		exit_error(game, NULL, MLX_ERR);
	screen_resize(game);
	finish_init(game, &(*game)->sp);
	init_player_dir(game, (*game)->player.start_o);
	load_tab_of_image(game, &(*game)->text, (*game)->path, 0);
	load_tab_of_image(game, &(*game)->weap.img, (*game)->path_bonus, 0);
	load_tab_of_image(game, &(*game)->door.img, (*game)->path_bonus, DN);
	load_image(game, &(*game)->sp.img, (*game)->path[S]);
	load_image(game, &(*game)->sp_foe.img, (*game)->path_bonus[SF]);
	load_image(game, &(*game)->sp_dead.img, (*game)->path_bonus[SD]);
	load_image(game, &(*game)->heart, (*game)->path_bonus[LIFE]);
	load_image(game, &(*game)->lose_game, (*game)->path_bonus[LOSE]);
	load_image(game, &(*game)->win_game, (*game)->path_bonus[WIN]);
	if ((*game)->save == TRUE)
		save_bmp(game);
	if (!((*game)->win = mlx_new_window(
	(*game)->mlx, (*game)->r[X], (*game)->r[Y], "Cub3D")))
		exit_error(game, NULL, MLX_ERR);
}
