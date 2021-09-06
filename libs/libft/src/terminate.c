#include "../inc/libft.h"

void	terminate(char *error)
{
	write(1, "Error\n", 6);
	ft_putendl_fd(error, 2);
	exit(1);
}
