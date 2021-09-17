/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:29:44 by fmeira            #+#    #+#             */
/*   Updated: 2021/09/17 01:23:52 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_bool	not_illegal_exit(int key_code, t_environment *env)
{
	if (key_code == W)
	{
		if (env->map[(env->p_y - 1)][env->p_x] == 'E' &&
			env->c_count > 0)
			return (false);
	}
	else if (key_code == S)
	{
		if (env->map[(env->p_y + 1)][env->p_x] == 'E' &&
			env->c_count > 0)
			return (false);
	}
	else if (key_code == A)
	{
		if (env->map[env->p_y][(env->p_x - 1)] == 'E' &&
			env->c_count > 0)
			return (false);
	}
	else if (key_code == D)
	{
		if (env->map[env->p_y][env->p_x + 1] == 'E' &&
			env->c_count > 0)
			return (false);
	}
	return (true);
}

static t_bool	can_move(int key_code, t_environment *env)
{
	if (not_illegal_exit(key_code, env))
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
	}
	return (false);
}

static void	update_matrix_and_pos(int key_code, t_environment *env)
{
	if (key_code == W)
		env->new_p_y = (env->p_y - 1);
	else if (key_code == S)
		env->new_p_y = (env->p_y + 1);
	else if (key_code == A)
		env->new_p_x = (env->p_x - 1);
	else if (key_code == D)
		env->new_p_x = (env->p_x + 1);
	if (env->map[env->new_p_y][env->new_p_x] == 'C')
		env->c_count--;
	env->map[env->new_p_y][env->new_p_x] = 'P';
	env->map[env->p_y][env->p_x] = '0';
}

static void	update_img(t_environment *env)
{
	int	x_0;
	int	y_0;
	int	x_p;
	int	y_p;

	x_0 = IMG_HEIGHT * (env->p_x);
	y_0 = IMG_WIDTH * (env->p_y);
	x_p = IMG_HEIGHT * (env->new_p_x);
	y_p = IMG_WIDTH * (env->new_p_y);
	mlx_put_image_to_window(env->mlx, env->win, env->i_0.img, x_0, y_0);
	mlx_put_image_to_window(env->mlx, env->win, env->i_p.img, x_p, y_p);
	if (env->c_count == 0)
		open_doors(env);
	env->p_y = env->new_p_y;
	env->p_x = env->new_p_x;
}

int	move(int key_code, t_environment *env)
{
	if (key_code == ESC)
		finish(env);
	if (key_code == W || key_code == S || key_code == A || key_code == D)
	{
		if (can_move(key_code, env))
		{
			update_matrix_and_pos(key_code, env);
			update_img(env);
			ft_putnbr_fd(++env->mov_count, 1);
			ft_putchar_fd('\n', 1);
			if (legal_exit(key_code, env))
				finish(env);
		}
	}
	return (0);
}
