/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_empty_line.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/24 12:34:03 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/24 18:14:32 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int			ft_check_empty_line(t_struct_m *main)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	//vertical
	y = 0;
	while (main->cubecopy[0][x])
	{
		if (main->cubecopy[0][x] == ' ')
		{
			while (y <= main->Ray.yy)
			{
				if (main->cubecopy[0][x] != ' ')
				break ;
			}
			return (1);
		}
		y = 0;
		x++;
	}
	return (0);
}
