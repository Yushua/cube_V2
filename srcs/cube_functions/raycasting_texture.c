/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting_texture.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/18 14:48:35 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void		ft_step_raycasting(t_struct_m *main)
{
	if (main->Ray.rayDirX < 0)
	{
		main->Ray.stepX = -1;
		main->Ray.sideDistX = (main->Ray.posX - main->Ray.mapX)
		* main->Ray.deltaDistX;
	}
	else
	{
		main->Ray.stepX = 1;
		main->Ray.sideDistX = (main->Ray.mapX + 1.0 - main->Ray.posX)
		* main->Ray.deltaDistX;
	}
	if (main->Ray.rayDirY < 0)
	{
		main->Ray.stepY = -1;
		main->Ray.sideDistY = (main->Ray.posY - main->Ray.mapY)
		* main->Ray.deltaDistY;
	}
	else
	{
		main->Ray.stepY = 1;
		main->Ray.sideDistY = (main->Ray.mapY + 1.0 - main->Ray.posY)
		* main->Ray.deltaDistY;
	}
}

static void			ft_location(t_struct_m *main)
{
	main->Ray.cameraX = 2 * main->Ray.x / (double)main->place.s_width - 1;
	main->Ray.rayDirX = main->Ray.dirX + main->Ray.planeX * main->Ray.cameraX;
	main->Ray.rayDirY = main->Ray.dirY + main->Ray.planeY * main->Ray.cameraX;
	main->Ray.mapX = (int)main->Ray.posX;
	main->Ray.mapY = (int)main->Ray.posY;
	main->Ray.hit = 0;
	main->Ray.deltaDistX = fabs(1 / main->Ray.rayDirX);
	main->Ray.deltaDistY = fabs(1 / main->Ray.rayDirY);
}

static void		ft_raycasting_hit(t_struct_m *main)
{
	while (main->Ray.hit == 0)
	{
		if (main->Ray.sideDistX < main->Ray.sideDistY)
		{
			main->Ray.sideDistX += main->Ray.deltaDistX;
			main->Ray.mapX += main->Ray.stepX;
			main->Ray.side = 0;
		}
		else
		{
			main->Ray.sideDistY += main->Ray.deltaDistY;
			main->Ray.mapY += main->Ray.stepY;
			main->Ray.side = 1;
		}
		if (main->place.cubemap[main->Ray.mapY][main->Ray.mapX] == '1')
			main->Ray.hit = 1;
	}
	if (main->Ray.side == 0)
		main->Ray.perpWallDist = ((main->Ray.mapX - main->Ray.posX + (1 -
		main->Ray.stepX) / 2) / main->Ray.rayDirX);
	else
		main->Ray.perpWallDist = ((main->Ray.mapY - main->Ray.posY + (1 -
		main->Ray.stepY) / 2) / main->Ray.rayDirY);
}

int				ft_raycasting(t_struct_m *main)
{
	main->Ray.x = 0;
	while (main->Ray.x < main->place.s_width)
	{
		ft_location(main);
		ft_step_raycasting(main);
		ft_raycasting_hit(main);
		main->Ray.lineHeight = (int)(main->place.s_height /
		main->Ray.perpWallDist);
		main->Ray.drawStart = (-main->Ray.lineHeight / 2 +
		(main->place.s_height / 2));
		if (main->Ray.drawStart < 0)
			main->Ray.drawStart = 0;
		main->Ray.drawEnd = (main->Ray.lineHeight / 2 +
		(main->place.s_height / 2));
		if (main->Ray.drawEnd >= main->place.s_height)
			main->Ray.drawEnd = main->place.s_height - 1;
		verline_structure(main);
		main->ZBuffer[main->Ray.x] = main->Ray.perpWallDist;
		main->Ray.x++;
	}
	return (0);
}
