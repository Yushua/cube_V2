/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floor_casting.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/15 11:58:22 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/17 17:32:36 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int     ft_floor_casting(t_struct_m *main)
{
	int     y;
	int		x;
	int		texNum;
	y = 0;
	x = 0;
	texNum = 3;
	while (y < main->place.s_height)
	{
		float   rayDirX0;
		float   rayDirY0;
		float   rayDirX1;
		float   rayDirY1;
		int     p;
		float   posZ;
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
	
		rayDirX0 = main->Ray.dirX - main->Ray.planeX;
		rayDirY0 = main->Ray.dirY - main->Ray.planeY;
		rayDirX1 = main->Ray.dirX + main->Ray.planeX;
		rayDirY1 = main->Ray.dirY + main->Ray.planeY;
		p = y - main->place.s_height / 2;
		posZ = 0.5 * main->place.s_height;
		rowDistance = posZ / p;
		
		floorStepX = rowDistance * (rayDirX1 - rayDirX0) / main->place.s_width;
		floorStepY = rowDistance * (rayDirY1 - rayDirY0) / main->place.s_width;
		floorX = main->Ray.posX + rowDistance * rayDirX0;
		floorY = main->Ray.posY + rowDistance * rayDirY0;

		while (x < main->place.s_width)
		{
			cellX = (int)(floorX);
			cellY = (int)(floorY);
			tx = (int)(main->texture[texNum].texture_width * (floorX - cellX)) & (main->texture[texNum].texture_width - 1);
			ty = (int)(main->texture[texNum].texture_height * (floorY - cellY)) & (main->texture[texNum].texture_height - 1);

			floorX += floorStepX;
			floorY += floorStepY;

			colour = (main->texture[texNum].texture_adress[main->texture[texNum].texture_height * ty + tx]);
			my_mlx_pixel_put(main, x, y, colour);

			colour = (main->texture[texNum].texture_adress[main->texture[texNum].texture_height * ty + tx]);
			my_mlx_pixel_put(main, x, main->place.s_height - y - 1, colour);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

// int     ft_floor_casting(t_struct_m *main)
// {
// 	int     y;
// 	int		x;
// 	int		texNum;
// 	y = 0;
// 	x = 0;
// 	texNum = 3;
// 	while (y < main->place.s_height)
// 	{
// 		float   rayDirX1;
// 		float   rayDirY1;
		
// 		main->keys.rayDirX0 = main->Ray.dirX - main->Ray.planeX;
// 		main->keys.rayDirY0 = main->Ray.dirY - main->Ray.planeY;
// 		rayDirX1 = main->Ray.dirX + main->Ray.planeX;
// 		rayDirY1 = main->Ray.dirY + main->Ray.planeY;
// 		main->keys.p = y - main->place.s_height / 2;
// 		main->keys.posZ = 0.5 * main->place.s_height;
// 		main->keys.rowDistance = main->keys.posZ / main->keys.p;
		
// 		main->keys.floorStepX = main->keys.rowDistance * (rayDirX1 - main->keys.rayDirX0) / main->place.s_width;
// 		main->keys.floorStepY = main->keys.rowDistance * (rayDirY1 - main->keys.rayDirY0) / main->place.s_width;
// 		main->keys.floorX = main->Ray.posX + main->keys.rowDistance * main->keys.rayDirX0;
// 		main->keys.floorY = main->Ray.posY + main->keys.rowDistance * main->keys.rayDirY0;

// 		while (x < main->place.s_width)
// 		{
// 			main->keys.cellX = (int)(main->keys.floorX);
// 			main->keys.cellX = (int)(main->keys.floorY);
// 			main->keys.tx = (int)(main->texture[texNum].texture_width * (main->keys.floorX - main->keys.cellX)) & (main->texture[texNum].texture_width - 1);
// 			main->keys.ty = (int)(main->texture[texNum].texture_height * (main->keys.floorY - main->keys.cellX)) & (main->texture[texNum].texture_height - 1);

// 			main->keys.floorX += main->keys.floorStepX;
// 			main->keys.floorY += main->keys.floorStepY;

// 			main->keys.colour = (main->texture[texNum].texture_adress[main->texture[texNum].texture_height * main->keys.ty + main->keys.tx]);
// 			my_mlx_pixel_put(main, x, y, main->keys.colour);

// 			main->keys.colour = (main->texture[texNum].texture_adress[main->texture[texNum].texture_height * main->keys.ty + main->keys.tx]);
// 			my_mlx_pixel_put(main, x, main->place.s_height - y - 1, main->keys.colour);
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// 	return (0);
// }
