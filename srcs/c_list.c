#include "../includes/so_long.h"

static t_c_list	*last(t_c_list *lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	add_to_C(t_c_list *C, t_environment *env, int j, int k)
{
	t_c_list	*tail;

	tail = init_C_elem(env, j, k);
	if (env)
	{
		if (C)
			last(C)->next = tail;
		else
			C = tail;
	}
}
