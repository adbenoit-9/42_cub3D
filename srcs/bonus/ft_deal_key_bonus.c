/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:17:17 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/29 21:36:04 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_key_press(int key, t_all **all)
{
	if (key == ESC)
		exit_game(all);
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

int	ft_close(t_all **all)
{
	exit_game(all);
	return (NO_ERR);
}
