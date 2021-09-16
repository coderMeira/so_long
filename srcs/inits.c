#include "../includes/so_long.h"

t_environment	*init_env(void)
{
	t_environment	*env;

	env = (t_environment *)malloc(sizeof(t_environment));
	if (!env)
		terminate("failed to malloc on t_environment");
	env->map = NULL;
	env->p_count = 0;
	env->e_count = 0;
	env->c_count = 0;
	env->mov_count = 0;
	env->x_size = 0;
	env->y_size = 0;
	env->p_x = 0;
	env->p_y = 0;
	env->new_p_x = 0;
	env->new_p_y = 0;
	env->e_x = 0;
	env->e_y = 0;
	env->i_1.img = NULL;
	return (env);
}

static void	init_asset_imgs(t_environment *env)
{
	env->i_1.img = mlx_xpm_file_to_image(env->mlx,
			"./so_long_imgs/1.xpm", &env->i_1.img_width, &env->i_1.img_height);
	env->i_p.img = mlx_xpm_file_to_image(env->mlx,
			"./so_long_imgs/P.xpm", &env->i_p.img_width, &env->i_p.img_height);
	env->i_e.img = mlx_xpm_file_to_image(env->mlx,
			"./so_long_imgs/E.xpm", &env->i_e.img_width, &env->i_e.img_height);
	env->i_c.img = mlx_xpm_file_to_image(env->mlx,
			"./so_long_imgs/C.xpm", &env->i_c.img_width, &env->i_c.img_height);
	env->i_0.img = mlx_xpm_file_to_image(env->mlx,
			"./so_long_imgs/0.xpm", &env->i_0.img_width, &env->i_0.img_height);
	env->i_x.img = mlx_xpm_file_to_image(env->mlx,
			"./so_long_imgs/X.xpm", &env->i_x.img_width, &env->i_x.img_height);
	if (!env->i_1.img || !env->i_p.img || !env->i_e.img || !env->i_c.img
		|| !env->i_0.img)
		die(env, "mlx_xpm_file_to_image failure");
}

void	start_window(t_environment *env)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	while (++i < env->y_size)
	{
		j = -1;
		while (++j < env->x_size)
		{
			x = IMG_HEIGHT * j;
			y = IMG_WIDTH * i;
			if (env->map[i][j] == '1')
				mlx_put_image_to_window(env->mlx, env->win, env->i_1.img, x, y);
			else if (env->map[i][j] == '0')
				mlx_put_image_to_window(env->mlx, env->win, env->i_0.img, x, y);
			else if (env->map[i][j] == 'P')
				mlx_put_image_to_window(env->mlx, env->win, env->i_p.img, x, y);
			else if (env->map[i][j] == 'E')
				mlx_put_image_to_window(env->mlx, env->win, env->i_x.img, x, y);
			else if (env->map[i][j] == 'C')
				mlx_put_image_to_window(env->mlx, env->win, env->i_c.img, x, y);
		}
	}
}

void	init_window(t_environment *env)
{
	int	size_x;
	int	size_y;

	size_x = IMG_WIDTH * env->x_size;
	size_y = IMG_HEIGHT * env->y_size;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, size_x, size_y, "So Long");
	init_asset_imgs(env);
	start_window(env);
}
