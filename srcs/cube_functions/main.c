/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/16 19:04:32 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void    ft_end_function(t_struct_m *main)
{
	exit(0);
}

int             ft_close(int keycode, t_struct_m *main)
{
	ft_end_function(main);
	return (0);
}

int     main()
{       
	t_struct_m *main;
	
	main = ft_calloc(1, sizeof(t_struct_m));
	
	background(main);
	set_value(main);
	// readmap(main);
	ft_read_map(main);
	ft_size_store_map(main);
	if (ft_read_map(main) == 2)
	{
		ft_putstr(" not enough information");
		ft_end_function(main);
	}
	set_location(main);
	spritesnumb(main);
	check_fill(main);
	printmap(main);
	// else if (main->place.error_c == 0) //don't forget to free wrong with error
	//     ft_end_function(main);
	ft_putstr("data");
	int i = 0;
	main->vars.mlx = mlx_init();
	// if (ft_strncmp(argv[2], " --save", ft_strlen(ft_strlen(argv[2]))) == 0)
	// {
	// 	ft_putstr("start screenshot");
	// 	ft_bmp(main);
	// 	ft_putstr("screenshot finished");
	// }
	// ft_bmp(main);
	// ft_end_function(main);
	main->vars.win = mlx_new_window(main->vars.mlx, main->place.s_width, main->place.s_height, "cube");
	main->img.img = mlx_new_image(main->vars.mlx, main->place.s_width, main->place.s_height);
	if (!main->img.img)
	{
		main->place.error_c = 24;//right
		ft_error(main);
	}
	main->img.addr = mlx_get_data_addr(main->img.img, &main->img.bits_per_pixel, &main->img.line_length,
								 &main->img.endian);
	set_value_texture(main);
	ft_putstr("done");
	// if (main->place.error_c == 0)
	// 	ft_end_function(main);
	
	ft_putstr(" no error");
	mlx_hook(main->vars.win, 2, 1L<<0, ft_push_key, main);
	mlx_hook(main->vars.win, 3, 1L<<1, ft_release_key, main);
	mlx_hook(main->vars.win, 17, 1L<<0, ft_close, main);
	mlx_loop_hook(main->vars.mlx, render_next_frame_structure, main);
	mlx_loop(main->vars.mlx);
}