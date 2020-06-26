/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_no.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:08:39 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/26 12:03:19 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int     ft_read_no(t_struct_m *main, char *map)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	if (main->doublle.d_no > 0)
	{
		main->place.error = 40;
		ft_error(main);
	}
	else
	{
		while (map[i] == ' ')
			i++;
		if (map[i] == 'N')
			i++;
		if (map[i] == 'O')
			i++;
		while (map[i] == ' ')
			i++;
		if (map[i] != ' ')
		{
			r = ft_strleng(map, i);
			main->place.no = ft_substr(map, i, r);
			i = i + r;
			r = 1;
			main->doublle.d_no = 1;
		}
		if (map[i] != '\0')
		{
			main->place.error = 41;
			ft_error(main);
		}
	}
	return (0);
}
