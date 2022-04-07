/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:45:34 by mykman            #+#    #+#             */
/*   Updated: 2022/04/07 18:47:50 by mykman           ###   ########.fr       */
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
	if (len < 0)
		len = ft_strlen(start);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str)
	{
		ft_memcpy(str, start, len);
		str[len] = 0;
	}
	if (old)
		free(old);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;
	char		buff[BUFFER_SIZE];
	int			ret;

	if (fd < 0)
		return (NULL);
	ret = 1;
	while (ret && !ft_strchr(saved, '\n'))
	{
		ret = read(fd, buff, BUFFER_SIZE - 1);
		buff[ret] = 0;
		saved = gnl_strjoin(saved, buff);
		if (!saved)
			return (NULL);
	}
	if (!*saved)
	{
		line = NULL;
		free(saved);
	}
	else
	{
		line = gnl_substr(saved, ft_strchr(saved, '\n') + 1, NULL);
		saved = gnl_substr(ft_strchr(saved, '\n') + 1, ft_strchr(saved, '\0'), saved);
	}
	return (line);
}
