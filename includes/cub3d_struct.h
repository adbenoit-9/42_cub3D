/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:14:51 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/03 14:36:26 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

enum	e_state
{
	INFO,
	MAP,
	END
};

typedef struct	s_draw
{
	int	start[2];
	int	end[2];
	int	pix[2];
	int	index[2];
	int	h;
	int	w;
}				t_draw;

typedef struct	s_player
{
	double	pos[2];
	double	dir[2];
	double	old_dir[2];
	char	start_o;
	int		start_pos;
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

typedef struct	s_screen
{
	double	plane[2];
	double	old_plane[2];
	int		x;

}				t_screen;

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
	int		pix[2];
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

typedef struct	s_bmp
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

typedef struct	s_door
{
	t_tab_img	img;
	char		tmp;
	int			side;
	int			dir[2];

}				t_door;

typedef struct	s_weap
{
	t_tab_img	img;
	char		state;

}				t_weap;

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

typedef int	(*t_function)(char *, t_game **);

#endif
