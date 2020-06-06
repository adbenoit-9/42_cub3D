/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:14:51 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/06 22:57:38 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

enum	e_state
{
	INFO,
	BONUS,
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
	int		column;

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

typedef struct	s_bonus
{
	int				loop;
	int				loop2;
	t_tab_img		weap;
	t_tab_img		door;
	char			door_tmp;
	char			map_c;
	int				door_side;
	char			**path;
	int				pull;
	int				life;
	int				mm_dim;
	t_img			heart;
	t_sprite		s1;
	t_sprite		sa;
	t_img			dead;
	t_img			win;
	int				foe;
	int				col;
}				t_bonus;

typedef struct	s_all
{
	char			**path;
	char			**map;
	int				r[2];
	int				f;
	int				c;
	int				map_size;
	int				fd;
	int				ret;
	int				save;
	t_key			key;
	enum e_state	state;
	t_player		player;
	void			*mlx;
	void			*win;
	t_screen		screen;
	t_wall			wall;
	t_img			img;
	t_tab_img		text;
	t_sprite		sp;
	t_bonus			bonus;
	double			invdet;

}				t_all;

typedef int	(*t_function)(char *, t_all **);

#endif
