#include "../inc/libft.h"

void	terminate(char *error)
{
	ft_putendl_fd(error, 2);
	exit(1);
}
