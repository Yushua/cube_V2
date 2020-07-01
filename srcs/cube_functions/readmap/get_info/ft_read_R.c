/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_r.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:08:39 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/01 11:03:38 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

static int			error_r(t_struct_m *main, char *map, int i, int y)
{
	if (y == 1)
	{
		if (map[i] != 'R')
		{
			main->place.error = 3;
			ft_error(main);
			return (2);
		}
	}
	if (y == 2)
	{
		main->place.error = 3;
		ft_error(main);
		return (2);
	}
	return (0);
}

static	int			ft_read_r_n(t_struct_m *main, char *map, int i)
{
	i = ft_isalnummer(i, map);
	if (i < 0)
	{
		main->place.error = 27;
		ft_error(main);
		return (0);
	}
}

static	int			ft_read_r_readd(t_struct_m *main, char *map, int i, int r)
{
	if (r == 0)
	{
		main->place.s_height = ft_atoi_cube(map, main, i);
		i = main->place.i;
		main->place.i = 0;
	}
	else if (r == 1)
	{
		main->place.s_width = ft_atoi_cube(map, main, i);
		i = main->place.i;
		main->place.i = 0;
		main->doublle.d_r = 1;
	}
	if (map[i] != '\0' && r == 1)
	{
		main->place.error = 28;
		ft_error(main);
		return (2);
	}
}

static int			ft_read_r_read(t_struct_m *main, char *map, int i, int r)
{
	while (map[i] == ' ')
		i++;
	if (error_r(main, map, i, 1) == 2)
		return (2);
	else
		i++;
	while (map[i] == ' ')
		i++;
	while (map[i])
	{
		while (map[i] == ' ')
			i++;
		if (map[i] >= '0' && map[i] <= '9')
		{
			i = ft_read_r_n(main, map, i);
			if (i == 0)
				return (2);
			else if (ft_read_r_readd(main, map, i, r) == 2)
				return (2);
			r++;
		}
		else
			return (error_r(main, map, i, 2));
	}
}

int					ft_read_r(t_struct_m *main, char *map)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	if (main->doublle.d_r > 0)
	{
		main->place.error = 26;
		ft_error(main);
	}
	else
	{
		if (ft_read_r_read(main, map, i, r) == 2)
			return (0);
	}
	if (main->doublle.d_r != 1)
	{
		main->place.error = 3;
		ft_error(main);
		return (0);
	}
	return (0);
}
