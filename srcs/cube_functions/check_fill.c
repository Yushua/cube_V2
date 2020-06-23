/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 11:13:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/23 16:35:17 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void			empty_map_two(t_struct_m *main, int n, int len)
{
	int		i;

	i = 0;
	// len = len + 1;
	while (len != 0)
	{
		main->cubecopytwo[n][i] = ' ';
		i++;
		len--;
	}
	main->cubecopytwo[n][i] = '\0';
}

static char			copy_map_two(char **copy, char **org, int y)
{
	int		i;
	int		x;
	int		yy;

	i = 0;
	x = 1;
	yy = y--;
	while (org[y][i])
	{
		copy[yy][x] = org[y][i];
		x++;
		i++;
	}
	copy[y][x] = '\0';
	return (0);
}

static int			fill_middle_copy(t_struct_m *main, int y, int yy, int len)
{
	while (y < (yy - 1))
	{
		len = ft_strlen(main->cubecopy[y - 1]) + 2;
		main->cubecopytwo[y] = (char *)malloc((len + 1) * sizeof(char));
		if (!main->cubecopytwo[y])
			return (1);
		empty_map_two(main, y, len);
		copy_map_two(main->cubecopytwo, main->cubecopy, y);
		ft_putstr(main->cubecopytwo[y]);
		y++;
	}
	main->cubecopytwo[yy] = (char *)malloc((len + 1) * sizeof(char));
	if (!main->cubecopytwo[yy])
		return (1);
	empty_map_two(main, yy, len);
	ft_putstr(main->cubecopytwo[yy]);
	return (0);
}

static int			map_copy_two(t_struct_m *main)
{
	int		y;
	int		yy;
	int		len;

	y = 1;
	yy = (main->Ray.yy + 2);
	main->cubecopytwo = NULL;
	if (!main->cubecopy)
		return (1);
	main->cubecopytwo = (char**)malloc(sizeof(char*) * (yy + 1));
	if (!main->cubecopytwo)
		return (1);
	len = ft_strlen(main->cubecopy[0]) + 2;
	main->cubecopytwo[0] = (char *)malloc((len + 1) * sizeof(char));
	empty_map_two(main, 0, len);
	ft_putstr(main->cubecopytwo[0]);
	if (fill_middle_copy(main, y, yy, len) == 1)
		return (1);
	return (0);
}

int					check_fill(t_struct_m *main)
{
	int	x;
	int	y;

	//empty space
	x = (int)(main->Ray.posX);
	y = (int)(main->Ray.posY);
	main->cubecopy[y][x] = '0';
	flood_fill(x, y, main);
	if (map_copy_two(main) == 1)
	{
		main->place.error_c = 46;
		ft_error(main);
		return (1);
	}
	y = 0;
	x = 0;
	while (y < (main->Ray.yy + 2))
	{
		main->cubecopy[y] = ft_strjoin(main->cubecopy[y], " ");
		y++;
	}
	y = 0;
	while (y < main->Ray.yy)
	{
		while (main->cubecopy[y][x])
		{
			if (main->cubecopy[y][x] == 'X')
				ft_check_empty(x, y, main);
			x++;
		}
		y++;
	}
	return (0);
}
