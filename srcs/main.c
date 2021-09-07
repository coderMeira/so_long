#include "../includes/so_long.h"

int	main(int ac, char** av)
{
	t_environment	*env;
	void	*mlx;
	void	*img;
	char	*relative_path = "~/Users/fmeira/Desktop/git/so_long/so_long_imgs/0.xpm";
	int		img_width;
	int		img_height;

	img = NULL;
	mlx = mlx_init();
	img_height = 500;
	img_width = 500;
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	env = init_env();
	if (ac == 2)
	{
		parse_map(av[1], env);
	}
	return (0);
}
