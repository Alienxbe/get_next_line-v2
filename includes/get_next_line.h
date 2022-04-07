/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:41:29 by mykman            #+#    #+#             */
/*   Updated: 2022/03/25 19:13:25 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// TO REMOVE !!!
# include <stdio.h>

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE	4
# define TRUE			(t_bool)1
# define FALSE			(t_bool)0

typedef unsigned char	t_bool;

char	*get_next_line(int fd);

/*
** Utils
*/

int		ft_strlen(char *s);
void	*ft_memcpy(void *dest, void *src, int n);
char	*ft_strchr(char *s, char c);

#endif