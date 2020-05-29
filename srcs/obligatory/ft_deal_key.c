/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:42:29 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/29 17:42:49 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_press(int key, t_all **all)
{
	if (key == ESC)
		exit_game(all);
	if (key == LEFT)
		(*all)->key.left = TRUE;
	if (key == RIGHT)
		(*all)->key.right = TRUE;
	if (key == KEY_W)
		(*all)->key.w = TRUE;
	if (key == KEY_A)
		(*all)->key.a = TRUE;
	if (key == KEY_S)
		(*all)->key.s = TRUE;
	if (key == KEY_D)
		(*all)->key.d = TRUE;
	return (NO_ERR);
}

int	ft_key_release(int key, t_all **all)
{
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
