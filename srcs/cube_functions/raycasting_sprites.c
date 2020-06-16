/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting_sprites.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/16 13:26:16 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int         render_next_frame_sprites(t_struct_m *main)
{
	int i = 0;
	while (i < main->numSprites)
	{
		main->spriteOrder[i] = i;
		main->spriteDistance[i] = ((main->Ray.posX - main->sprites[i].x) * (main->Ray.posX - main->sprites[i].x) + (main->Ray.posY - main->sprites[i].y) * (main->Ray.posY - main->sprites[i].y));
		i++;
	}
	bubble_sort(main);
	i = 0;
	while (i < main->numSprites)
	{
		main->sprite.spritex = main->sprites[main->spriteOrder[i]].x - main->Ray.posX;
		main->sprite.spritey = main->sprites[main->spriteOrder[i]].y - main->Ray.posY;


		main->sprite.invDet = 1.0 / (main->Ray.planeX * main->Ray.dirY - main->Ray.dirX * main->Ray.planeY);

		main->sprite.transformX = main->sprite.invDet * (main->Ray.dirY * main->sprite.spritex - main->Ray.dirX * main->sprite.spritey);
		main->sprite.transformY = main->sprite.invDet * (-main->Ray.planeY * main->sprite.spritex + main->Ray.planeX * main->sprite.spritey);

		main->sprite.spriteScreenX = (int)((main->place.s_width / 2) * (1 + main->sprite.transformX / main->sprite.transformY));
		
		#define uDiv 1
		#define vDiv 1
		#define vMove 0.0

		main->sprite.spriteHeight = abs((int)(main->place.s_height / (main->sprite.transformY)));//using "transformY" instead of the real distance prevents fisheye

		main->sprite.drawStartY = -main->sprite.spriteHeight / 2 + main->place.s_height / 2;
		if (main->sprite.drawStartY < 0)
			main->sprite.drawStartY = 0;
		main->sprite.drawendY = main->sprite.spriteHeight / 2 + main->place.s_height / 2;
		if (main->sprite.drawendY >= main->place.s_height)
			main->sprite.drawendY = main->place.s_height - 1;
		main->sprite.spriteWidth = abs((int)(main->place.s_height / (main->sprite.transformY)));
		main->sprite.drawStartX = -main->sprite.spriteWidth / 2 + main->sprite.spriteScreenX;
		if (main->sprite.drawStartX < 0)
			main->sprite.drawStartX = 0;
		main->sprite.drawendX = main->sprite.spriteWidth / 2 + main->sprite.spriteScreenX;
		if (main->sprite.drawendX >= main->place.s_width)
			main->sprite.drawendX = main->place.s_width - 1;

		main->sprite.stripe = main->sprite.drawStartX;
		int		y;
		int		d;
		int		texY;
		int		colour;
		while (main->sprite.stripe < main->sprite.drawendX)
		{
			int		texX = (int)(256 * (main->sprite.stripe - (-main->sprite.spriteWidth / 2 + main->sprite.spriteScreenX)) * main->texture->texture_width / main->sprite.spriteWidth) / 256;
			y = main->sprite.drawStartY;
			if (main->sprite.transformY > 0 && main->sprite.stripe > 0 && main->sprite.stripe < main->place.s_width && main->sprite.transformY < main->ZBuffer[main->sprite.stripe])
			{
				while (y < main->sprite.drawendY)
				{
					d = (y) * 256 - main->place.s_height * 128 + main->sprite.spriteHeight * 128;
					texY = ((d * main->texture[4].texture_height) / main->sprite.spriteHeight) / 256;
					colour	= main->texture[4].texture_adress[main->texture[4].texture_width * texY + texX];
					if (colour != 0)
						my_mlx_pixel_put(main, main->sprite.stripe, y, colour);
					y++;
				}	
			}
			main->sprite.stripe++;
		}
		i++;
	}
}