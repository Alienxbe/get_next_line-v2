/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:41:29 by mykman            #+#    #+#             */
/*   Updated: 2022/04/22 15:56:55 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

# define BUFFER_SIZE	32

char	*get_next_line(int fd);

/*
** Utils
*/

int		ft_strlen(char *s);
char	*free_return(char **str, void *ret);
void	*ft_memcpy(void *dest, void *src, int n);
char	*ft_strchr(char *s, char c);

#endif