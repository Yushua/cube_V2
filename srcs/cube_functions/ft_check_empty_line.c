/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_empty_line.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/24 12:34:03 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/25 14:36:21 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int			ft_check_empty_line(t_struct_m *main, int x, int y)
{
	int		yy;

	yy = main->Ray.yy;
	yy--;
	while (main->cubecopy[y][x])
	{
		if (main->cubecopy[y][x] == ' ')
		{
			while (y < yy && main->cubecopy[y][x] == ' ')
				y++;
			if (main->cubecopy[y][x] == ' ')
				return (1);
		}
		y = 0;
		x++;
	}
	return (0);
}
