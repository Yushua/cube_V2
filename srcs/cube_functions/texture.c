/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/15 11:32:35 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void            my_mlx_pixel_put(t_struct_m *main, int x, int y, int color)
{
    char    *dst;

    dst = main->img.addr + (y * main->img.line_length + x * (main->img.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int 	background(t_struct_m *main)
{
	int x = 0;
	int y = 0;
    int col = 0xffffffff;

	while (y < main->place.s_height)
	{
		while (x < main->place.s_width)
		{
			my_mlx_pixel_put(main, x, y, col);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
