/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:08:39 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/26 14:46:09 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int			ft_read_c(t_struct_m *main, char *map)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	if (main->doublle.d_c > 0)
	{
		main->place.error = 35;
		ft_error(main);
	}
	else
	{
		while (map[i] == ' ')
			i++;
		if (map[i] != 'C')
		{
			main->place.error = 10;
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
				if (i < 0)
				{
					main->place.error = 31;
					ft_error(main);
				}
				else
				{
					if (r == 0)
					{
						main->place.ccol1 = ft_atoi_cube(map, main, i);
						i = main->place.i;
						main->place.i = 0;
						i++;
					}
					else if (r == 1)
					{
						main->place.ccol2 = ft_atoi_cube(map, main, i);
						i = main->place.i;
						main->place.i = 0;
						i++;
					}
					else if (r == 2)
					{
						main->place.ccol3 = ft_atoi_cube(map, main, i);
						i = main->place.i;
						main->place.i = 0;
						main->doublle.d_c = 1;
					}
					if (map[i] != '\0' && r == 2)
					{
						main->place.error = 34;
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
	if (main->doublle.d_c != 1)
	{
		main->place.error = 33;
		ft_error(main);
		return (0);
	}
	return (0);
}
