/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:32:27 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/28 14:30:52 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_press(int key, t_all **all)
{
	if (key == ESC)
		exit_error(all, NULL, NO_ERR);
	if (key == SPACE && (*all)->bonus.life != 0 && (*all)->bonus.foe != 0)
		(*all)->key.space = TRUE;
	if (key == LEFT && (*all)->bonus.life != 0 && (*all)->bonus.foe != 0)
		(*all)->key.left = TRUE;
	if (key == RIGHT && (*all)->bonus.life != 0 && (*all)->bonus.foe != 0)
		(*all)->key.right = TRUE;
	if (key == KEY_W && (*all)->bonus.life != 0 && (*all)->bonus.foe != 0)
		(*all)->key.w = TRUE;
	if (key == KEY_A && (*all)->bonus.life != 0 && (*all)->bonus.foe != 0)
		(*all)->key.a = TRUE;
	if (key == KEY_S && (*all)->bonus.life != 0 && (*all)->bonus.foe != 0)
		(*all)->key.s = TRUE;
	if (key == KEY_D && (*all)->bonus.life != 0 && (*all)->bonus.foe != 0)
		(*all)->key.d = TRUE;
	if (key == KEY_F && (*all)->bonus.life != 0 && (*all)->bonus.foe != 0)
		open_door(all);
	return (NO_ERR);
}

int	ft_key_release(int key, t_all **all)
{
	if (key == SPACE)
		(*all)->key.space = FALSE;
	if (key == LEFT)
		(*all)->key.left = FALSE;
	if (key == RIGHT)
		(*all)->key.right = FALSE;
	if (key == KEY_W)
		(*all)->key.w = FALSE;
	if (key == KEY_A)
		(*all)->key.a = FALSE;
	if (key == KEY_S)
		(*all)->key.s = FALSE;
	if (key == KEY_D)
		(*all)->key.d = FALSE;
	return (NO_ERR);
}

int		ft_close(t_all **all)
{
	exit_error(all, NULL, NO_ERR);
	return (NO_ERR);
}