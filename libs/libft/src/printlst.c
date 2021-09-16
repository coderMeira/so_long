/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:30:10 by fmeira            #+#    #+#             */
/*   Updated: 2021/09/16 17:30:11 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
