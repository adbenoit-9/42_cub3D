/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:10:07 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/09 15:25:08 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		exit_game(t_game **game)
{
	clear_sprites(game);
	clear_image(game);
	clear_textures(game);
	clear_utils(game);
	write(1, "Game exit.\n", 11);
	exit(EXIT_SUCCESS);
}

void		exit_error(t_game **game, char *line, char *err)
{
	free(line);
	line = NULL;
	clear_sprites(game);
	clear_image(game);
	clear_textures(game);
	clear_utils(game);
	print_error(err);
}

void		print_error(char *err)
{
	write(1, "Error\n", 6);
	write(1, err, ft_strlen(err));
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}
