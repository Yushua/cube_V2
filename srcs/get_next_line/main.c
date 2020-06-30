/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/25 16:49:00 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/30 11:47:50 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void			ft_putstr(char *str)
{
	int i;

	i = ft_strlen(str);
	write(1, "[", 1);
	write(1, str, i);
	write(1, "]", 1);
	write(1, "\n", 1);
}

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
		ft_putstr(line);
		free(line);
	}
	return (0);
}
