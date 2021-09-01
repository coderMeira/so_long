#include "../includes/so_long.h"

t_element	*init_element(int i, int j)
{
	t_element	*elem;

	elem = (t_element *)malloc(sizeof(t_element));
	if (!elem)
		terminate("failed to malloc element");
	elem->pos = (int *)malloc(sizeof(int) * 2);
	elem->pos[0] = j;
	elem->pos[1] = k;
	elem->count = 1;
	return (elem);
}

t_environment	*init_env(void)
{
	t_environment	*env;

	env = (t_environment *)malloc(sizeof(t_environment));
	if (!env)
		terminate("failed to malloc on t_environment");
	env->P = NULL;
	env->E = NULL;
	env->C = NULL;
	env->map = NULL;
	env->c_count = 0;
	env->mov_count = 0;
	return (env);
}
