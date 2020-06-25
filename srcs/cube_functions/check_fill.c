/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 11:13:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/25 13:45:03 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int		check_fill_bottom(t_struct_m *main)
{
	int	x;
	int	y;

	y = main->Ray.yy;
	y--;
	x = 0;
	while (main->cubecopy[y][x])
	{
		if (main->cubecopy[y][x] == 'X')
		{
			main->place.error = 17;
			ft_error(main);
			return (1);
		}
		x++;
	}
	return (0);
}

static int		check_fill_top(t_struct_m *main)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (main->cubecopy[0][x])
	{
		if (main->cubecopy[0][x] == 'X')
		{
			main->place.error = 17;
			ft_error(main);
			return (1);
		}
		x++;
	}
	return (0);
}

static	int		check_fill_left(t_struct_m *main)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < main->Ray.yy)
	{
		if (main->cubecopy[y][x] == 'X')
		{
			main->place.error = 16;
			ft_error(main);
			return (1);
		}
		y++;
	}
	return (0);
}

static int		check_fill_right(t_struct_m *main)
{
	int	x;
	int	y;

	y = main->Ray.yy;
	while (y < main->Ray.yy)
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
	return (0);
}

int				check_fill(t_struct_m *main)
{
	int	x;
	int	y;

	x = (int)(main->Ray.posX);
	y = (int)(main->Ray.posY);
	main->cubecopy[y][x] = '0';
	flood_fill(x, y, main);
	x = 0;
	if (check_fill_right(main) == 1)
		x = 1;
	if (check_fill_left(main) == 1)
		x = 1;
	if (check_fill_top(main) == 1)
		x = 1;
	if (check_fill_bottom(main) == 1)
		x = 1;
	return (x);
}
