/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_r.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:08:39 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/26 12:03:41 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int			ft_read_r(t_struct_m *main, char *map)
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
		while (map[i] == ' ')
			i++;
		if (map[i] != 'R')
		{
			main->place.error = 3;
			ft_error(main);
		}
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
				i = ft_isalnummer(i, map);
				if (i < 0)
				{
					main->place.error = 27;
					ft_error(main);
				}
				else
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
						return (0);
					}
				}
				r++;
			}
			else
			{
				main->place.error = 3;
				ft_error(main);
				return (0);
			}
		}
	}
	if (main->doublle.d_r != 1)
	{
		main->place.error = 3;
		ft_error(main);
		return (0);
	}
	return (0);
}
