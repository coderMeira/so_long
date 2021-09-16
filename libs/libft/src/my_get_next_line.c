/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:26:26 by fmeira            #+#    #+#             */
/*   Updated: 2021/09/16 17:30:16 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	get_next_line(int fd, char **line)
{
	t_gnl	gnl;

	gnl.l = 1;
	*line = ft_calloc(sizeof(char), gnl.l);
	if (!(*line))
		return (-1);
	gnl.r = read(fd, &gnl.c, 1);
	while (gnl.r && gnl.l++ && gnl.c != '\n')
	{
		gnl.tmp = malloc(gnl.l);
		if (!(gnl.tmp))
		{
			free(*line);
			return (-1);
		}
		gnl.i = -1;
		while (++gnl.i < gnl.l - 2)
			gnl.tmp[gnl.i] = (*line)[gnl.i];
		gnl.tmp[gnl.i] = gnl.c;
		gnl.tmp[gnl.i + 1] = 0;
		free(*line);
		*line = gnl.tmp;
		gnl.r = read(fd, &gnl.c, 1);
	}
	return (gnl.r);
}
