/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting_sprites.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/26 12:49:29 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int			render_next_frame_sprites(t_struct_m *main)
{
	int		i;
	int		y;
	int		d;
	int		texy;
	int		colour;
	int		texx;

	i = 0;
	while (i < main->numsprites)
	{
		main->spriteorder[i] = i;
		main->spritedistance[i] = ((main->ray.posx - main->sprites[i].x) *
		(main->ray.posx - main->sprites[i].x) + (main->ray.posy -
		main->sprites[i].y) * (main->ray.posy - main->sprites[i].y));
		i++;
	}
	bubble_sort(main);
	i = 0;
	while (i < main->numsprites)
	{
		main->sprite.spritex = main->sprites[main->spriteorder[i]].x -
		main->ray.posx;
		main->sprite.spritey = main->sprites[main->spriteorder[i]].y -
		main->ray.posy;
		main->sprite.invdet = 1.0 / (main->ray.planex * main->ray.diry -
		main->ray.dirx * main->ray.planey);
		main->sprite.transformx = main->sprite.invdet * (main->ray.diry *
		main->sprite.spritex - main->ray.dirx * main->sprite.spritey);
		main->sprite.transformy = main->sprite.invdet * (-main->ray.planey *
		main->sprite.spritex + main->ray.planex * main->sprite.spritey);

		main->sprite.spritescreenx = (int)((main->place.s_width / 2) *
		(1 + main->sprite.transformx / main->sprite.transformy));
#define udiv 1
#define vdiv 1
#define vmove 0.0

		main->sprite.spriteheight = abs((int)(main->place.s_height /
		(main->sprite.transformy)));

		main->sprite.drawstarty = -main->sprite.spriteheight / 2 +
		main->place.s_height / 2;
		if (main->sprite.drawstarty < 0)
			main->sprite.drawstarty = 0;
		main->sprite.drawendy = main->sprite.spriteheight / 2 +
		main->place.s_height / 2;
		if (main->sprite.drawendy >= main->place.s_height)
			main->sprite.drawendy = main->place.s_height - 1;
		main->sprite.spritewidth = abs((int)(main->place.s_height /
		(main->sprite.transformy)));
		main->sprite.drawstartx = -main->sprite.spritewidth /
		2 + main->sprite.spritescreenx;
		if (main->sprite.drawstartx < 0)
			main->sprite.drawstartx = 0;
		main->sprite.drawendx = main->sprite.spritewidth /
		2 + main->sprite.spritescreenx;
		if (main->sprite.drawendx >= main->place.s_width)
			main->sprite.drawendx = main->place.s_width - 1;
		main->sprite.stripe = main->sprite.drawstartx;
		while (main->sprite.stripe < main->sprite.drawendx)
		{
			texx = (int)(256 * (main->sprite.stripe -
			(-main->sprite.spritewidth / 2 + main->sprite.spritescreenx)) *
			main->texture->texture_width / main->sprite.spritewidth) / 256;
			y = main->sprite.drawstarty;
			if (main->sprite.transformy > 0 && main->sprite.stripe > 0 &&
			main->sprite.stripe < main->place.s_width &&
			main->sprite.transformy < main->zbuffer[main->sprite.stripe])
			{
				while (y < main->sprite.drawendy)
				{
					d = (y) * 256 - main->place.s_height * 128 +
					main->sprite.spriteheight * 128;
					texy = ((d * main->texture[4].texture_height) /
					main->sprite.spriteheight) / 256;
					colour = main->texture[4].texture_adress[main->texture[4].texture_width * texy + texx];
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
