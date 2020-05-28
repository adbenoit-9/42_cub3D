/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:48:03 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/27 22:59:07 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		exit_game(t_all **all)
{
	clear_sprites(all);
	clear_img(all);
	clear_textures(all);
	clear_utils(all);
	write(1, "Game exit.\n", 21);
	exit(EXIT_SUCCESS);
}

void		exit_error(t_all **all, char *line, int code)
{
	free(line);
	line = NULL;
	clear_sprites(all);
	clear_img(all);
	clear_textures(all);
	clear_utils(all);
	print_error(code);
}

void		print_error(int err)
{
	char *err_mess[NB_ERR] = {"Failed to load map.", "failed to load image.", "Failed to find color", "Failed to open file", "failed to malloc.",
							"Please enter corrects arguments.", "mlx failed to create window or image.", "Failed to find resolution"};

	if (err >= 0)
	{
		write(1, "Error\n", 6);
		write(1, err_mess[err], ft_strlen(err_mess[err])); 
		write (1, "\n", 1);
	}
	exit(EXIT_FAILURE);
}