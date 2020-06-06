/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:18:19 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/06 22:48:26 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	mlx_handle(t_all *all)
{
	mlx_hook(all->win, 17, 1L << 0, ft_close, &all);
	mlx_hook(all->win, KEY_PRESS, 1L << 0, ft_key_press, &all);
	mlx_hook(all->win, KEY_RELEASE, 1L << 1, ft_key_release, &all);
	mlx_mouse_hook(all->win, ft_mouse, &all);
	mlx_loop_hook(all->mlx, &create_image, &all);
	mlx_loop(all->mlx);
	return (NO_ERR);
}
