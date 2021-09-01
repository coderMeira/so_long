/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:09:05 by fmeira            #+#    #+#             */
/*   Updated: 2021/08/31 15:10:32 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	if (lst)
	{
		if (*lst)
			ft_lstlast(*lst)->next = n;
		else
			*lst = n;
	}
}
