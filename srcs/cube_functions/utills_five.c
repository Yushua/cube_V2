/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utills_five.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 18:50:30 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/08 10:29:26 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int			ft_error_map(t_struct_m *main, int fd)
{
	fd = open(main->map, O_RDONLY);
	if (fd < 0)
	{
		main->place.error = 24;
		ft_error(main);
		return (-2);
	}
	return (fd);
}

void		read_map_bmp(t_struct_m *main)
{
	if (ft_size_store_map(main) == 1)
	{
		ft_putstr("size store error");
		ft_end_function(main);
	}
	check_value(main);
	check_screen_bmp(main);
	set_location(main);
	spritesnumb(main);
	if (check_fill(main) == 1)
	{
		ft_putstr("error in check_fill");
		ft_end_function(main);
	}
	if (ft_check_empty_line(main, 0, 0) == 1)
	{
		ft_putstr("error in empty_line");
		ft_end_function(main);
	}
	printmap(main);
	if (main->place.error_n == 0)
	{
		ft_putstr(" error after map print");
		ft_end_function(main);
	}
}

void		check_screen_bmp(t_struct_m *main)
{
	if (main->place.s_height > 16000)
		main->place.s_height = 16000;
	if (main->place.s_width > 16000)
		main->place.s_width = 16000;
	if (main->place.s_height <= 0 || main->place.s_width <= 0)
	{
		main->place.error = 53;
		ft_error(main);
		ft_end_function(main);
	}
}
