/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_empty_space.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 19:09:40 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/23 20:11:58 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void			empty_map_two(t_struct_m *main, int n, int len)
{
	int		i;

	i = 0;
	while (len != 0)
	{
		main->cubecopytwo[n][i] = ' ';
		i++;
		len--;
	}
	main->cubecopytwo[n][i] = '\0';
}

int				ft_empty_space(t_struct_m *main)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < (main->Ray.yy))
	{
		while (main->cubecopy[y][x] == ' ')
			x++;
		if (main->cubecopy[y][x] == '\0')
		{
			main->place.error = 47;
			ft_error(main);
			ft_putstr(ft_itoa(y));
			ft_putstr(ft_itoa(x));
			return (0);
		}
		x = 0;
		y++;
	}
}

static int		map_top_bottom(t_struct_m *main, int y, int yy, int len)
{
	while (y <= (yy - 2))
	{
		len = (ft_strlen(main->cubecopy[y]) + 2);
		main->cubecopytwo[y] = (char *)malloc((len + 1) * sizeof(char));
		if (!main->cubecopytwo[y])
			return (1);
		empty_map_two(main, y, len);
		ft_putstr(main->cubecopytwo[y]);
		y++;
	}
	main->cubecopytwo[y] = (char *)malloc((len + 1) * sizeof(char));
	if (!main->cubecopytwo[y])
		return (1);
	empty_map_two(main, y, len);
	ft_putstr(main->cubecopytwo[y]);
}

int				map_copy_two(t_struct_m *main)
{
	int		y;
	int		yy;
	int		len;

	yy = (main->Ray.yy + 2);
	if (!main->cubecopy)
		return (1);
	main->cubecopytwo = (char**)malloc(sizeof(char*) * (yy + 1));
	if (!main->cubecopytwo)
		return (1);
	y = 0;
	len = (ft_strlen(main->cubecopy[y]) + 2);
	main->cubecopytwo[y] = (char *)malloc((len + 1) * sizeof(char));
	empty_map_two(main, y, len);
	ft_putstr(main->cubecopytwo[y]);
	// if (map_top_bottom(main, y, yy, len) == 1)
	// 	return (1);
	while (y <= (yy - 2))
	{
		len = (ft_strlen(main->cubecopy[y]) + 2);
		main->cubecopytwo[y] = (char *)malloc((len + 1) * sizeof(char));
		if (!main->cubecopytwo[y])
			return (1);
		empty_map_two(main, y, len);
		ft_putstr(main->cubecopytwo[y]);
		y++;
	}
	main->cubecopytwo[y] = (char *)malloc((len + 1) * sizeof(char));
	if (!main->cubecopytwo[y])
		return (1);
	empty_map_two(main, y, len);
	ft_putstr(main->cubecopytwo[y]);
	printf("y == [%i]\n", y);
	return (0);
}
