#include "../includes/so_long.h"

void start_window(t_environment *env)
{
	int	i;
	int	j;
	int	x;
	int y;

	i = 0;
	while (i < env->y_size)
	{
		j = 0;
		while (j < env->x_size)
		{
			x = ASSET_HEIGHT * j;
			y = ASSET_WIDTH * i;
			if (env->map[i][j] == '1')
				mlx_put_image_to_window(env->mlx, env->win, env->i_1.img, x, y);
			else if (env->map[i][j] == '0')
				mlx_put_image_to_window(env->mlx, env->win, env->i_0.img, x, y);
			else if (env->map[i][j] == 'P')
				mlx_put_image_to_window(env->mlx, env->win, env->i_P.img, x, y);
			else if (env->map[i][j] == 'E')
				mlx_put_image_to_window(env->mlx, env->win, env->i_E.img, x, y);
			else if (env->map[i][j] == 'C')
				mlx_put_image_to_window(env->mlx, env->win, env->i_C.img, x, y);
			j++;
		}
		i++;
	}
}
