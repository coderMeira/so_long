/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:26:03 by fmeira            #+#    #+#             */
/*   Updated: 2021/03/15 19:56:20 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*p;

	len = ft_strlen(s1);
	i = 0;
	p = (char *)malloc(len * sizeof(char) + 1);
	if (p)
	{
		while (i < len)
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = s1[i];
		return (p);
	}
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2)
		return (0);
	if (!(p = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (*s1)
		p[i++] = *s1++;
	while (*s2)
		p[i++] = *s2++;
	p[i] = ('\0');
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ss;

	i = 0;
	ss = (char *)s;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(ss + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(ss + i));
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		p = malloc(sizeof(char));
		if (!p)
			return (0);
		*p = '\0';
		return (p);
	}
	if (s_len < len)
		return (ft_strdup((char *)s + start));
	i = 0;
	p = (char *)malloc(len + 1 * sizeof(char));
	if (!p)
		return (0);
	while (start < s_len && i < len)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
