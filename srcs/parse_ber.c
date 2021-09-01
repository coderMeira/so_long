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

static void	check_letters(char **line, int i, int len)
{
	int j;
	int k;
	int	C;
	int E;
	int P;

	j = 0;
	C = 0;
	E = 0;
	P = 0;
	while (j < i)
	{
		k = 0;
		while (k < len)
		{
			if (line[j][k] != '1' && line[j][k] != 'C' &&
			line[j][k] != 'E' && line[j][k] != '0' && line[j][k] != 'P')
				terminate("only 5 possible characters: 0, 1, C, E, P");
			if (line[j][k] == 'C')
				C = 1;
			if (line[j][k] == 'E')
				E = 1;
			if (line[j][k] == 'P')
				P = 1;
			k++;
		}
		j++;
	}
	if ((C + E + P) < 3)
		terminate("map needs to have at least 1 'C', 1 'E' and 1 'P'");
}

static void	validate_map(char **line, int i)
{
	int len;

	len = ft_strlen(line[0]);
	write(1, &("0\n"), 2);
	if (line)
	{
		check_if_rectangle(line, i, len);
		write(1, &("1\n"), 2);
		check_borders(line, i, len);
		write(1, &("2\n"), 2);
		check_letters(line, i, len);
		write(1, &("3\n"), 2);

	}
	else
		terminate("error in line pointer");
}

char**	parse_map(char* ber)
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
	for(int j = 0; j < i; j++)
		printf("%s\n", new[j]);
	validate_map(new, i);
	close(fd);
	return (new);
}
