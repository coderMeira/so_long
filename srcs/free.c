/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:28:12 by fmeira            #+#    #+#             */
/*   Updated: 2021/09/16 17:29:17 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		free(env->map);
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
	mlx_destroy_image(env->mlx, env->i_1.img);
	mlx_destroy_image(env->mlx, env->i_0.img);
	mlx_destroy_image(env->mlx, env->i_p.img);
	mlx_destroy_image(env->mlx, env->i_e.img);
	mlx_destroy_image(env->mlx, env->i_c.img);
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
	return (1);
}
