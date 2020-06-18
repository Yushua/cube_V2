/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 13:26:33 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/18 15:45:34 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int				ft_push_key(int keycode, t_struct_m *main)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(main->vars.mlx, main->vars.win);
		ft_end_function(main);
	}
	if (keycode == W_KEY && main->keys.S != 1)
		main->keys.W = 1;
	if (keycode == S_KEY && main->keys.W != 1)
		main->keys.S = 1;
	if (keycode == A_KEY && main->keys.D != 1)
		main->keys.A = 1;
	if (keycode == D_KEY && main->keys.A != 1)
		main->keys.D = 1;
	if (keycode == LEF_KEY && main->keys.RIG != 1)
		main->keys.LEF = 1;
	if (keycode == RIG_KEY && main->keys.LEF != 1)
		main->keys.RIG = 1;
	if (keycode == DOW_KEY && main->keys.UP != 1)
		main->keys.DOW = 1;
	if (keycode == UP_KEY && main->keys.DOW != 1)
		main->keys.UP = 1;
	return (0);
}

int				ft_release_key(int keycode, t_struct_m *main)
{
	if (keycode == W_KEY)
		main->keys.W = 0;
	if (keycode == S_KEY)
		main->keys.S = 0;
	if (keycode == A_KEY)
		main->keys.A = 0;
	if (keycode == D_KEY)
		main->keys.D = 0;
	if (keycode == LEF_KEY)
		main->keys.LEF = 0;
	if (keycode == RIG_KEY)
		main->keys.RIG = 0;
	if (keycode == UP_KEY)
		main->keys.UP = 0;
	if (keycode == DOW_KEY)
		main->keys.DOW = 0;
	return (0);
}

int				wasd_2(t_struct_m *main)
{
	double movesp;
	double rotsp;

	movesp = 0.07;
	rotsp = 0.05;
	if (main->keys.W)
	{
		if (main->place.cubemap[(int)(main->Ray.posY)][(int)(main->Ray.posX
		+ main->Ray.dirX * movesp)] != '1')
			main->Ray.posX += main->Ray.dirX * movesp;
		if (main->place.cubemap[(int)(main->Ray.posY + main->Ray.dirY
		* movesp)][(int)(main->Ray.posX)] != '1')
			main->Ray.posY += main->Ray.dirY * movesp;
	}
	wasd_s_d(main, movesp, rotsp);
	wasd_a(main, movesp, rotsp);
	wasd_r_l(main, movesp, rotsp);
	return (0);
}
