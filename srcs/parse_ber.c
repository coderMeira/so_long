#include "../includes/so_long.h"

static void	check_if_rectangle(t_environment *env, int len)
{
	int	j;
	int	this_len;

	j = 0;
	while (j < env->map_size)
	{
		this_len = ft_strlen(env->map[j]);
		if (this_len != len)
			die(env, "map is not a rectangle");
		j++;
	}
	if (len <= env->map_size)
		die(env, "map is not a rectangle");
}

static void	check_borders(t_environment *env, int len)
{
	int j;

	j = 0;
	while (j < len)
	{
		if (env->map[0][j] != '1')
			die(env, "top border not closed");
		j++;
	}
	j = 0;
	while (j < env->map_size)
	{
		if (env->map[j][0] != '1' || env->map[j][len - 1] != '1')
			die(env, "one of the middle borders is not closed");
		j++;
	}
	j = 0;
	while (j < len)
	{
		if (env->map[env->map_size - 1][j] != '1')
			die(env, "botton border not closed");
		j++;
	}
}

static void	check_letters(t_environment *env, int len)
{
	int 		j;
	int 		k;
	t_c_list	*C;

	j = 0;
	while (j < env->map_size)
	{
		k = 0;
		while (k < len)
		{
			if (env->map[j][k] != '1' && env->map[j][k] != 'C' &&
				env->map[j][k] != 'E' && env->map[j][k] != '0' &&
				env->map[j][k] != 'P')
				die(env, "only 5 possible characters: 0, 1, C, E, P");
			else if (env->map[j][k] == 'C')
				add_to_C(C, env, j, k);
			else if (env->map[j][k] == 'E')
			{
				if (env->E->is_set)
					die(env, "only one Exit allowed");
				env->E = init_element(j, k, env);
			}
			else if (env->map[j][k] == 'P')
			{
				if (env->P->is_set)
					die(env, "only one Player allowed");
				env->P = init_element(j, k, env);
			}
			k++;
		}
		j++;
	}
	if (!(env->C) || !(env->E) || !(env->P))
		die(env, "map needs to have at least 1 'C', 1 'E' and 1 'P'");
}

static void	validate_map(t_environment *env)
{
	int len;

	len = ft_strlen(env->map[0]);
	write(1, &("0\n"), 2);
	if (env)
	{
		check_if_rectangle(env, len);
		write(1, &("1\n"), 2);
		check_borders(env, len);
		write(1, &("2\n"), 2);
		check_letters(env, len);
		write(1, &("3\n"), 2);

	}
	else
		die(env, "error in environment pointer");
}

char**	parse_map(char* ber, t_environment*	env)
{
	char*	line;
	char**	new;
	int		i;
	int		fd;

	line = NULL;
	new = NULL;
	i = 0;
	fd = open(ber, O_RDONLY);
	new = malloc((sizeof(char*) * (1000)));
	while ((get_next_line(fd, &line) > 0))
	{
		new[i++] = ft_strdup(line);
		free(line);
	}
	free_slice(new, i, 1000);
	new[i] = NULL;
	env->map = new;
	env->map_size = i;
	close(fd);
	for(int j = 0; j < i; j++)
		printf("%s\n\n", env->map[j]);
	validate_map(env);
	return (new);
}
