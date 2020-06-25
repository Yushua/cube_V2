/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_F.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:08:39 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/25 16:14:28 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int     ft_read_F(t_struct_m *main, char *map)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	if (main->Double.D_F > 0)
	{
		main->place.error = 29;
		ft_error(main);
	}
	else
	{
		while (map[i] == ' ')
			i++;
		if (map[i] == 'F')
			i++;
		while (map[i] == ' ')
			i++;
		while (map[i])
		{
			if(map[i] >= '0' && map[i] <= '9')
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
						main->place.Fcol1 = ft_atoi_cube(map, main, i);
						i = main->place.i;
						main->place.i = 0;
						i++;
					}
					else if (r == 1)
					{
						main->place.Fcol2 = ft_atoi_cube(map, main, i);
						i = main->place.i;
						main->place.i = 0;
						i++;
					}
					else if (r == 2)
					{
						main->place.Fcol3 = ft_atoi_cube(map, main, i);
						i = main->place.i;
						main->place.i = 0;
						main->Double.D_F = 1;
					}
					if (map[i] != '\0' && r == 2)
					{
						printf("2\n");
						main->place.error = 30;//not enough information r too much
						ft_error(main);
						return (0);
					}
				}
			}
			r++;
		}
	}
	if (main->Double.D_F != 1)
	{
		main->place.error = 32;//not enough information
		ft_error(main);
		return (0);  
	}
	printf("F = [%d][%d][%d]\n", main->place.Fcol1, main->place.Fcol2, main->place.Fcol3);
	return (0);
}