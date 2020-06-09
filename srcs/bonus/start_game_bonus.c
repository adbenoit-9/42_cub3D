/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:21:45 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/08 15:38:50 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	start_game(t_game **game)
{
	if (!((*game)->mlx = mlx_init()))
		exit_error(game, NULL, MLX_ERR);
	if (!((*game)->win = mlx_new_window(
	(*game)->mlx, (*game)->r[X], (*game)->r[Y], "Cub3D")))
		exit_error(game, NULL, MLX_ERR);
	check_door(game);
	finish_init(game, &(*game)->sp);
	init_player(game, (*game)->player.start_o);
	(*game)->screen.plane[X] = ((*game)->player.dir[X] == 0) ? 0.66 : 0;
	(*game)->screen.plane[Y] = ((*game)->player.dir[Y] == 0) ? 0.66 : 0;
	load_tab_of_image(game, &(*game)->text, (*game)->path, 0);
	load_tab_of_image(game, &(*game)->weap.img, (*game)->path_bonus, 0);
	load_tab_of_image(game, &(*game)->door.img, (*game)->path_bonus, DN);
	load_image(game, &(*game)->sp.img, (*game)->path[S]);
	load_image(game, &(*game)->sp_foe.img, (*game)->path_bonus[SF]);
	load_image(game, &(*game)->sp_dead.img, (*game)->path_bonus[SD]);
	load_image(game, &(*game)->heart, (*game)->path_bonus[LIFE]);
	load_image(game, &(*game)->lose_game, (*game)->path_bonus[LOSE]);
	load_image(game, &(*game)->win_game, (*game)->path_bonus[WIN]);
	create_image(game);
	if ((*game)->save == TRUE)
		save_bmp(game);
}
