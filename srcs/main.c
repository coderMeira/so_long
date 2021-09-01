#include "../includes/so_long.h"

int	main(int ac, char** av)
{
	//t_vars	*mlx_vars;
	//t_data	*img;
	t_environment	*env;

	env = init_env();

	//mlx_vars = NULL;
	//img = NULL;

	if (ac == 2)
	{
		parse_map(av[1], env);
		//init_window(mlx_vars, img);
	}
	return (0);
}
