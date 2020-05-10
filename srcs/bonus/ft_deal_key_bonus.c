/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:32:27 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/08 15:48:44 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_press(int key, t_all **all)
{
	if (key == ESC)
		ft_error(all, NULL, NO_ERR);
	if (key == SPACE && (*all)->bonus.life != 0 && (*all)->bonus.foe != 0)
		(*all)->key.space = 1;
	if (key == LEFT && (*all)->bonus.life != 0 && (*all)->bonus.foe != 0)
		(*all)->key.left = 1;
	if (key == RIGHT && (*all)->bonus.life != 0 && (*all)->bonus.foe != 0)
		(*all)->key.right = 1;
	if (key == KEY_W && (*all)->bonus.life != 0 && (*all)->bonus.foe != 0)
		(*all)->key.w = 1;
	if (key == KEY_A && (*all)->bonus.life != 0 && (*all)->bonus.foe != 0)
		(*all)->key.a = 1;
	if (key == KEY_S && (*all)->bonus.life != 0 && (*all)->bonus.foe != 0)
		(*all)->key.s = 1;
	if (key == KEY_D && (*all)->bonus.life != 0 && (*all)->bonus.foe != 0)
		(*all)->key.d = 1;
	if (key == KEY_F && (*all)->bonus.life != 0 && (*all)->bonus.foe != 0)
		(*all)->key.f = 1;
	return (NO_ERR);
}

int	ft_key_release(int key, t_all **all)
{
	if (key == SPACE)
		(*all)->key.space = 0;
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
	if (key == KEY_F)
		(*all)->key.f = 0;
	return (NO_ERR);
}

int		ft_close(t_all **all)
{
	ft_error(all, NULL, NO_ERR);
	return (NO_ERR);
}