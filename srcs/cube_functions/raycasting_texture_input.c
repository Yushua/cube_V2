/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting_texture_input.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 13:52:53 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/18 14:48:23 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void		ft_wall(t_struct_m *main)
{
	if (main->Ray.side == 0)
		main->Ray.wallX = main->Ray.posY + main->Ray.perpWallDist *
		main->Ray.rayDirY;
	else
		main->Ray.wallX = main->Ray.posX + main->Ray.perpWallDist *
		main->Ray.rayDirX;
	main->Ray.wallX -= floor(main->Ray.wallX);
	main->Ray.texX = (int)(main->Ray.wallX * (double)
	(main->texture[main->Ray.texNum].texture_width));
	if (main->Ray.side == 0 && main->Ray.rayDirX > 0)
		main->Ray.texX = main->texture[main->Ray.texNum].texture_width
		- main->Ray.texX - 1;
	if (main->Ray.side == 1 && main->Ray.rayDirY < 0)
		main->Ray.texX = main->texture[main->Ray.texNum].texture_width
		- main->Ray.texX - 1;
	main->Ray.step = 1.0 * main->texture[main->Ray.texNum].texture_height
	/ main->Ray.lineHeight;
	main->Ray.texPos = (main->Ray.drawStart - main->place.s_height / 2
	+ main->Ray.lineHeight / 2) * main->Ray.step;
}

static void		ft_wall_texture_input(t_struct_m *main)
{
	int		colour;

	colour = 0;
	while (main->Ray.drawStart <= main->Ray.drawEnd)
	{
		main->Ray.texY = (int)(main->Ray.texPos) &
		(main->texture[main->Ray.texNum].texture_height - 1);
		main->Ray.texPos += main->Ray.step;
		colour = (main->texture[main->Ray.texNum].texture_adress
		[main->texture[main->Ray.texNum].texture_height *
		main->Ray.texY + main->Ray.texX]);
		my_mlx_pixel_put(main, main->Ray.x, main->Ray.drawStart, colour);
		main->Ray.drawStart++;
	}
}

void			verline_structure(t_struct_m *main)
{
	int		h;
	int		i;
	int		colour;

	h = main->place.s_height / 2;
	i = 0;
	if (main->Ray.side == 0)
	{
		if (main->Ray.posX > main->Ray.mapX)
			main->Ray.texNum = 0;
		if (main->Ray.posX < main->Ray.mapX)
			main->Ray.texNum = 1;
	}
	if (main->Ray.side == 1)
	{
		if (main->Ray.posY > main->Ray.mapY)
			main->Ray.texNum = 2;
		if (main->Ray.posY < main->Ray.mapY)
			main->Ray.texNum = 3;
	}
	ft_wall(main);
	ft_wall_texture_input(main);
}
