/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   functions_pfour.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 18:50:30 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 16:03:51 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int				ft_map_line_get_x(char *map)
{
	int		x;

	x = 0;
	while (map[x])
		x++;
	return (x);
}

int				ft_map_line(t_struct_m *main, char *map)
{
	int		x;

	x = 0;
	while (map[x])
	{
		if (map[x] == 'N' || map[x] == 'S' || map[x] == 'E' || map[x] == 'W')
			main->place.mapp++;
		if (main->place.mapp > 1)
			return (1);
		x++;
	}
	return (0);
}

void			ft_fill_empty_string(t_struct_m *main, int y)
{
	int		x;

	x = 0;
	while (x <= main->ray.xx)
	{
		main->place.cubemap[y][x] = ' ';
		main->cubecopy[y][x] = ' ';
		x++;
	}
	main->place.cubemap[y][main->ray.xx] = '\0';
	main->cubecopy[y][main->ray.xx] = '\0';
}

int				ft_strncmp_map(char *s1, char *s2, int n)
{
	int i;

	i = ft_strlen(s2);
	if (!n || i != n)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return (1);
}
