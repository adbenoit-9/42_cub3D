/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 20:23:18 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/03 14:50:55 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "utils.h"
# include <math.h>
# include "error.h"
# include "key.h"
# include "cub3d_macros.h"
# include "cub3d_struct.h"

# define TRUE 1
# define FALSE 0

int				fill_map(char *line, t_game **game);
int				fill_path(char *line, t_game **game, char **path);
int				fill_res(char *line, int *i, int max);
int				finish_parse_map(t_game **game);
int				parse_color(t_game **game, char *line, int ident);
int				parse_file(char *arg, t_game **game, int save);
int				parse_info(char *line, t_game **game);
int				parse_map(char *line, t_game **game);
int				parse_res(t_game **game, char *line);
int				read_file(t_game **game);

int				create_image(t_game **game);
void			finish_init(t_game **game, t_sprite *sp);
void			init_game(t_game **game);
void			init_player_dir(t_game **game, char o);
void			init_sprite(t_game **game);
void			load_image(t_game **game, t_img *img, char *path);
void			load_tab_of_image(t_game **game, t_tab_img *img, char **path,
				int start_game);
void			save_bmp(t_game **game);
int				mlx_handle(t_game *game);

double			dist_screen(t_game **game, int x, int y);
double			set_wall_dist(t_game **game, t_wall *w);
void			add_dist(t_game **game, t_sprite *sp, void (*sort)(t_sprite *));
void			complete_text(t_game **game);
void			draw_sprite(t_game **game, t_sprite *sp);
void			draw_wall(t_game **game);
void			draw_wall_pixel(t_game **game, t_tab_img *text, int i,
				int side);
void			init_wall(t_game **game, t_wall *w);
void			raycast_sprite(t_game **game, t_sprite *sp, t_img *sp_img);
void			set_side_dist(t_game **game, t_wall *w);
void			set_wall_side(t_game **game);
void			sort_sprite(t_sprite *sp);
void			start_game(t_game **game);

void			ft_move(t_game **game);
void			ft_turnleft(t_game **game);
void			ft_turnright(t_game **game);
void			ft_forward(t_game **game, t_player *p);
void			ft_backward(t_game **game, t_player *p);
void			ft_rightward(t_game **game, t_player *p);
void			ft_leftward(t_game **game, t_player *p);
int				ft_close(t_game **game);
int				ft_key_release(int key, t_game **game);
int				ft_key_press(int key, t_game **game);
int				key_init(t_game **game);

void			clear_sprites(t_game **game);
void			clear_textures(t_game **game);
void			clear_utils(t_game **game);
void			exit_error(t_game **game, char *line, char *err);
void			exit_game(t_game **game);
void			print_error(char *err);

#endif
