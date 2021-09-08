#include "../includes/so_long.h"

void	free_struct(t_environment *env)
{
	if (env)
	{
		if (env->map)
		{
			while (env->x_size >= 0)
				free(env->map[env->x_size--]);
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
