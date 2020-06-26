/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floor_casting.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/15 11:58:22 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/26 12:51:19 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int     ft_floor_casting(t_struct_m *main)
{
	int		y;
	int		x;
	int		texnum;

	y = 0;
	x = 0;
	texnum = 3;
	while (y < main->place.s_height)
	{
		float	raydirx0;
		float	raydiry0;
		float	raydirx1;
		float	raydiry1;
		int		p;
		float	rowdistance;
		float	floorstepx;
		float	floorstepy;
		float	floorx;
		float	floory;
		int		cellx;
		int		celly;
		int		tx;
		int		ty;
		int		colour;

		raydirx0 = main->ray.dirx - main->ray.planex;
		raydiry0 = main->ray.diry - main->ray.planey;
		raydirx1 = main->ray.dirx + main->ray.planex;
		raydiry1 = main->ray.diry + main->ray.planey;
		p = y - main->place.s_height / 2;
		main->keys.posz = 0.5 * main->place.s_height;
		rowdistance = main->keys.posz / p;
		floorstepx = rowdistance * (raydirx1 - raydirx0) / main->place.s_width;
		floorstepy = rowdistance * (raydiry1 - raydiry0) / main->place.s_width;
		floorx = main->ray.posx + rowdistance * raydirx0;
		floory = main->ray.posy + rowdistance * raydiry0;
		while (x < main->place.s_width)
		{
			cellx = (int)(floorx);
			celly = (int)(floory);
			tx = (int)(main->texture[3].texture_width * (floorx - cellx))
			& (main->texture[3].texture_width - 1);
			ty = (int)(main->texture[3].texture_height * (floory - celly))
			& (main->texture[3].texture_height - 1);
			floorx += floorstepx;
			floory += floorstepy;
			colour = (main->texture[3].texture_adress
			[main->texture[3].texture_height * ty + tx]);
			my_mlx_pixel_put(main, x, y, colour);
			colour = (main->texture[3].texture_adress
			[main->texture[3].texture_height * ty + tx]);
			my_mlx_pixel_put(main, x, main->place.s_height - y - 1, colour);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
