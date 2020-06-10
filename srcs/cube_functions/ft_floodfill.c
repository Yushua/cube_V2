/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_floodfill.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 14:30:07 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/10 15:36:12 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// static void      	fill_with_x(int x, int y, t_struct_m *main)
// {
// 	if (y < 0 || x < 0)//check if the cordinates don't go out of the map
// 		return ;
// 	else if (main->cubecopy[y][x] != '1' && main->cubecopy[y][x] != ' ' && main->cubecopy[y][x] != 'X')
// 	{
// 		main->cubecopy[y][x] = 'X';
// 		main->count == 1;
// 	}
// }

// static	int			check_with_x(int x, int y, t_struct_m *main)
// {
// 	x--;
// 	fill_with_x(x, y, main);
// 	y--;
// 	fill_with_x(x, y, main);
// 	x++;
// 	fill_with_x(x, y, main);
// 	x++;
// 	fill_with_x(x, y, main);
// 	y++;
// 	fill_with_x(x, y, main);
// 	y++;
// 	fill_with_x(x, y, main);
// 	x--;
// 	fill_with_x(x, y, main);
// 	x--;
// 	fill_with_x(x, y, main);
// }

// int					flood_fill(int x, int y, t_struct_m *main)
// {
// 	x = 0;
// 	y = 0;
// 	while (x != (ft_strlen(main->cubecopy[y]) && y != main->Ray.yy))
// 	{
// 		while (y < main->Ray.yy)
// 		{
// 			while(main->cubecopy[y][x])
// 			{
// 				if (main->cubecopy[y][x] == 'X')// checks for somehting that isn't
// 				{
// 					check_with_x(x, y, main);
// 					if (main->count == 1)
// 					{
// 						x = 0;
// 						y = 0;
// 						flood_fill(x, y, main);
// 					}
// 				}
// 				x++;
// 			}
// 			y++;
// 			x = 0;
// 		}
// 	}
// }