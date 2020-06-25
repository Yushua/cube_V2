/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_map.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 14:08:37 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/25 13:24:25 by ybakker       ########   odam.nl         */
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
			main->place.mapp++;
		if (main->place.mapp > 1)
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
		return (1);
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
	main->Ray.eh = 0;
	fd = open(main->map, O_RDONLY);
	if (fd < 0)
	{
		main->place.error = 24;
		ft_error(main);
	}
	while (count > 0)
	{
		count = get_next_line(fd, &map);
		if (y != 0)
			y--;
		else
		{
			if (map[0] == '\0')
				main->Ray.eh++;
			else if (ft_check_for_map(map, main) == 1 && main->Ray.eh > 0)
			{
				main->place.error = 47;
				ft_error(main);
				return (1);
			}
			main->Ray.yy++;
			if (get_size_map(main, map) == 1)
			{
				free(map);
				return (1);
			}
		}
		free(map);
	}
	main->Ray.yy = main->Ray.yy - main->Ray.eh;
	space_cubemap(main);
	return (0);
}
