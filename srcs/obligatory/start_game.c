/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:43:24 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/06 22:48:26 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_game(t_all **all)
{
	if (!((*all)->mlx = mlx_init()))
		exit_error(all, NULL, MLX_ERR);
	if (!((*all)->win = mlx_new_window((*all)->mlx,
					(*all)->r[X], (*all)->r[Y], "Cub3D")))
		exit_error(all, NULL, MLX_ERR);
	finish_init(all, &(*all)->sp);
	init_player(all, (*all)->player.start_o);
	(*all)->screen.plane[X] = ((*all)->player.dir[X] == 0) ? 0.66 : 0;
	(*all)->screen.plane[Y] = ((*all)->player.dir[Y] == 0) ? 0.66 : 0;
	load_tab_of_image(all, &(*all)->text, (*all)->path, 0);
	load_image(all, &(*all)->sp.img, (*all)->path[S]);
	create_image(all);
	if ((*all)->save == TRUE)
		save_bmp(all);
}
