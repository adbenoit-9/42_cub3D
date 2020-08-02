/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 14:58:52 by Adeline           #+#    #+#             */
/*   Updated: 2020/08/02 15:31:48 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d_struct.h"
# include "cub3d_macros_bonus.h"

enum	e_state
{
	INFO,
	BONUS,
	MAP,
	END
};

typedef struct	s_game
{
	enum e_state	state;
	char			**map;
	char			**path;
	char			**path_bonus;
	int				r[2];
	int				f;
	int				c;
	void			*mlx;
	void			*win;
	char			map_c;
	int				map_size;
	int				loop[2];
	int				save;
	int				fd;
	int				ret;
	t_img			img;
	t_wall			wall;
	t_screen		screen;
	t_player		player;
	t_tab_img		text;
	t_sprite		sp;
	t_sprite		sp_foe;
	t_sprite		sp_dead;
	t_img			heart;
	t_img			lose_game;
	t_img			win_game;
	t_weap			weap;
	t_door			door;
	t_key			key;
	double			invdet;
	int				mm_dim;
	int				life;
	int				nb_foe;
	int				hit;
}				t_game;

# include "cub3d_utils.h"

typedef int	(*t_function)(char *, t_game **);

void	        clear_image(t_game **game);
void			deal_door(t_game **game);
void			draw_door(t_game **game);
void			draw_hearts(t_game **game);
void			draw_mini_map(t_game **game);
void			draw_replay(t_game **game, t_img *im, int k1, int k2);
void			draw_weapon(t_game **game, t_tab_img *weap);
void			manage_life(t_game **game, char c);
int				ft_mouse(int button, int x, int y, t_game **game);

#endif
