/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:32:59 by fmeira            #+#    #+#             */
/*   Updated: 2021/09/16 17:33:00 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_bool	ft_strcmp(char *newstr, char *original)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(original);
	while (i < len)
	{
		if (original[i] != newstr[i])
			return (false);
		i++;
	}
	return (true);
}
