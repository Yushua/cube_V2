/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_floodfill_extra.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 15:05:44 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/26 15:17:48 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void			if_x(int x, int y, t_struct_m *main)
{
	if (main->cubecopy[y][x] == '0' || main->cubecopy[y][x] == '2')
		main->cubecopy[y][x] = 'X';
}

static void		ft_place_x(t_struct_m *main, int x, int y)
{
	if_x(x - 1, y, main);
	if_x(x + 1, y, main);
	if_x(x, y - 1, main);
	if_x(x, y + 1, main);
}

void			ft_floodfill_extra(t_struct_m *main, int x, int y)
{
	while (y < main->ray.yy)
	{
		while (main->cubecopy[x][y])
		{
			if (main->cubecopy[x][y] == 'X')
				ft_place_x(main, x, y);
			x++;
		}
		y++;
	}
}
