/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:17:17 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/08 15:26:07 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_key_press(int key, t_game **game)
{
	if (key == ESC)
		exit_game(game);
	if (key == SPACE && (*game)->life != 0 && (*game)->nb_foe != 0)
		(*game)->key.space = TRUE;
	if (key == LEFT && (*game)->life != 0 && (*game)->nb_foe != 0)
		(*game)->key.left = TRUE;
	if (key == RIGHT && (*game)->life != 0 && (*game)->nb_foe != 0)
		(*game)->key.right = TRUE;
	if (key == KEY_W && (*game)->life != 0 && (*game)->nb_foe != 0)
		(*game)->key.w = TRUE;
	if (key == KEY_A && (*game)->life != 0 && (*game)->nb_foe != 0)
		(*game)->key.a = TRUE;
	if (key == KEY_S && (*game)->life != 0 && (*game)->nb_foe != 0)
		(*game)->key.s = TRUE;
	if (key == KEY_D && (*game)->life != 0 && (*game)->nb_foe != 0)
		(*game)->key.d = TRUE;
	if (key == KEY_F && (*game)->life != 0 && (*game)->nb_foe != 0)
		deal_door(game);
	return (NO_ERR);
}

int	ft_key_release(int key, t_game **game)
{
	if (key == SPACE)
		(*game)->key.space = FALSE;
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
