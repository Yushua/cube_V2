/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utills_five.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 18:50:30 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/01 13:45:52 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int			ft_error_map(t_struct_m *main, int fd)
{
	fd = open(main->map, O_RDONLY);
	if (fd < 0)
	{
		main->place.error = 24;
		ft_error(main);
		return (-2);
	}
	return (fd);
}
