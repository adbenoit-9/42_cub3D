/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:15:00 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/31 17:31:50 by adbenoit         ###   ########.fr       */
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

void			finish_init(t_all **all, t_sprite *sp);
void			init_game(t_all **all);
void			init_player(t_all **all, char o);
void			init_player_pos(t_all **all, char *line, int i, int j);
void			set_sprite_coor(t_all **all, char *line, int i);
int				mlx_handle(t_all *all);

double			**realloc_doub(double **ptr, int newsize);
void			all_null(t_all **all);
void			clear_sprites(t_all **all);
void			clear_textures(t_all **all);
void			clear_bonus(t_all **all);
void			clear_utils(t_all **all);
void			exit_error(t_all **all, char *line, char *err);
void			exit_game(t_all **all);
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

void			ft_turnleft(t_all **all);
void			ft_turnright(t_all **all);
void			ft_forward(t_all **all, t_player *p);
void			ft_backward(t_all **all, t_player *p);
void			ft_rightward(t_all **all, t_player *p);
void			ft_leftward(t_all **all, t_player *p);

int				parse_color(t_all **all, char *line, int ident);
int				fill_col(char *line, char *col, int i);
int				fill_map(char *line, t_all **all);
int				fill_path(char *line, t_all **all, int i);
int				fill_res(char *line, int *i, int max);
int				parse_res(t_all **all, char *line);
int				read_file(t_all **all);
int				parse_info(char *line, t_all **all);
int				parse_map(char *line, t_all **all);
int				check_map_border(t_all **all);
int				check_map_end(t_all **all, char **map, int i);
int				open_file(char *arg, t_all **all, int save);

double			dist_screen(t_all **all, int x, int y);
double			set_wall_dist(t_all **all, t_wall *w);
void			add_dist(t_all **all, t_sprite *sp, void (*sort)(t_sprite *));
void			complete_text(t_all **all);
void			init_wall(t_all **all, t_wall *w);
void			ft_move(t_all **all);
void			draw_wall(t_all **all);
void			set_wall_side(t_all **all);
void			draw_sprite(t_all **all, t_sprite *sp);
void			load_image(t_all **all, t_img *img, char *path);
void			load_tab_of_image(t_all **all, t_tab_img *img, char **path, int start_game);
void			raycast_sprite(t_all **all, t_sprite *sp, t_img *sp_img);
void			draw_wall_pixel(t_all **all, t_tab_img *text, int i);
void			save_bmp(t_all **all);
void			set_side_dist(t_all **all, t_wall *w);
void			sort_sprite(t_sprite *sp);
void			start_game(t_all **all);
int				create_image(t_all **all);
int				ft_close(t_all **all);
int				key_init(t_all **all);
int				ft_key_release(int key, t_all **all);
int				ft_key_press(int key, t_all **all);

int				parse_bonus(char *line, t_all **all);

#endif
