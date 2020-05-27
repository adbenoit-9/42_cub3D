/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:45:39 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/27 22:59:31 by Adeline          ###   ########.fr       */
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

# define INF_NO "NO "
# define INF_SO "SO "
# define INF_WE "WE "
# define INF_EA "EA "
# define INF_S "S "
# define INF_R "R "
# define INF_F "F "
# define INF_C "C "

# define BON_P0 "P0 "
# define BON_P1 "P1 "
# define BON_P2 "P2 "
# define BON_P3 "P3 "
# define BON_P4 "P4 "
# define BON_S1 "S1 "
# define BON_SA "SA "
# define BON_DN "DN "
# define BON_DS "DS "
# define BON_DE "DE "
# define BON_DW "DW "
# define BON_LIFE "LI "
# define BON_LOSE "LO "
# define BON_WIN "WI "

# define NB_INFO 8
# define NB_BON 14

# define NO 1
# define SO 3
# define WE 0
# define EA 2
# define S 4
# define R 5
# define F 6
# define C 7

# define P0 0
# define P1 1
# define P2 2
# define P3 3
# define P4 4
# define S1 5
# define SA 6
# define DN 7
# define DS 8
# define DE 9
# define DW 10
# define LIFE 11
# define LOSE 12
# define WIN 13

# define WALL '1'
# define OBJ '2'
# define EMPT '0'
# define HOLE ' '
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'
# define OBJ1 '3'
# define DOOR 'D'
# define OPEN 'O'
# define WALL_DOOR 'R'
# define DEAD 'X'

# define NB_CHAR 8
# define NB_CHAR_B 10

# define END_INFO -2
# define NO_ERR -1
# define PARS_ERR 0
# define FILE_ERR 1
# define MAL_ERR 2
# define ARG_ERR 3
# define PATH_ERR 4
# define MLX_ERR 5

# define NB_ERR 6

# define BUFFER_SIZE 4096

# define X 0
# define Y 1

# define ESC 53
# define TAB 48
# define SPACE 49
# define RIGHT 124
# define LEFT 123
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_MOUSE 2

# define ROTSPEED 0.05
# define MOVESPEED 0.1

enum	e_state
{
	INFO,
	BONUS,
	MAP,
	END
};

typedef struct	s_player
{
	double	map[2];
	double	dir[2];
	double	old_dir[2];
	char	o;
}				t_player;

typedef struct	s_wall
{
	double	delta_dist[2];
	double	side_dist[2];
	double	*dist;
	int		slice_h;
	double	raydir[2];
	double	camx;
	int		step[2];
	int		pos[2];
	int		side;
	double	hit;
}				t_wall;

typedef struct	s_grid
{
	double	plane[2];
	double	old_plane[2];
	int		column;

}				t_grid;

typedef struct	s_img
{
	int		dim[2];
	void	*ptr;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_tab_img
{
	int		dim[4][2];
	int		pos[2];
	void	*ptr[4];
	int		*data[4];
	int		bpp;
	int		size_line;
	int		endian;
}				t_tab_img;

typedef struct	s_sprite
{
	t_img	img;
	double	**pos;
	double	**coor;
	int		count;
	double	*dist;
	int		w;
	int		h;
	int		screen;
	int		*dead;
	int		*see;
	char	*type;
	int		index;
	double	transf[2];
}				t_sprite;

typedef struct	s_im_head
{
	int			size_imh;
	int			w;
	int			h;
	short		plan;
	short		bpp;
	int			comp;
	int			sizeim;
	int			hres;
	int			vres;
	int			cpalette;
	int			cipalette;
}				t_im_head;

typedef struct s_bmp
{
	char		sign[2];
	int			size;
	int			rsv;
	int			offset;
	t_im_head	im_head;
}				t_bmp;

typedef struct	s_key
{
	int	left;
	int	right;
	int	tab;
	int space;
	int	w;
	int	a;
	int	s;
	int	d;
	int f;
}				t_key;

typedef struct	s_bonus
{
	int				loop;
	int				loop2;
	t_tab_img		weap;
	t_tab_img		door;
	char			door_tmp;
	int				door_side;
	char			*path[NB_BON + 1];
	int				pull;
	int				life;
	t_img			heart;
	t_sprite		s1;
	t_sprite		sa;
	t_img			dead;
	t_img			win;
	int				foe;
	int				col;
	char			c;
}				t_bonus;

typedef struct	s_all
{
	char			*info[6];
	char			**map;
	int				r[2];
	int				f;
	int				c;
	int				i_map;
	int				pos;
	int				fd;
	int				ret;
	int				save;
	t_key			key;
	enum e_state	state;
	t_player		player;
	void			*mlx;
	void			*win;
	t_grid			grid;
	t_wall			wall;
	t_img			img;
	t_tab_img		text;
	t_sprite		sp;
	t_bonus			bonus;
	double 			invdet;

}				t_all;

typedef int		(*t_function)(char *, t_all **);

void	init_all(t_all **all);
int		mlx_handle(t_all *all);
void    complete_all(t_all **all, t_sprite *sp);
void 	ft_putdir(t_all **all, char o);

//utils
double			**realloc_doub(double **ptr, int newsize);
void			all_null(t_all **all);
void			free_tab_char(char **ptr, int alloc);
void			free_tab_nb(void **ptr, int size, int alloc);
void			ft_bzero(void *s, size_t n);
void			exit_game(t_all **all, char *line, int err);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_putnbr_fd(int n, int fd);
void			*ft_realloc(void *ptr, int newsize);
void			print_err(int err);
char			*ft_strtrim(char *s1, char const *set, int size);
char			**realloc_tab(char **ptr, int newsize);
int				ft_atoi(const char *str);
int				ft_rgb(int r, int g, int b);
int				ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, int n);


//move
void			ft_turnleft(t_all **all);
void			ft_turnright(t_all **all);
void			ft_forward(t_all **all);
void			ft_backward(t_all **all);
void			ft_rightward(t_all **all);
void			ft_leftward(t_all **all);

//parsing
int				add_col(t_all **all, char *line, int ident);
int				add_r(t_all **all, char *line);
int				ft_parsing(t_all **all);
int				info(char *line, t_all **all);
int				map(char *line, t_all **all);
int				map_end_error(t_all **all);
int				map_error(t_all **all);
int				open_f(char *arg, t_all **all, int save);

//raycasting
double			dist_screen(t_all **all, int x, int y);
double			wall_dist(t_all **all, t_wall *wall);
void			add_dist(t_all **all, t_sprite *sp, void (*sort)(t_sprite *));
void			complete_text(t_all **all);
void			complete_wall_inf(t_all **all, t_wall *wall);
void			ft_move(t_all **all);
void			ft_wall(t_all **all);
void			hit_wall(t_all **all);
void			print_sprite(t_all **all, t_sprite *sp);
void    		put_img(t_all **all, t_img *img, char *path);
void			put_tab_img(t_all **all, t_tab_img *tab_img, char **path, int start);
void			raycast_sprite(t_all **all, t_sprite *sp, t_img *sp_img);
void			raycast_wall(t_all **all, int column);
void			save_bmp(t_all **all);
void			side_dist(t_all **all, t_wall *wall);
void			sort_sprite(t_sprite *sp);
void			start(t_all **all);
int				create_image(t_all **all);
int				ft_close(t_all **all);
int 			key_init(t_all **all);
int				ft_key_release(int key, t_all **all);
int				ft_key_press(int key, t_all **all);


//bonus
void			add_mini_map(t_all **all);
void 			check_door(t_all **all);
void			open_door(t_all **all);
void			ft_door(t_all **all);
void			ft_pull_weapon(t_all **all);
void			init_all_sprite(t_all **all, t_sprite *sp);
void    		lose_life(t_all **all, char c);
void			print_all_sprites(t_all **all, t_sprite *sp);
void    		print_play_again(t_all **all, t_img *im, int k1, int k2);
void    		print_hearts(t_all **all);
void    		print_weapon(t_all **all, int pull);
void			put_all_sprites(t_all **all);
void			put_door(t_all **all);
void    		put_weapon(t_all **all);
int				bonus(char *line, t_all **all);
int     		ft_mouse(int button, int x, int y, t_all **all);

#endif
