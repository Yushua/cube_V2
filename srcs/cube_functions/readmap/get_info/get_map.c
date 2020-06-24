/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_map.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 14:08:37 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/24 14:10:31 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int				ft_map_line_get_x(char *map)
{
	int		x;

	x = 0;
	while (map[x])
		x++;
	return (x);
}

int				ft_map_line(t_struct_m *main, char *map)
{
	int		x;

	x = 0;
	while (map[x])
	{
		if (map[x] == 'N' || map[x] == 'S' || map[x] == 'E' || map[x] == 'W')
			return (1);
		x++;
	}
	return (0);
}

int				get_size_map(t_struct_m *main, char *map)
{
	int		x;

	x = 0;
	if (ft_map_line(main, map) == 1)
	{
		main->place.error = 48;
		ft_error(main);
	}
	x = ft_map_line_get_x(map);
	if (x > main->Ray.xx)
		main->Ray.xx = x;
	return (0);
}

int			ft_size_store_map(t_struct_m *main)
{
	int		count;
	int		fd;
	char	*map;
	int		y;

	count = 1;
	y = main->Ray.yyy;
	main->place.mapp = 0;
	main->Ray.yy = 0;
	main->Ray.xx = 0;
	fd = open("./srcs/maps/mape_5.cub", O_RDONLY);
	while (count > 0)
	{
		count = get_next_line(fd, &map);
		if (y != 0)
			y--;
		else
		{
			main->Ray.yy++;
			if (get_size_map(main, map) == 1)
				return (1);
		}
		free(map);
	}
	printf("y=[%i]x=[%i]\n", main->Ray.yy, main->Ray.xx);
	space_cubemap(main);
	return (0);
}
