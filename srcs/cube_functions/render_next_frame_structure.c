/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_next_frame_structure.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 13:24:45 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/18 13:25:28 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int 	render_next_frame_structure(t_struct_m *main)
{
	wasd_2(main);
	ft_floor_casting(main);
	ft_cealing_casting(main);
	ft_raycasting(main);
	render_next_frame_sprites(main);
	mlx_put_image_to_window(main->vars.mlx, main->vars.win, main->img.img, 0, 0);
	mlx_destroy_image(main->vars.mlx, main->img.img);
	main->img.img = mlx_new_image(main->vars.mlx, main->place.s_width, main->place.s_height);
	main->img.addr = mlx_get_data_addr(main->img.img, &main->img.bits_per_pixel,
			&main->img.line_length, &main->img.endian);
	if (main->keys.UP > 0)
		main->keys.UP = -1;
	else if (main->keys.DOW > 0)
		main->keys.DOW = -1;
	return (0);
}
