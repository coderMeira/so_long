#include "../inc/libft.h"

void free_slice(char **arr, int current, int end)
{
	if (arr)
	{
		while (++current < end)
			free(arr[current]);
	}
}
