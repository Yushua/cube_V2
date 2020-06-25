/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/25 16:49:00 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/25 16:49:32 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int			main(void)
{
	int		count;
	int		fd;
	char	*line;

	count = 1;
	fd = open("get_next_line.c", O_RDONLY);
	while (count > 0)
	{
		count = get_next_line(fd, &line);
		free(line);
	}
	return (0);
}
