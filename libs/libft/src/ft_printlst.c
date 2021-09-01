
#include "../inc/libft.h"

void	ft_printlst(t_list *a)
{
	t_list	*current;
	int		*p;

	current = NULL;
	p = current -> content;
	current = a;
	while (current)
	{
		printf("%d\n", *p);
		current = current -> next;
	}
}
