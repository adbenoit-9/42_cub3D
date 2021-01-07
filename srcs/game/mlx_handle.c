/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:42:36 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/08 14:40:15 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_handle(t_game *game)
{
	mlx_hook(game->win, 17, 1L << 17, ft_close, &game);
	mlx_hook(game->win, KEY_PRESS, 1L << 0, ft_key_press, &game);
	mlx_hook(game->win, KEY_RELEASE, 1L << 1, ft_key_release, &game);
	mlx_loop_hook(game->mlx, &create_window, &game);
	mlx_loop(game->mlx);
	return (NO_ERR);
}
