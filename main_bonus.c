/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:15:15 by maykman           #+#    #+#             */
/*   Updated: 2022/04/22 20:23:13 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bonus/includes/get_next_line_bonus.h"

int main()
{
	char	*line;
	int		fd[3];

	fd[0] = open("files/test1", O_RDONLY);
	fd[1] = open("files/test2", O_RDONLY);
	fd[2] = open("files/test3", O_RDONLY);
	for (int i = 0; i < 3; i++)
	{
		line = get_next_line(fd[i % 3]);
		write(1, line, ft_strlen(line));
		if (line)
			free(line);
	}
	for (int i = 0; i < 3; i++)
		close(fd[i]);
	return 0;
}
