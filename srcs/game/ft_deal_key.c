/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:42:29 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/08 14:39:06 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_press(int key, t_game **game)
{
	if (key == ESC)
		exit_game(game);
	if (key == LEFT)
		(*game)->key.left = TRUE;
	if (key == RIGHT)
		(*game)->key.right = TRUE;
	if (key == KEY_W)
		(*game)->key.w = TRUE;
	if (key == KEY_A)
		(*game)->key.a = TRUE;
	if (key == KEY_S)
		(*game)->key.s = TRUE;
	if (key == KEY_D)
		(*game)->key.d = TRUE;
	return (NO_ERR);
}

int	ft_key_release(int key, t_game **game)
{
	if (key == LEFT)
		(*game)->key.left = FALSE;
	if (key == RIGHT)
		(*game)->key.right = FALSE;
	if (key == KEY_W)
		(*game)->key.w = FALSE;
	if (key == KEY_A)
		(*game)->key.a = FALSE;
	if (key == KEY_S)
		(*game)->key.s = FALSE;
	if (key == KEY_D)
		(*game)->key.d = FALSE;
	return (NO_ERR);
}

int	ft_close(t_game **game)
{
	exit_game(game);
	return (NO_ERR);
}
