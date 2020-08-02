/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:11:18 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/02 23:38:03 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		exit_game(t_game **game)
{
	clear_sprites(game);
	clear_textures(game);
	clear_utils(game);
	write(1, "Game exit.\n", 11);
	exit(EXIT_SUCCESS);
}

void		exit_error(t_game **game, char *line, char *err)
{
	printf("line = %s\n", line);
	free(line);
	line = NULL;
	clear_sprites(game);
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
