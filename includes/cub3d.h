/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:15:00 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/08 15:34:23 by adbenoit         ###   ########.fr       */
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
# include "get_next_line.h"
# include <math.h>
# include "error.h"
# include "key.h"
# include "cub3d_macros.h"
# include "cub3d_struct.h"

# define TRUE 1
# define FALSE 0

void			finish_init(t_game **game, t_sprite *sp);
void			init_game(t_game **game);
void			init_player(t_game **game, char o);
void			init_player_pos(t_game **game, char *line, int i, int j);
void			set_sprite_coor(t_game **game, char *line, int i);
int				mlx_handle(t_game *game);

double			**realloc_doub(double **ptr, int newsize);
void			game_null(t_game **game);
void			clear_sprites(t_game **game);
void			clear_textures(t_game **game);
void			clear_bonus(t_game **game);
void			clear_utils(t_game **game);
void			exit_error(t_game **game, char *line, char *err);
void			exit_game(t_game **game);
void			free_tab_char(char **ptr);
void			free_tab_nb(void **ptr, int size);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_putnbr_fd(int n, int fd);
void			*ft_realloc(void *ptr, int newsize);
void			print_error(char *err);
char			*ft_strtrim(char *s1, char const *set, int size);
char			**realloc_tab(char **ptr, int newsize);
int				ft_atoi(const char *str);
int				ft_rgb(int r, int g, int b);
int				ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, int n);

void			ft_turnleft(t_game **game);
void			ft_turnright(t_game **game);
void			ft_forward(t_game **game, t_player *p);
void			ft_backward(t_game **game, t_player *p);
void			ft_rightward(t_game **game, t_player *p);
void			ft_leftward(t_game **game, t_player *p);

int				parse_color(t_game **game, char *line, int ident);
int				fill_col(char *line, char *col, int i);
int				fill_map(char *line, t_game **game);
int				fill_path(char *line, t_game **game, int i);
int				fill_res(char *line, int *i, int max);
int				parse_res(t_game **game, char *line);
int				read_file(t_game **game);
int				parse_info(char *line, t_game **game);
int				parse_map(char *line, t_game **game);
int				check_map_border(t_game **game);
int				check_map_end(t_game **game, char **map, int i);
int				open_file(char *arg, t_game **game, int save);

double			dist_screen(t_game **game, int x, int y);
double			set_wall_dist(t_game **game, t_wall *w);
void			add_dist(t_game **game, t_sprite *sp, void (*sort)(t_sprite *));
void			complete_text(t_game **game);
void			init_wall(t_game **game, t_wall *w);
void			ft_move(t_game **game);
void			draw_wall(t_game **game);
void			set_wall_side(t_game **game);
void			draw_sprite(t_game **game, t_sprite *sp);
void			load_image(t_game **game, t_img *img, char *path);
void			load_tab_of_image(t_game **game, t_tab_img *img, char **path,
				int start_game);
void			raycast_sprite(t_game **game, t_sprite *sp, t_img *sp_img);
void			draw_wall_pixel(t_game **game, t_tab_img *text, int i, int side);
void			save_bmp(t_game **game);
void			set_side_dist(t_game **game, t_wall *w);
void			sort_sprite(t_sprite *sp);
void			start_game(t_game **game);
int				create_image(t_game **game);
int				ft_close(t_game **game);
int				key_init(t_game **game);
int				ft_key_release(int key, t_game **game);
int				ft_key_press(int key, t_game **game);

int				parse_bonus(char *line, t_game **game);

#endif
