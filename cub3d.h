/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:45:39 by adbenoit          #+#    #+#             */
/*   Updated: 2020/03/12 20:02:02 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./minilibx_opengl_20191021/mlx.h"
# include "get_next_line.h"
# include <math.h>

# define INF_NO "NO"
# define INF_SO "SO"
# define INF_WE "WE"
# define INF_EA "EA"
# define INF_S "S"
# define INF_R "R"
# define INF_F "F"
# define INF_C "C"

# define NB_INFO 8

# define NO 3
# define SO 1
# define WE 2
# define EA 0
# define S 4
# define R 5
# define F 6
# define C 7

# define WALL '1'
# define OBJ '2'
# define EMPT '0'
# define HOLE '3'
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'

# define NB_CHAR 8

# define END_MAP -3
# define END_INFO -2
# define NO_ERR -1
# define PARS_ERR 0
# define FILE_ERR 1
# define MAL_ERR 2

# define NB_ERR 2

# define BUFFER_SIZE 4096

# define X 0
# define Y 1

# define ESC 53
# define RIGHT 124
# define LEFT 123
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_PRESS 2
# define KEY_RELEASE 3

# define ROTSPEED 0.1
# define MOVESPEED 0.2

enum	e_state
{
	INFO,
	MAP,
	END
};

typedef struct	s_player
{
	double	map[2];
	double	dir[2];
	double	old_dir[2];
	double	pos[2];
	char	o;
}				t_player;

typedef struct	s_wall
{
	double	angle;
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
	void	*ptr;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_text
{
	int		dim[2];
	int		pos[2];
	void	*ptr;
	int		*data[4];
	int		bpp;
	int		size_line;
	int		endian;
}				t_text;

typedef struct	s_sprite
{
	int		dim[2];
	void	*ptr;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
	double	**pos;
	double	**coor;
	int		count;
	double	*dist;
	int		w;
	int		h;
	int		screen;
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
	int	w;
	int	a;
	int	s;
	int	d;
}				t_key;

typedef struct	s_all
{
	char			**info;
	char			**map;
	int				r[2];
	int				f;
	int				c;
	int				i_map;
	int				pos;
	int				err;
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
	t_text			text;
	t_sprite		sp;

}				t_all;

typedef int		(*t_function)(char *, t_all **);

int				ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, int n);
int				ft_parsing(t_all **all);
int				open_f(char *arg, t_all **all, int save);
int				map(char *line, t_all **all);
int				info(char *line, t_all **all);
void			ft_putnbr_fd(int n, int fd);
int				map_end_error(t_all **all);
int				print_err(int err);
int				map_error(t_all **all, char *line);
int				ft_error(t_all **all, char *line, int err);
char			*ft_realloc(char *ptr, int newsize);
char			**realloc_tab(char **ptr, int newsize);
void			free_tab(char **tab);
int				ft_atoi(const char *str);
int				add_r(t_all **all, char *line);
int				add_col(t_all **all, char *line, int ident);
char			*ft_trim(char *s1, char set);
char			*ft_strtrim(char *s1, char const *set, int size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_rgb(int r, int g, int b);
double			dist_screen(t_all **all, int x, int y);
int				start(t_all **all);
void			hit_wall(t_all **all);
double			wall_dist(t_all **all);
int				ft_deal_key(int key, t_all **all);
int				ft_key_press(int key, t_all **all);
int				create_image(t_all **all);
void			put_text(t_all **all);
void			complete_text(t_all **all);
void			complete_wall_inf(t_all **all);
void			side_dist(t_all **all);
double			**realloc_doub(double **ptr, int newsize);
void			put_sprite(t_all **all);
void			raycast_sprite(t_all **all);
void			save_bmp(t_all **all);
void			ft_bzero(void *s, size_t n);
void			ft_view(t_all **all);
void			direct_wa(t_all **all);
void			direct_sd(t_all **all);
void			ft_move(t_all **all);
int				ft_close(t_all **all);

#endif
