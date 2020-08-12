/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:16:38 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/04 17:51:23 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	ray_casting(t_game **game)
{
	(*game)->screen.x = 0;
	ft_move(game);
	draw_door(game);
	draw_sprite(game, &(*game)->sp);
	draw_weapon(game, &(*game)->weap.img);
	draw_mini_map(game);
	draw_hearts(game);
	draw_target(game);
	if ((*game)->nb_foe == 0)
		draw_replay(game, &(*game)->win_game, 1, 1);
}

void		create_image(t_game **game)
{
	(*game)->loop[1]++;
	(*game)->loop[0]++;
	if ((*game)->img.ptr != NULL)
	{
		mlx_destroy_image((*game)->mlx, (*game)->img.ptr);
		(*game)->img.ptr = NULL;
	}
	(*game)->img.ptr = mlx_new_image((*game)->mlx, (*game)->r[X],
						(*game)->r[Y]);
	(*game)->img.bpp = 32;
	(*game)->img.size_line = (*game)->r[X] * 4;
	(*game)->img.endian = 0;
	(*game)->img.data = (int *)mlx_get_data_addr((*game)->img.ptr,
		&(*game)->img.bpp, &(*game)->img.size_line, &(*game)->img.endian);
	ray_casting(game);
}

int			create_window(t_game **game)
{
	int i;

	create_image(game);
	mlx_put_image_to_window((*game)->mlx, (*game)->win,
		(*game)->img.ptr, 0, 0);
	i = -1;
	while (++i < (*game)->sp.count)
		(*game)->sp.see[i] = 0;
	return (NO_ERR);
}
