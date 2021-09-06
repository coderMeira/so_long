#include "../includes/so_long.h"


void	free_c_list(t_c_list *list)
{
	t_c_list	*current;
	t_c_list	*delete;

	current = list;
	while (current)
	{
		delete = current;
		current = current->next;
		free(delete->pos);
		free(delete);
	}
	free(list);
}

void	free_struct(t_environment *env)
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
		{
			while (env->map_size >= 0)
				free(env->map[env->map_size--]);
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
