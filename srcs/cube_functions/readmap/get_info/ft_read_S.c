/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_S.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:08:39 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/25 16:48:06 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int     ft_read_S(t_struct_m *main, char *map)
{
	int     i;
	int     r;

	i = 0;
	r = 0;
	if (main->Double.D_S > 0)
	{
		main->place.error = 44;//St eSugh information
		ft_error(main);
	}
	else
	{
		while (map[i] == ' ')
			i++;
		while (map[i] == 'S')
			i++;
		while (map[i] == ' ')
			i++;
		if (map[i] != ' ')
		{
			r = ft_strleng(map, i);
			main->place.S = ft_substr(map, i, r);
			i = i + r;
			r = 1;
			main->Double.D_S = 1;
		}
		if (map[i] != '\0')
		{
			main->place.error = 45;
			ft_error(main);
		}
	}
	return (0);
}
