/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 11:22:49 by liz           #+#    #+#                 */
/*   Updated: 2020/06/16 13:40:23 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

​
int raycasting_loop(t_data *data)
{
		data->ray->cameraX = 2 * data->ray->x_ray / (double)data->width - 1; //x-coordinate in camera space
		data->ray->rayDirX = data->ray->dirX + data->ray->planeX * data->ray->cameraX;
		data->ray->rayDirY = data->ray->dirY + data->ray->planeY * data->ray->cameraX;
		data->ray->mapX = (int)data->ray->posX;
		data->ray->mapY = (int)data->ray->posY;
		data->ray->hit = 0;
		data->ray->deltaDistX = fabs(1 / data->ray->rayDirX);
		data->ray->deltaDistY = fabs(1 / data->ray->rayDirY);
		if (data->ray->rayDirX < 0)
		{
			data->ray->stepX = -1;
			data->ray->sideDistX = (data->ray->posX - data->ray->mapX) * data->ray->deltaDistX;
		}
		else
		{
			data->ray->stepX = 1;
			data->ray->sideDistX = (data->ray->mapX + 1.0 - data->ray->posX) * data->ray->deltaDistX;
		}
		if (data->ray->rayDirY < 0)
		{
			data->ray->stepY = -1;
			data->ray->sideDistY = (data->ray->posY - data->ray->mapY) * data->ray->deltaDistY;
		}
		else
		{
			data->ray->stepY = 1;
			data->ray->sideDistY = (data->ray->mapY + 1.0 - data->ray->posY) * data->ray->deltaDistY;
		}
		while (data->ray->hit == 0)
		{
			if (data->ray->sideDistX < data->ray->sideDistY)
			{
				data->ray->sideDistX += data->ray->deltaDistX;
				data->ray->mapX += data->ray->stepX;
				data->ray->side = 0;
			}
			else
			{
				data->ray->sideDistY += data->ray->deltaDistY;
				data->ray->mapY += data->ray->stepY;
				data->ray->side = 1;
			}
			//check if ray had hit a wall
			if (data->map->array_map_int[data->ray->mapX][data->ray->mapY] > 0)
				data->ray->hit = 1;
		}
		if (data->ray->side == 0)
			data->ray->perpWallDist = (data->ray->mapX - data->ray->posX + (1 - data->ray->stepX) / 2) / data->ray->rayDirX;
		else
			data->ray->perpWallDist = (data->ray->mapY - data->ray->posY + (1 - data->ray->stepY) / 2) / data->ray->rayDirY;
		data->ray->lineHeight =(int)(data->height / data->ray->perpWallDist);
		data->ray->drawStart = -data->ray->lineHeight / 2 + data->height / 2;
		if (data->ray->drawStart < 0)
			data->ray->drawStart = 0;
		data->ray->drawEnd = data->ray->lineHeight / 2 + data->height / 2;
		if (data->ray->drawEnd >= data->height)
			data->ray->drawEnd = data->height - 1;
		if (data->map->array_map_int[data->ray->mapX][data->ray->mapY] == 1)
			data->ray->color_ray = create_trgb(1, 123,234,123);
		if (data->map->array_map_int[data->ray->mapX][data->ray->mapY] == 2)
			data->ray->color_ray = create_trgb(1, 225, 123, 225);
		if (data->ray->side == 1)
		{
			data->ray->color_ray = data->ray->color_ray / 2;	
		}
		draw_line(data->ray->x_ray, data->ray->drawStart, data->ray->drawEnd, data->ray->color_ray, data);
		data->ray->x_ray++;
}
​