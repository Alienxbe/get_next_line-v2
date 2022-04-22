/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:41:29 by mykman            #+#    #+#             */
/*   Updated: 2022/04/22 19:43:03 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

/*
** Main functions
*/

char	*get_next_line(int fd);

/*
** Utils
*/

int		ft_strlen(char *s);
void	*ft_free(char **s1, char **s2);
void	*ft_memcpy(void *dest, void *src, int n);
char	*ft_strchr(char *s, char c);

#endif