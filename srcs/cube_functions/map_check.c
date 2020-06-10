/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 11:53:18 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/10 12:03:10 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		if_empty(int x, int y, t_struct_m *main)
{
	// if (y < 0 || x < 0)//check if the cordinates don't go out of the map
	// 	return (0);
	if (main->cubecopy[y][x] == ' ')
	{
		printf("hello\n");
		main->place.error_c = 17;
		ft_error(main);
		return (0);
	}
}

int		flood_fill(int x, int y, t_struct_m *main)
{
	// if (main->cubecopy[y][x] == '1' || main->cubecopy[y][x] == color)
	// 	return 0;
	// if (main->cubecopy[y][x] != '0')
	// 	return 0;
	// main->cubecopy[y][x] = 'X';
	// if (y + 1 < main->Ray.yy)
	// 	flood_fill(y = 1, x, main);
	// if (y - 1 >= 0)
	// 	flood_fill(y - 1, x, main);
	// if (x - 1 >= 0)
	// 	flood_fill(y, x - 1, main);
	// if (x + 1 < ft_strlen(main->cubecopy[y]))
	// 	flood_fill(y, x + 1, main);
}

int		check_fill(t_struct_m *main)
{
	int	x = main->Ray.posY;
	int	y = main->Ray.posX;
	// flood_fill(x, y,main);
	y = 0;
	x = 0;
	while (main->cubecopy[0][x])
	{
		if (main->cubecopy[0][x] != '1') && main->cubecopy[0][x] != ' ')
		{
			main->place.error_c = 15;//top
			ft_error(main);
			return (0);
		}
	}
	x = 0;
	while (main->cubecopy[main->Ray.yy][x])
	{
		if (main->cubecopy[main->Ray.yy][x] != '1' && main->cubecopy[main->Ray.yy][x] != ' ')
		{
			main->place.error_c = 15;//bottom
			ft_error(main);
			return (0);
		}
		x++;
	}
	while (y < main->Ray.yy)
	{
        if (main->cubecopy[y][0] != '1' && main->cubecopy[y][0] != ' ')//first in the line
		{
            main->place.error_c = 16;//left
			ft_error(main);
			return (0);
		}
        x = ft_strlen(main->cubecopy[y])
        if (main->cubecopy[y][x] != '1' && main->cubecopy[y][x] != ' ')//first in the line
		{
            main->place.error_c = 17;//right
			ft_error(main);
			return (0);
		}
        x = 0;
		while (main->cubecopy[y][x])
		{
			if (main->cubecopy[y][x] != '1')//place with the where yu look
			{ 
			}
			x++;
		}
		y++;
	}
}