/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_fill_copy.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 16:59:57 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/23 17:16:49 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char		*map_copy_top(t_struct_m *main, int y, int len)
{
	char	*str;

	str = NULL;
	y = 0;
	len = (ft_strlen(main->cubecopy[y]) + 2);
	str = (char *)malloc((len + 1) * sizeof(char));
	empty_map_two(str, y, len);
	ft_putstr("start");
	ft_putstr(str);
	return (str);
}
