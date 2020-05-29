/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:11:18 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/29 16:27:20 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		exit_game(t_all **all)
{
	clear_sprites(all);
	clear_img(all);
	clear_textures(all);
	clear_utils(all);
	write(1, "Game exit.\n", 11);
	exit(EXIT_SUCCESS);
}

void		exit_error(t_all **all, char *line, char *err)
{
	free(line);
	line = NULL;
	clear_sprites(all);
	clear_img(all);
	clear_textures(all);
	clear_utils(all);
	print_error(err);
}

void		print_error(char *err)
{
	write(1, "Error\n", 6);
	write(1, err, ft_strlen(err));
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}
