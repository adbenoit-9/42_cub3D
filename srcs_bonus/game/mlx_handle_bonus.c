/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:18:19 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/08 14:40:15 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	mlx_handle(t_game *game)
{
	mlx_hook(game->win, 17, 1L << 0, ft_close, &game);
	mlx_hook(game->win, KEY_PRESS, 1L << 0, ft_key_press, &game);
	mlx_hook(game->win, KEY_RELEASE, 1L << 1, ft_key_release, &game);
	mlx_mouse_hook(game->win, ft_mouse, &game);
	mlx_loop_hook(game->mlx, &create_image, &game);
	mlx_loop(game->mlx);
	return (NO_ERR);
}
