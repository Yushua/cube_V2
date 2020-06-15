/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_bmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/15 10:26:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/15 11:02:58 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	ft_header_bmp(t_struct_m *main, int fd)
{
	int		width;
	int		y;
	char	s[54];

	ft_bzero(s, 54);
	width = main->place.s_width;
	write(fd, s, 54);
	return (y);
}

static void	ft_image(t_struct_m *main)
{
	main->img.img = mlx_new_image(main->vars.mlx, main->place.s_width, main->place.s_height);
	if (!main->img.img)
	{
		main->place.error_c = 24;//right
		ft_error(main);
	}
	main->img.addr = mlx_get_data_addr(main->img.img, &main->img.bits_per_pixel, &main->img.line_length,
                                 &main->img.endian);
	set_value_texture(main);
	ft_putstr("done, start drawing screenshot");
	render_next_frame_structure(main);
}

void		ft_bmp(t_struct_m *main)
{
	int			fd;
	char		*string;
	int			y;
    int         len;
    int         x:

	ft_image(main);
	fd = open("screen.bmp", O_RDWR | O_CREAT, 0666);
	y = ft_header_bmp(main, fd);
	len = main->place.s_height - 1;
	while (len >= 0)
	{
		x = 0;
		while (x < main->place.s_width)
		{
			string = (main->img.addr + (len * main->img.line_length + x * (main->img.bits_per_pixel / 8)));
			write(fd, string, 3);
			x++;
		}
		write(fd, "\0\0\0", y);
		len--;
	}
	ft_close(fd);
}