#include "cub3d.h"

int	mlx_handle(t_all *all)
{
	mlx_hook(all->win_ptr, 17, 1L << 0, ft_close, &all);
	mlx_hook(all->win_ptr, KEY_PRESS, 1L << 0, ft_key_press, &all);
	mlx_hook(all->win_ptr, KEY_RELEASE, 1L << 1, ft_key_release, &all);
	mlx_mouse_hook(all->win_ptr, ft_mouse, &all);
	mlx_loop_hook(all->mlx_ptr, &create_image, &all);
	mlx_loop(all->mlx_ptr);
	return (NO_ERR);
}
