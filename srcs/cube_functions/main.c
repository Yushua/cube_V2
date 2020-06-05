/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/05 14:28:06 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int     main(void)
{
    t_struct_m *main;
    
    main = ft_calloc(1, sizeof(t_struct_m));
    
    background(main);
    set_value(main);
    ft_size_store_map(main);
    readmap(main);
    set_location(main);
    ft_putstr("this means my other functions stil work\n");
    //map_correct(main);
    printmap(main);
    spritesnumb(main);
	ft_putstr("begin fill check");
	// check_fill(main);
    if (main->place.error == -1)
        ft_putstr("no error\n");
    // else if (main->place.error_c == 0) //don't forget to free
    //     return (0);
    ft_putstr("data");
	int i = 0;
    main->vars.mlx = mlx_init();
    main->vars.win = mlx_new_window(main->vars.mlx, main->place.s_width, main->place.s_height, "cube");
    main->img.img = mlx_new_image(main->vars.mlx, main->place.s_width, main->place.s_height);
    main->img.addr = mlx_get_data_addr(main->img.img, &main->img.bits_per_pixel, &main->img.line_length,
                                 &main->img.endian);
    set_value_texture(main);
	ft_putstr("done");
	// mlx_loop_hook(main->vars.mlx, render_next_frame, main);
    mlx_loop_hook(main->vars.mlx, render_next_frame_structure, main);
    mlx_hook(main->vars.win, 2, 1L<<0, wasd_2, main);
    mlx_loop(main->vars.mlx);
}