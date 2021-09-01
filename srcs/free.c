#include "../includes/so_long.h"


void	free_c_list(t_c_list *list)
{

}

void	free_struct(t_environment *env, int i)
{
	if (env)
	{
		if (env->P)
			free(env->P);
		if (env->E)
			free(env->E);
		if (env->C)
			free_c_list(env->C);
		if (env->map)
			free_map(env->map);
	free(env);
	env = NULL;
	}
}

void	die(t_environment *env, int i, char *message)
{
	free_struct(env, i);
	terminate(message);
}
