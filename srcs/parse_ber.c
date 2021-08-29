#include "../includes/so_long.h"

static t_bool	not_valid(char **line, int i)
{}

char**	parse_map(char* ber)
{
	char**	line;
	int		i;

	line = NULL;
	i = 0;
	while (get_next_line(ber, line) > 0)
		i++;
	if (not_valid(line, i))
		terminate("bad_map");
}
