/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 11:53:18 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/11 15:10:30 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		if_empty(int x, int y, t_struct_m *main)
{
	if (y < 0 || x < 0)//check if the cordinates don't go out of the map
		return (0);
	else if (main->cubecopy[y][x] == ' ')
	{
		main->place.error_c = 18;
		ft_error(main);
		return (0);
	}
	return (1);
}

int     ft_check_empty(int x, int y, t_struct_m *main)
{
    if (if_empty(x - 1, y, main) == 0)
        return (0);
    if (if_empty(x + 1, y, main) == 0)
        return (0);
    if (if_empty(x, y + 1, main) == 0)
        return (0);
    if (if_empty(x, y - 1, main) == 0)
        return (0);
    if (if_empty(x + 1, y + 1, main) == 0)
        return (0);
    if (if_empty(x - 1, y - 1, main) == 0)
        return (0);
    if (if_empty(x - 1, y + 1, main) == 0)
        return (0);
    if (if_empty(x + 1, y - 1, main) == 0)
        return (0);
    return (0);
}

void		flood_fill(int x, int y, t_struct_m *main)
{
	if (main->cubecopy[y][x] == '1')
		return ;
	if (main->cubecopy[y][x] != '0' && main->cubecopy[y][x] != '2' )
		return ;
    if(x <= 0 || y <= 0 || y == (main->Ray.yy) || x == (ft_strlen(main->cubecopy[y]) - 1))
    {
        main->place.error = 15;
        return ;
    }
	main->cubecopy[y][x] = 'X';
    flood_fill(x, y + 1, main);
	flood_fill(x, y - 1, main);
	flood_fill(x + 1, y, main);
	flood_fill(x - 1, y, main);
	flood_fill(x + 1, y + 1, main);
	flood_fill(x - 1, y - 1, main);
	flood_fill(x + 1, y - 1, main);
	flood_fill(x - 1, y + 1, main);
}

int		check_fill(t_struct_m *main)
{
	int	x = (int)(main->Ray.posX);
	int	y = (int)(main->Ray.posY);
	main->cubecopy[y][x] = '0';
	flood_fill(x , y, main);
	y = 0;
	x = 0;
	while (main->cubecopy[0][x])
	{
		if (((main->cubecopy[0][x]) != '1') && (main->cubecopy[0][x] != ' '))
		{
			main->place.error_c = 15;//top
			ft_error(main);
		}
        x++;
	}
	x = 0;
	while (main->cubecopy[main->Ray.yy][x])
	{
		if (main->cubecopy[main->Ray.yy][x] != '1' && main->cubecopy[main->Ray.yy][x] != ' ')
		{
			main->place.error_c = 15;//bottom
			ft_error(main);
		}
		x++;
	}
	while (y < main->Ray.yy)
	{
        if (main->cubecopy[y][0] != '1' && main->cubecopy[y][0] != ' ')//first in the line
		{
            main->place.error_c = 16;//left
			ft_error(main);
		}
        x = (ft_strlen(main->cubecopy[y]) - 1);
        if (main->cubecopy[y][x] != '1' && main->cubecopy[y][x] != ' ')//last in the line
		{
            main->place.error_c = 17;//right
			ft_error(main);
		}
        x = 0;
		while (main->cubecopy[y][x])
		{
			if (main->cubecopy[y][x] == '0')//place with the where yu look
			{
                ft_check_empty(x, y, main);
			}
			x++;
		}
		y++;
	}
	return (1);
}