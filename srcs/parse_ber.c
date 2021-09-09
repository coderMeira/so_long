#include "../includes/so_long.h"

static void	check_if_rectangle(t_environment *env)
{
	int	j;
	int	this_len;

	j = 0;
	while (j < env->y_size)
	{
		//write(1, &(env->map[j]), ft_strlen(env->map[j]));
		this_len = ft_strlen(env->map[j]);
		if (this_len != env->x_size)
			die(env, "map is not a rectangle");
		j++;
		//write(1, &("\n"), 1);
	}
}

static void	check_borders(t_environment *env)
{
	int j;

	j = 0;
	while (j < env->x_size)
	{
		if (env->map[0][j] != '1')
			die(env, "top border not closed");

		j++;
	}
	j = 0;
	while (j < env->y_size)
	{
		if (env->map[j][0] != '1' || env->map[j][env->x_size - 1] != '1')
			die(env, "one of the middle borders is not closed");
		j++;
	}
	j = 0;
	while (j < env->x_size)
	{
		if (env->map[env->y_size - 1][j] != '1')
			die(env, "botton border not closed");
		j++;
	}
}

static void	check_letter(t_environment *env, char letter, int j, int k)
{
	if (letter == 'P')
	{
		env->p_x = k;
		env->p_y = j;
	}
	if (letter != '1' && letter != 'C' &&
		letter != 'E' && letter != '0' && letter != 'P')
			die(env, "only 5 possible characters: 0, 1, C, E, P");
}

static void	parse_letters(t_environment *env)
{
	int		j;
	int		k;

	j = 0;
	while (j < env->y_size)
	{
		k = 0;
		while (k < env->x_size)
		{
			check_letter(env, env->map[j][k], j, k);
			if (env->map[j][k] == 'C')
				env->C_count++;
			else if (env->map[j][k] == 'E')
				env->E_count++;
			else if (env->map[j][k] == 'P')
				env->P_count++;
			k++;
		}
		j++;
	}
	env->y_size = j;
	if (!(env->C_count) || !(env->E_count) || env->P_count > 1)
		die(env, "map needs to have at least 1 'C', 1 'E', and 1 'P' max");
}

void	parse_map(char* ber, t_environment*	env)
{
	char	*line;
	int		i;
	int		fd;

	line = NULL;
	i = 0;
	fd = open(ber, O_RDONLY);
	env->map = malloc((sizeof(char*) * (1000)));
	while ((get_next_line(fd, &line) > 0))
	{
		if (line[0] == 0)
			free(line);
		else
		{
			env->map[i++] = ft_strdup(line);
			free(line);
		}
	}
	free_slice(env->map, i, 1000);
	env->y_size = i;
	env->x_size = ft_strlen(env->map[0]);
	close(fd);
	check_if_rectangle(env);
	check_borders(env);
	parse_letters(env);
}
