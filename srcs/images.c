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

static t_bool	can_move(int key_code, t_environment *env)
{
	if (key_code == W)
	{
		if (env->map[(env->p_y - 1)][env->p_x] != '1')
			return (true);
	}
	else if (key_code == S)
	{
		if (env->map[(env->p_y + 1)][env->p_x] != '1')
			return (true);
	}
	else if (key_code == A)
	{
		if (env->map[env->p_y][(env->p_x - 1)] != '1')
			return (true);
	}
	else if (key_code == D)
	{
		if (env->map[env->p_y][env->p_x + 1] != '1')
			return (true);
	}
	return (false);
}

static void	update_matrix_and_p_pos(int key_code, t_environment *env)
{
	if (key_code == W)
		env->new_p_y = (env->new_p_y - 1);
	else if (key_code == S)
		env->new_p_y = (env->new_p_y + 1);
	else if (key_code == A)
		env->new_p_x = (env->new_p_x - 1);
	else if (key_code == D)
		env->new_p_x = (env->new_p_x - 1);
	env->map[env->new_p_y][env->new_p_x] = 'P';
	env->map[env->p_y][env->p_x] = '0';
	env->p_x = env->new_p_x;
}

static void	update_img(t_environment *env)
{
	int	x_0;
	int	y_0;
	int	x_p;
	int	y_p;

	x_0 = ASSET_HEIGHT * (env->p_x);
	y_0 = ASSET_WIDTH * (env->p_y);
	x_p = ASSET_HEIGHT * (env->new_p_x);
	y_p = ASSET_WIDTH * (env->new_p_y);

	mlx_put_image_to_window(env->mlx, env->win, env->i_0.img, x_0, y_0);
	mlx_put_image_to_window(env->mlx, env->win, env->i_P.img, x_p, y_p);
	env->p_y = env->new_p_y;
}

int move(int key_code, t_environment *env)
{
	// if (key_code == ESC)
	// 	exit;
	if (key_code == W || key_code == S || key_code == A || key_code == D)
	{
		if (can_move(key_code, env))
		{
			update_matrix_and_p_pos(key_code, env);
			update_img(env);
			ft_putnbr_fd(env->mov_count++, 1);
			ft_putchar_fd('\n', 1);
		}
	}
	return (0);
}
