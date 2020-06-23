/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 11:13:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/23 20:12:20 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char			copy_map_two(char **copy, char **org, int y)
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

int				check_fill(t_struct_m *main)
{
	int	x;
	int	y;

	// ft_empty_space(main);//empty line check, make sure that you stop when there is no map left else errors
	x = (int)(main->Ray.posX);
	y = (int)(main->Ray.posY);
	main->cubecopy[y][x] = '0';
	flood_fill(x, y, main);
	ft_putstr("-start copy empty space-");
	if (map_copy_two(main) == 1)
	{
		main->place.error = 46;
		ft_error(main);
		return (1);
	}
	// if (map_fill_two(main) == 1)
	// {
	// 	main->place.error = 46;
	// 	ft_error(main);
	// 	return (1);
	// }
	y = 0;
	while (y < (main->Ray.yy + 2))
	{
		main->cubecopytwo[y] = ft_strjoin(main->cubecopytwo[y], " ");
		y++;
	}
	y = 0;
	ft_putstr("-copy check-");
	while (y < (main->Ray.yy) + 2)
	{
		ft_putstr(main->cubecopytwo[y]);
		y++;
	}
	y = 0;
	x = 0;
	while (y < main->Ray.yy + 2)
	{
		while (main->cubecopytwo[y][x])
		{
			if (main->cubecopytwo[y][x] == 'X')
				ft_check_empty(x, y, main);
			x++;
		}
		y++;
	}
	return (0);
}
