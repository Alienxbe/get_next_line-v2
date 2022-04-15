/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:45:34 by mykman            #+#    #+#             */
/*   Updated: 2022/04/15 23:26:13 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	int		size;
	char	*str;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[size] = 0;
	if (s1)
		free(s1);
	return (str);
}

char	*gnl_substr(char *start, char *end, char *old)
{
	char	*str;
	long	len;

	len = end - start;
	if (start > end)
		len = ft_strlen(start);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str)
	{
		ft_memcpy(str, start, len);
		str[len] = 0;
	}
	if (old || !str)
		free(old);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;
	char		*buff;
	int			bytes;

	buff = (char *)malloc(sizeof(*buff) * (BUFFER_SIZE + 1));
	if (!buff || read(fd, NULL, 0) < 0)
		return (free_return(&buff));
	bytes = 1;
	while (bytes && !ft_strchr(saved, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		buff[bytes] = 0;
		saved = gnl_strjoin(saved, buff);
		if (!saved)
			return (free_return(&buff));
	}
	free(buff);
	if (!*saved)
	{
		free(saved);
		line = NULL;
		saved = NULL;
	}
	else if (ft_strchr(saved, '\n')) // Cas 1
	{
		line = gnl_substr(saved, ft_strchr(saved, '\n') + 1, NULL);
		saved = gnl_substr(ft_strchr(saved, '\n') + 1, ft_strchr(saved, '\0'), saved);
		if (!saved)
			return(free_return(&line));
	}
	else
	{
		line = gnl_substr(saved, ft_strchr(saved, '\0'), saved);
		saved = NULL;
	}
	return (line);
}
