#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_environment	*env;

	if (ac != 2)
		terminate("program usage: ./so_long map.ber");
	env = init_env();
	parse_map(av[1], env);
	init_window(env);
	mlx_key_hook(env->win, &move, env);
	//mlx_hook(env->win,)
	mlx_loop(env->mlx);

	return (0);
}
