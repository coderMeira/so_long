#include "../includes/so_long.h"

t_environment	*init_env(void)
{
	t_environment	*env;

	env = (t_environment *)malloc(sizeof(t_environment));
	if (!env)
		terminate("failed to malloc on t_environment");
	env->map = NULL;
	env->P_count = 0;
	env->E_count = 0;
	env->C_count = 0;
	env->mov_count = 0;
	env->x_size = 0;
	env->y_size = 0;
	// env->player = 0;
	// env->exit = 0;
	// env->consumable = 0;
	// env->wall = 0;
	// env->floor = 0;
	return (env);
}

static void	init_asset_imgs(t_environment *env)
{
	env->i_1.img = mlx_xpm_file_to_image(env->mlx,
			"./so_long_imgs/1.xpm", &env->i_1.img_width, &env->i_1.img_height);
	env->i_P.img = mlx_xpm_file_to_image(env->mlx,
			"./so_long_imgs/P.xpm", &env->i_P.img_width, &env->i_P.img_height);
	env->i_E.img = mlx_xpm_file_to_image(env->mlx,
			"./so_long_imgs/E.xpm", &env->i_E.img_width, &env->i_E.img_height);
	env->i_C.img = mlx_xpm_file_to_image(env->mlx,
			"./so_long_imgs/C.xpm", &env->i_C.img_width, &env->i_C.img_height);
	env->i_0.img = mlx_xpm_file_to_image(env->mlx,
			"./so_long_imgs/0.xpm", &env->i_0.img_width, &env->i_0.img_height);
	if (!env->i_1.img || !env->i_P.img || !env->i_E.img || !env->i_C.img
		|| !env->i_0.img)
		die(env, "mlx_xpm_file_to_image failure");
}

void	init_window(t_environment *env)
{
	int	size_x;
	int	size_y;

	size_x = ASSET_WIDTH * env->x_size;
	size_y = ASSET_HEIGHT * env->y_size;

	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, size_x, size_y, "So Long");
	init_asset_imgs(env);
	mlx_put_image_to_window(env->mlx, env->win, env->i_P.img, 1, 1);
}
