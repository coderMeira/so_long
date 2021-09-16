/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:31:54 by fmeira            #+#    #+#             */
/*   Updated: 2021/09/16 17:31:55 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_bool	not_int(char *s)
{
	int			i;
	int			len;
	char		*tmp;
	long long	check_size;
	long long	max_int;

	i = 0;
	len = ft_strlen(s);
	tmp = s;
	check_size = ft_stoi(tmp);
	max_int = 2147483647;
	if (check_size > max_int)
		return (true);
	if (s[i] == '-' && ft_isdigit(s[1]))
		i++;
	while (i < len)
	{
		if (!(ft_isdigit(s[i++])))
			return (true);
	}
	return (false);
}
