/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   functions_pthree.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 18:50:30 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/25 18:52:56 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int			ft_isalnummer(int i, char *str)
{
	int y;

	y = i;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
				i++;
			return (y);
		}
		else
			return (-1);
	}
	return (0);
}

int			ft_strlenght(char *s)
{
	int i;

	i = 0;
	while (s[i] != ' ')
		i += 1;
	return (i);
}

int				ft_check_for_map(char *map, t_struct_m *main)
{
	int		x;

	x = 0;
	while (map[x] == ' ')
		x++;
	if (map[x] == '0' || map[x] == '1' || map[x] == '2')
		return (1);
	return (0);
}

int				ft_get_info(t_struct_m *main, char *map)
{
	int		x;

	x = 0;
	if (!(*map))
		return (0);
	while (map[x] == ' ')
		x++;
	if (map[x])
		check_map_symbol(main, map);
	else
	{
		main->place.error = 2;
		ft_error(main);
	}
	return (0);
}

int				ft_clutter(t_struct_m *main, char *map)
{
	int		i;

	i = 0;
	if (main->Double.D_R == 1 && main->Double.D_NO == 1 &&
	main->Double.D_SO == 1 && main->Double.D_EA == 1 &&
	main->Double.D_S == 1 && main->Double.D_WE == 1 &&
	main->Double.D_F == 1 && main->Double.D_C == 1)
	{
		while (map[i])
		{
			if (map[i] == '0' || map[i] == '1' || map[i] == '2' ||
			map[i] == ' ' || map[i] == 'N' || map[i] == 'S' ||
			map[i] == 'W' || map[i] == 'E')
				i++;
			else
			{
				main->place.error = 50;
				ft_error(main);
				return (2);
			}
		}
	}
	return (0);
}
