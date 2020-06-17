/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floor_casting.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/15 11:58:22 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/17 19:46:29 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void    ft_wall_posZ(t_struct_m *main)
{
    int     look;

    look = main->Ray.look * 20;
    if (look > 0)
    {
        main->keys.posZ += look;
        if (main->keys.posZ >= main->place.s_height)
            main->keys.posZ = main->place.s_height - 1;
    }
    else if (look < 0)
    {
        main->keys.posZ += look;
        if (main->keys.posZ < 0)
            main->keys.posZ = 0;
    }
}

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

		if (main->Ray.look < 0)
		{
			p = y - (main->place.s_height + main->Ray.look * 40) / 2;
			main->keys.posZ = 0.5 * (main->place.s_height + main->Ray.look * 40);
		}
		else if  (main->Ray.look >= 0)
		{
			p = y - (main->place.s_height - main->Ray.look * 40) / 2;
			main->keys.posZ = 0.5 * (main->place.s_height - main->Ray.look * 40);
		}
		ft_wall_posZ(main);
		rowDistance = main->keys.posZ / p;
		
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
