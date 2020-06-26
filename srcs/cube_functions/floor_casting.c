/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floor_casting.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/15 11:58:22 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/26 11:31:33 by ybakker       ########   odam.nl         */
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
		float   rayDirX1;
		float   rayDirY1;
		int     p;
		float   rowDistance;
		float   floorStepX;
		float   floorStepY;
		float   floorX;
		float   floorY;
		int     cellX;
		int     cellY;
		int     tx;
		int     ty;
		int     colour;

		raydirx0 = main->Ray.dirX - main->Ray.planeX;
		raydiry0 = main->Ray.dirY - main->Ray.planeY;
		rayDirX1 = main->Ray.dirX + main->Ray.planeX;
		rayDirY1 = main->Ray.dirY + main->Ray.planeY;
		p = y - main->place.s_height / 2;
		main->keys.posZ = 0.5 * main->place.s_height;
		rowDistance = main->keys.posZ / p;
		floorStepX = rowDistance * (rayDirX1 - raydirx0) / main->place.s_width;
		floorStepY = rowDistance * (rayDirY1 - raydiry0) / main->place.s_width;
		floorX = main->Ray.posX + rowDistance * raydirx0;
		floorY = main->Ray.posY + rowDistance * raydiry0;
		while (x < main->place.s_width)
		{
			cellX = (int)(floorX);
			cellY = (int)(floorY);
			tx = (int)(main->texture[3].texture_width * (floorX - cellX))
			& (main->texture[3].texture_width - 1);
			ty = (int)(main->texture[3].texture_height * (floorY - cellY))
			& (main->texture[3].texture_height - 1);
			floorX += floorStepX;
			floorY += floorStepY;
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
