/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:56:51 by mykman            #+#    #+#             */
/*   Updated: 2022/04/22 19:51:35 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_free(char **s1, char **s2)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (NULL);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, void *src, int n)
{
	if (!src || !dest)
		return (NULL);
	while (n--)
		*((unsigned char *)dest + n) = *((unsigned char *)src + n);
	return (dest);
}

char	*ft_strchr(char *s, char c)
{
	while (s && *s && *s != c)
		s++;
	if (s && *s == c)
		return (s);
	return (NULL);
}
