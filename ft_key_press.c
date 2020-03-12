/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:32:27 by adbenoit          #+#    #+#             */
/*   Updated: 2020/03/12 19:59:32 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int	ft_key_press(int key, t_all **all)
{
	if (key == ESC)
	{
		mlx_destroy_window((*all)->mlx, (*all)->win);
		exit(EXIT_SUCCESS);
	}
	if (key == LEFT)
		(*all)->key.left = 1;
	if (key == RIGHT)
		(*all)->key.right = 1;
	if (key == KEY_W)
		(*all)->key.w = 1;
	if (key == KEY_A)
		(*all)->key.a = 1;
	if (key == KEY_S)
		(*all)->key.s = 1;
	if (key == KEY_D)
		(*all)->key.d = 1;
	ft_move(all);
	return (0);
}

int	ft_close(t_all **all)
{
	mlx_destroy_window((*all)->mlx, (*all)->win);
	exit(EXIT_SUCCESS);
	/*if (button == CLOSE)
	{
		mlx_destroy_window((*all)->mlx, (*all)->win);
		exit(EXIT_SUCCESS);
	}*/
	return (0);
}