/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_f.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:08:39 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/26 12:01:52 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int     ft_read_f(t_struct_m *main, char *map)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	if (main->doublle.d_f > 0)
	{
		main->place.error = 29;
		ft_error(main);
	}
	else
	{
		while (map[i] == ' ')
			i++;
		if (map[i] != 'F')
		{
			main->place.error = 9;
			ft_error(main);
			return (0);
		}
		i++;
		while (map[i] == ' ')
			i++;
		while (map[i])
		{
			if (map[i] >= '0' && map[i] <= '9')
			{
				i = ft_isalnummer(i, map);
				if (i == -1)
				{
					main->place.error = 31;
					ft_error(main);
				}
				else
				{
					if (r == 0)
					{
						main->place.fcol1 = ft_atoi_cube(map, main, i);
						i = main->place.i;
						main->place.i = 0;
						i++;
					}
					else if (r == 1)
					{
						main->place.fcol2 = ft_atoi_cube(map, main, i);
						i = main->place.i;
						main->place.i = 0;
						i++;
					}
					else if (r == 2)
					{
						main->place.fcol3 = ft_atoi_cube(map, main, i);
						i = main->place.i;
						main->place.i = 0;
						main->doublle.d_f = 1;
					}
					if (map[i] != '\0' && r == 2)
					{
						main->place.error = 30;
						ft_error(main);
						return (0);
					}
				}
			}
			else
			{
				main->place.error = 9;
				ft_error(main);
				return (0);
			}
			r++;
		}
	}
	if (main->doublle.d_f != 1)
	{
		main->place.error = 32;
		ft_error(main);
		return (0);
	}
	return (0);
}
