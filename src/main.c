#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	t_vars	*ok;

	ok = vars;
	keycode++;
	vars->win = ok->win;
	printf("Hello from key_hook!\n");
	return (1);
}

int	main(void)
{
	t_vars	vars;
	int 	i = 0;;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, &key_hook(i, &vars), &vars);
	mlx_loop(vars.mlx);
}
