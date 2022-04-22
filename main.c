/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:46:24 by mykman            #+#    #+#             */
/*   Updated: 2022/04/22 16:02:23 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*int main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else if (argc == 1)
		fd = STDIN_FILENO;
	else
		fd = -1;
	if (fd < 0)
		return (1);
	line = (char *)1;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			write(1, line, ft_strlen(line));
			free(line);
		}
	}
	close(fd);
	return (0);
}*/

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	for (int i = 0; i < 3; i++)
	{
		line = get_next_line(fd);
		if (line)
			free(line);
		printf("----------\n");
	}
	return (0);
}
