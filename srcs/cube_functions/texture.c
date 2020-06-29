/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 14:32:24 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void			my_mlx_pixel_put(t_struct_m *main, int x, int y, int color)
{
	char	*dst;

	dst = main->img.addr + (y * main->img.line_length + x *
	(main->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int				background(t_struct_m *main)
{
	int		x;
	int		y;
	int		m;
	int		colour;

	x = 0;
	y = 0;
	m = main->place.s_height / 2;
	colour = create_trgb(main->place.fcol1, main->place.fcol2,
	main->place.fcol3);
	while (y < m)
	{
		while (x < main->place.s_width)
		{
			my_mlx_pixel_put(main, x, y, colour);
			x++;
		}
		x = 0;
		y++;
	}
	colour = create_trgb(main->place.ccol1, main->place.ccol2,
	main->place.ccol3);
	x = 0;
	while (m < main->place.s_height)
	{
		while (x < main->place.s_width)
		{
			my_mlx_pixel_put(main, x, m, colour);
			x++;
		}
		x = 0;
		m++;
	}
	return (0);
}
