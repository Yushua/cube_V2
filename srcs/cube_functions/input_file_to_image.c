/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_file_to_image.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 15:16:25 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/18 15:19:09 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void			set_value_texture_no(t_struct_m *main, int fd)
{
	ft_putstr("NO");
	ft_putstr(main->place.NO);
	fd = open(main->place.NO, O_RDONLY);
	if (fd != -1)
	{
		if (ft_strnstr(main->place.NO, ".xpm",
		ft_strlen(main->place.NO)) != NULL)
		{
			main->texture[0].texture = mlx_xpm_file_to_image(main->vars.mlx,
			main->place.NO, &(main->texture[0].texture_width),
			&(main->texture[0].texture_height));
		}
		else if (ft_strnstr(main->place.NO, ".png",
		ft_strlen(main->place.NO)) != NULL)
		{
			main->texture[0].texture = mlx_png_file_to_image(main->vars.mlx,
			main->place.NO, &(main->texture[0].texture_width),
			&(main->texture[0].texture_height));
		}
	}
	else
	{
		main->place.error_c = 19;
		ft_error(main);
	}
}

void			set_value_texture_so(t_struct_m *main, int fd)
{
	ft_putstr("SO");
	ft_putstr(main->place.SO);
	fd = open(main->place.SO, O_RDONLY);
	if (fd != -1)
	{
		if (ft_strnstr(main->place.SO, ".xpm",
		ft_strlen(main->place.SO)) != NULL)
		{
			main->texture[1].texture = mlx_xpm_file_to_image(main->vars.mlx,
			main->place.SO, &(main->texture[1].texture_width),
			&(main->texture[1].texture_height));
		}
		else if (ft_strnstr(main->place.SO, ".png",
		ft_strlen(main->place.SO)) != NULL)
		{
			main->texture[1].texture = mlx_png_file_to_image(main->vars.mlx,
			main->place.SO, &(main->texture[1].texture_width),
			&(main->texture[1].texture_height));
		}
	}
	else
	{
		main->place.error_c = 20;
		ft_error(main);
	}
}

void			set_value_texture_we(t_struct_m *main, int fd)
{
	ft_putstr("WE");
	ft_putstr(main->place.WE);
	fd = open(main->place.WE, O_RDONLY);
	if (fd != -1)
	{
		if (ft_strnstr(main->place.WE, ".xpm",
		ft_strlen(main->place.WE)) != NULL)
		{
			main->texture[2].texture = mlx_xpm_file_to_image(main->vars.mlx,
			main->place.WE, &(main->texture[2].texture_width),
			&(main->texture[2].texture_height));
		}
		else if (ft_strnstr(main->place.WE, ".png",
		ft_strlen(main->place.WE)) != NULL)
		{
			main->texture[2].texture = mlx_png_file_to_image(main->vars.mlx,
			main->place.WE, &(main->texture[2].texture_width),
			&(main->texture[2].texture_height));
		}
	}
	else
	{
		main->place.error_c = 21;
		ft_error(main);
	}
}

void			set_value_texture_s(t_struct_m *main, int fd)
{
	ft_putstr("S");
	ft_putstr(main->place.S);
	fd = open(main->place.S, O_RDONLY);
	if (fd != -1)
	{
		if (ft_strnstr(main->place.S, ".xpm",
		ft_strlen(main->place.S)) != NULL)
		{
			main->texture[4].texture = mlx_xpm_file_to_image(main->vars.mlx,
			main->place.S, &main->texture[4].texture_width,
			&main->texture[4].texture_height);
		}
		else if (ft_strnstr(main->place.S, ".png",
		ft_strlen(main->place.S)) != NULL)
		{
			main->texture[4].texture = mlx_png_file_to_image(main->vars.mlx,
			main->place.S, &main->texture[4].texture_width,
			&main->texture[4].texture_height);
		}
	}
	else
	{
		main->place.error_c = 23;
		ft_error(main);
	}
}

void			set_value_texture_ea(t_struct_m *main, int fd)
{
	ft_putstr("EA");
	ft_putstr(main->place.EA);
	fd = open(main->place.EA, O_RDONLY);
	if (fd != -1)
	{
		if (ft_strnstr(main->place.EA, ".xpm",
		ft_strlen(main->place.EA)) != NULL)
		{
			main->texture[3].texture = mlx_xpm_file_to_image(main->vars.mlx,
			main->place.EA, &(main->texture[3].texture_width),
			&(main->texture[3].texture_height));
		}
		else if (ft_strnstr(main->place.EA, ".png",
		ft_strlen(main->place.EA)) != NULL)
		{
			main->texture[3].texture = mlx_png_file_to_image(main->vars.mlx,
			main->place.EA, &(main->texture[3].texture_width),
			&(main->texture[3].texture_height));
		}
	}
	else
	{
		main->place.error_c = 22;
		ft_error(main);
	}
}
