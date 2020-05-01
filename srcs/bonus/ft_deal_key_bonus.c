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

#include "cub3d.h"

int	ft_key_press(int key, t_all **all)
{
	if (key == ESC)
		ft_error(all, NULL, NO_ERR);
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
	return (NO_ERR);
}

int	ft_key_release(int key, t_all **all)
{
	if (key == LEFT)
		(*all)->key.left = 0;
	if (key == RIGHT)
		(*all)->key.right = 0;
	if (key == KEY_W)
		(*all)->key.w = 0;
	if (key == KEY_A)
		(*all)->key.a = 0;
	if (key == KEY_S)
		(*all)->key.s = 0;
	if (key == KEY_D)
		(*all)->key.d = 0;
	return (NO_ERR);
}

int		ft_close(t_all **all)
{
	ft_error(all, NULL, NO_ERR);
	return (NO_ERR);
}