/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 11:13:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/24 11:54:38 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int				check_fill(t_struct_m *main)
{
	int	x;
	int	y;

	x = (int)(main->Ray.posX);
	y = (int)(main->Ray.posY);
	main->cubecopy[y][x] = '0';
	flood_fill(x, y, main);
	y = 0;
	while (y <= main->Ray.yy)//left
	{
		while (main->cubecopy[y][x])
		{
			if (main->cubecopy[y][x] == 'X')
			{
				main->place.error = 16;
				ft_error(main);
				return (1);
			}
			x++;
		}
		y++;
	}
	while (y <= main->Ray.yy)//right
	{
		x = ft_strlen(main->cubecopy[y]);
		if (main->cubecopy[y][x] == 'X')
		{
			main->place.error = 17;
			ft_error(main);
			return (1);
		}
		y++;
	}
	x = 0;
	while (main->cubecopy[0][x])//top
	{
		if (main->cubecopy[0][x] == 'X')
		{
			main->place.error = 17;
			ft_error(main);
			return (1);
		}
		x++;
	}
	y = main->Ray.yy;
	while (main->cubecopy[y][x])//bottom
	{
		if (main->cubecopy[y][x] == 'X')
		{
			main->place.error = 17;
			ft_error(main);
			return (1);
		}
		x++;
	}
	ft_putstr("done");
	return (0);
}
