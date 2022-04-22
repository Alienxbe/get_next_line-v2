/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:45:34 by mykman            #+#    #+#             */
/*   Updated: 2022/04/22 19:50:17 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*gnl_strjoin(char *s1, char *s2)
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

static char	*gnl_substr(char *start, char *end, char *old)
{
	char	*str;
	long	len;

	len = end - start;
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

static char	*get_line(char **saved)
{
	char	*line;
	char	*split;

	if (!**saved)
		return (ft_free(saved, NULL));
	split = ft_strchr(*saved, '\n') + 1;
	if (split < *saved)
		split = ft_strchr(*saved, '\0');
	line = gnl_substr(*saved, split, NULL);
	*saved = gnl_substr(split, ft_strchr(*saved, '\0'), *saved);
	if (!line || !*saved)
		return (ft_free(&line, saved));
	if (!**saved)
		ft_free(saved, NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*saved[OPEN_MAX];
	char		*buff;
	int			bytes;

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buff = (char *)malloc(sizeof(*buff) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (bytes && !ft_strchr(saved[fd], '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		buff[bytes] = 0;
		saved[fd] = gnl_strjoin(saved[fd], buff);
		if (!saved[fd])
			return (ft_free(&buff, NULL));
	}
	free(buff);
	return (get_line(&saved[fd]));
}
