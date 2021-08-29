/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:18:44 by fmeira            #+#    #+#             */
/*   Updated: 2021/08/29 20:15:37 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

int		return_func(char **saved, int fd, char **line, int ret)
{
	if (ret < 0)
		return (-1);
	if (ret == 0 && saved[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (divide_n_conquer(&(saved[fd]), line));
}

int		divide_n_conquer(char **saved, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*saved)[i] && (*saved)[i] != '\n')
		i++;
	if ((*saved)[i] == '\n')
	{
		*line = ft_substr(*saved, 0, i);
		temp = ft_strdup(&((*saved)[i + 1]));
		free(*saved);
		*saved = temp;
	}
	else
	{
		*line = ft_strdup(*saved);
		free(*saved);
		saved = NULL;
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	static char *saved[OPEN_MAX];
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || (read(fd, buffer, 0)) < 0)
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (saved[fd] == NULL)
			saved[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(saved[fd], buffer);
			free(saved[fd]);
			saved[fd] = temp;
		}
		if (ft_strchr(saved[fd], '\n'))
			break ;
	}
	return (return_func(saved, fd, line, ret));
}
