/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/16 13:28:48 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

#define ESC 53
#define W_KEY 13
#define S_KEY 1
#define A_KEY 0
#define D_KEY 2
#define UP_KEY 126
#define DOW_KEY 125
#define LEF_KEY 123
#define RIG_KEY 124

static void    ft_end_function(t_struct_m *main)
{
	exit(0);
}

int             ft_push_key(int keycode, t_struct_m *main)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(main->vars.mlx, main->vars.win);
		ft_end_function(main);
	}
	if (keycode == W_KEY && main->keys.S != 1)
	{
		main->keys.W = 1;
	}
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
	return (0);
}

int             ft_release_key(int keycode, t_struct_m *main)
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
	return (0);
}

int             ft_close(int keycode, t_struct_m *main)
{
	ft_end_function(main);
	return (0);
}

int     main(int argc, char **argv)
{       
	t_struct_m *main;
	
	main = ft_calloc(1, sizeof(t_struct_m));
	
	background(main);
	set_value(main);
	ft_size_store_map(main);
	readmap(main);
	set_location(main);
	ft_putstr("this means my other functions stil work\n");
	spritesnumb(main);
	ft_putstr("begin fill check");
	check_fill(main);
	printmap(main);
	if (main->place.error == -1)
		ft_putstr("no error\n");
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