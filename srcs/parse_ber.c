#include "../includes/so_long.h"

static void	check_if_rectangle(char **line, int i, int len)
{
	int	j;
	int	this_len;

	j = 0;
	while (j < i)
	{
		this_len = ft_strlen(line[j]);
		if (this_len != len)
			terminate("map is not a rectangle");
		j++;
	}
	if (len <= i)
		terminate("map is not a rectangle");
}

static void	check_borders(char **line, int i, int len)
{
	int j;

	j = 0;
	while (j < len)
	{
		if (line[0][j] != '1')
			terminate("top border not closed");
		j++;
	}
	j = 0;
	while (j < i)
	{
		if (line[j][0] != '1' || line[j][len - 1] != '1')
			terminate("one of the middle borders is not closed");
		j++;
	}
	j = 0;
	while (j < len)
	{
		if (line[i - 1][j] != '1')
			terminate("botton border not closed");
		j++;
	}
}

static void	check_letters(t_environment *env, int i, int len)
{
	int j;
	int k;

	j = 0;
	while (j < i)
	{
		k = 0;
		while (k < len)
		{
			if (env->map[j][k] != '1' && env->map[j][k] != 'C' &&
				env->map[j][k] != 'E' && env->map[j][k] != '0' &&
				env->map[j][k] != 'P')
				terminate("only 5 possible characters: 0, 1, C, E, P");
			//if (env->map[j][k] == 'C')
				//add to C
			if (env->map[j][k] == 'E')
			{
				if (env->E->count)
				{
					free_struct(env);
					terminate("only one exit allowed");
				}
				env->E = set_pos(env->map, j, k);
			}
			if (env->map[j][k] == 'P')
			{
				if (env->P->count)
				{
					free_struct(env);
					terminate("only one player allowed");
				}
				env->P = set_pos(env->map, j, k);
			}
			k++;
		}
		j++;
	}
	if ((C + E + P) < 3)
		terminate("map needs to have at least 1 'C', 1 'E' and 1 'P'");
}

static void	validate_map(t_environment *env, int i)
{
	int len;

	len = ft_strlen(env->map[0]);
	write(1, &("0\n"), 2);
	if (line)
	{
		check_if_rectangle(env->map, i, len);
		write(1, &("1\n"), 2);
		check_borders(env->map, i, len);
		write(1, &("2\n"), 2);
		check_letters(env, i, len);
		write(1, &("3\n"), 2);

	}
	else
		terminate("error in line pointer");
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
	new = malloc((sizeof(char*) * (100)));
	while ((get_next_line(fd, &line) > 0))
	{
		new[i++] = ft_strdup(line);
		free(line);
	}
	free_slice(new, i, 100);
	new[i] = NULL;
	env->map = new;
	close(fd);
	for(int j = 0; j < i; j++)
		printf("%s\n\n", env->map[j]);
	validate_map(env, i);
	return (new);
}
