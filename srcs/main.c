/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:28:14 by fmeira            #+#    #+#             */
/*   Updated: 2021/09/17 01:21:24 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	open_doors(t_environment *env)
{
	int	j;
	int	k;
	int	e_x;
	int	e_y;

	j = 0;
	while (j < env->y_size)
	{
		k = 0;
		while (k < env->x_size)
		{
			if (env->map[j][k] == 'E')
			{
				e_y = IMG_HEIGHT * j;
				e_x = IMG_WIDTH * k;
				mlx_put_image_to_window(env->mlx, env->win, env->i_e.img,
					e_x, e_y);
			}
			k++;
		}
		j++;
	}
}

t_bool	legal_exit(int key_code, t_environment *env)
{
	if (key_code == W)
	{
		if (env->map[(env->p_y - 1)][env->p_x] == 'E' &&
			env->c_count == 0)
			return (true);
	}
	else if (key_code == S)
	{
		if (env->map[(env->p_y + 1)][env->p_x] == 'E' &&
			env->c_count == 0)
			return (true);
	}
	else if (key_code == A)
	{
		if (env->map[env->p_y][(env->p_x - 1)] == 'E' &&
			env->c_count == 0)
			return (true);
	}
	else if (key_code == D)
	{
		if (env->map[env->p_y][env->p_x + 1] == 'E' &&
			env->c_count == 0)
			return (true);
	}
	return (false);
}

int	main(int ac, char **av)
{
	t_environment	*env;

	if (ac != 2)
		terminate("program usage: ./so_long map.ber");
	if (!(ft_strcmp(&(av[1][(ft_strlen(av[1] - 4))]), ".ber")))
		terminate("map must be a .ber file");
	env = init_env();
	parse_map(av[1], env);
	init_window(env);
	mlx_key_hook(env->win, &move, env);
	mlx_hook(env->win, 17, 1L << 17, &finish, env);
	mlx_loop(env->mlx);
	return (0);
}
