#include "../includes/so_long.h"

t_c_list	*init_C_elem(t_environment *env, int j, int k)
{
	t_c_list	*elem;

	elem = (t_c_list *)malloc(sizeof(t_c_list));
	if (!elem)
		die(env, "failed to malloc c_list");
	elem->pos = (int *)malloc(sizeof(int) * 2);
	elem->pos[0] = j;
	elem->pos[1] = k;
	elem->next = NULL;
	return (elem);
}

t_element	*init_element(int j, int k, t_environment *env)
{
	t_element	*elem;

	elem = (t_element *)malloc(sizeof(t_element));
	if (!elem)
		die(env, "failed to malloc element");
	elem->pos = (int *)malloc(sizeof(int) * 2);
	elem->pos[0] = j;
	elem->pos[1] = k;
	elem->is_set = true;
	return (elem);
}

t_environment	*init_env(void)
{
	t_environment	*env;

	env = (t_environment *)malloc(sizeof(t_environment));
	if (!env)
		terminate("failed to malloc on t_environment");
	env->P = NULL;
	env->E = NULL;
	env->C = NULL;
	env->map = NULL;
	env->c_count = 0;
	env->mov_count = 0;
	env->map_size = 0;
	return (env);
}

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
	my_mlx_pixel_put(img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx_vars->mlx, mlx_vars->win, img->img, 0, 0);
	mlx_loop(mlx_vars->mlx);
}
