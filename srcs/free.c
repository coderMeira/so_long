#include "../includes/so_long.h"

static void	free_struct(t_environment *env)
{
	if (env)
	{
		if (env->map)
		{
			while (env->y_size >= 0)
				free(env->map[env->y_size--]);
		}
		free(env);
		env = NULL;
	}
}

void	die(t_environment *env, char *message)
{
	free_struct(env);
	terminate(message);
}

int	finish(t_environment *env)
{
	free_struct(env);
	ft_putnbr_fd(1111, 1);
	ft_putchar_fd('\n', 1);
	mlx_destroy_image(env->mlx, env->i_1.img);
	ft_putnbr_fd(2222, 1);
	ft_putchar_fd('\n', 1);
	mlx_destroy_image(env->mlx, env->i_0.img);
	mlx_destroy_image(env->mlx, env->i_p.img);
	mlx_destroy_image(env->mlx, env->i_e.img);
	mlx_destroy_image(env->mlx, env->i_c.img);
	mlx_destroy_window(env->mlx, env->win);
	ft_putnbr_fd(3333, 1);
	ft_putchar_fd('\n', 1);
	exit(0);
	return (1);
}
