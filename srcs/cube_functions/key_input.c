/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 15:45:22 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/18 15:46:25 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void			wasd_s_d(t_struct_m *main, double movesp, double rotsp)
{
	double olddirx;
	double oldplanex;

	if (main->keys.S)
	{
		if (main->place.cubemap[(int)(main->Ray.posY)][(int)(main->Ray.posX -
		main->Ray.dirX * movesp)] != '1')
			main->Ray.posX -= main->Ray.dirX * movesp;
		if (main->place.cubemap[(int)(main->Ray.posY - main->Ray.dirY *
		movesp)][(int)(main->Ray.posX)] != '1')
			main->Ray.posY -= main->Ray.dirY * movesp;
	}
	if (main->keys.D)
	{
		olddirx = main->Ray.dirX;
		main->Ray.dirX = main->Ray.dirX * cos(rotsp) -
		main->Ray.dirY * sin(rotsp);
		main->Ray.dirY = olddirx * sin(rotsp) + main->Ray.dirY * cos(rotsp);
		oldplanex = main->Ray.planeX;
		main->Ray.planeX = main->Ray.planeX * cos(rotsp)
		- main->Ray.planeY * sin(rotsp);
		main->Ray.planeY = oldplanex * sin(rotsp) +
		main->Ray.planeY * cos(rotsp);
	}
}

void			wasd_a(t_struct_m *main, double movesp, double rotsp)
{
	double olddirx;
	double oldplanex;

	if (main->keys.A)
	{
		olddirx = main->Ray.dirX;
		main->Ray.dirX = main->Ray.dirX * cos(-rotsp) -
		main->Ray.dirY * sin(-rotsp);
		main->Ray.dirY = olddirx * sin(-rotsp) + main->Ray.dirY * cos(-rotsp);
		oldplanex = main->Ray.planeX;
		main->Ray.planeX = main->Ray.planeX * cos(-rotsp) -
		main->Ray.planeY * sin(-rotsp);
		main->Ray.planeY = oldplanex * sin(-rotsp) +
		main->Ray.planeY * cos(-rotsp);
	}
}

void			wasd_r_l(t_struct_m *main, double movesp, double rotsp)
{
	if (main->keys.RIG)
	{
		if (main->place.cubemap[(int)(main->Ray.posY)][(int)(main->Ray.posX
		+ main->Ray.planeX * movesp)] != '1')
			main->Ray.posX += main->Ray.planeX * movesp;
		if (main->place.cubemap[(int)(main->Ray.posY + main->Ray.planeY *
		movesp)][(int)(main->Ray.posX)] != '1')
			main->Ray.posY += main->Ray.planeY * movesp;
	}
	if (main->keys.LEF)
	{
		if (main->place.cubemap[(int)(main->Ray.posY)][(int)(main->Ray.posX -
		main->Ray.planeX * movesp)] != '1')
			main->Ray.posX -= main->Ray.planeX * movesp;
		if (main->place.cubemap[(int)(main->Ray.posY - main->Ray.planeY *
		movesp)][(int)(main->Ray.posX)] != '1')
			main->Ray.posY -= main->Ray.planeY * movesp;
	}
}
