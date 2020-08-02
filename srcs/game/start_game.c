/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:43:24 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/02 23:34:17 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_game(t_game **game)
{
	if (!((*game)->mlx = mlx_init()))
		exit_error(game, NULL, MLX_ERR);
	if (!((*game)->win = mlx_new_window((*game)->mlx,
					(*game)->r[X], (*game)->r[Y], "Cub3D")))
		exit_error(game, NULL, MLX_ERR);
	finish_init(game, &(*game)->sp);
	init_player_dir(game, (*game)->player.start_o);
	load_tab_of_image(game, &(*game)->text, (*game)->path, 0);
	load_image(game, &(*game)->sp.img, (*game)->path[S]);
	create_image(game);
	if ((*game)->save == TRUE)
		save_bmp(game);
}
