/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:15:00 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/01 18:34:58 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_struct.h"

enum	e_state
{
	INFO,
	MAP,
	END
};

typedef struct	s_game
{
	enum e_state	state;
	char			**map;
	char			**path;
	int				r[2];
	int				f;
	int				c;
	void			*mlx;
	void			*win;
	char			map_c;
	int				map_size;
	int				save;
	int				fd;
	int				ret;
	t_img			img;
	t_wall			wall;
	t_screen		screen;
	t_player		player;
	t_tab_img		text;
	t_sprite		sp;
	t_key			key;
	double			invdet;
}				t_game;

# include "cub3d_utils.h"

typedef int	(*t_function)(char *, t_game **);

#endif
