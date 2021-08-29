#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init_window(t_vars *mlx_vars, t_data* img)
{
	mlx_vars->mlx = mlx_init();
	mlx_vars->win = mlx_new_window(mlx_vars->mlx, 1920, 1080, "Hello world!");
	img->img = mlx_new_image(mlx_vars->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx_vars->mlx, mlx_vars->win, img->img, 0, 0);
	mlx_loop(mlx_vars->mlx);
}
