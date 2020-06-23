/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 14:22:42 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/23 19:08:21 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void		error_check_one(t_struct_m *main)
{
	if (main->place.error == 2)
		ft_putstr("unknown input in map, or clutter fix your map\n");
	else if (main->place.error == 3)
		ft_putstr("unacceptable command in line R, fix your map\n");
	else if (main->place.error == 4)
		ft_putstr("unacceptable command in line NO, fix your map\n");
	else if (main->place.error == 5)
		ft_putstr("unacceptable command in line EA, fix your map\n");
	else if (main->place.error == 6)
		ft_putstr("unacceptable command in line S, fix your map\n");
	else if (main->place.error == 7)
		ft_putstr("unacceptable command in line SO, fix your map\n");
	else if (main->place.error == 8)
		ft_putstr("unacceptable command in line WE, fix your map\n");
	else if (main->place.error == 9)
		ft_putstr("unacceptable command in line F, fix your map\n");
	else if (main->place.error == 10)
		ft_putstr("unacceptable command in line C, fix your map\n");
	else if (main->place.error == 11)
		ft_putstr("INCORRECT input of position input, fix your map\n");
	else if (main->place.error == 12)
		ft_putstr("double inputs after inputs or wrong input, fix your map\n");
	else if (main->place.error == 12)
		ft_putstr("wrong input in map, can't read map, fix your map\n");
}

static void		error_check_two(t_struct_m *main)
{
	if (main->place.error == 13)
		ft_putstr("problem in malloc, try again\n");
	else if (main->place.error == 14)
		ft_putstr("problem in functions, line is NULL\n");
	else if (main->place.error == 15)
		ft_putstr("map incorrect, not surroudned by 1, top or bottom wrong\n");
	else if (main->place.error == 16)
		ft_putstr("map incorrect, not surroudned by 1, left side wrong\n");
	else if (main->place.error == 17)
		ft_putstr("map incorrect, not surroudned by 1, right side wrong\n");
	else if (main->place.error == 18)
		ft_putstr("map incorrect\n");
	else if (main->place.error == 19)
		ft_putstr("link in map file incorrect at NO, fd is -1\n");
	else if (main->place.error == 20)
		ft_putstr("link in map file incorrect at SO, fd is -1\n");
	else if (main->place.error == 21)
		ft_putstr("link in map file incorrect at WE, fd is -1\n");
	else if (main->place.error == 22)
		ft_putstr("link in map file incorrect at EA, fd is -1");
	else if (main->place.error == 23)
		ft_putstr("link in map file incorrect at S, fd is -1");
	else if (main->place.error == 24)
		ft_putstr("error in fd, read map, fd < 0");
}

static void		error_check_three(t_struct_m *main)
{
	if (main->place.error == 25)
		ft_putstr("not all information was given, or map is in wrong location");
	else if (main->place.error == 26)
		ft_putstr("double R");
	else if (main->place.error == 27)
		ft_putstr("first set numbers in R is incorrect");
	else if (main->place.error == 28)
		ft_putstr("too many inputs in R, fix R");
	else if (main->place.error == 29)
		ft_putstr("double F");
	else if (main->place.error == 30)
		ft_putstr("too many inputs in F, fix F");
	else if (main->place.error == 31)
		ft_putstr("first set numbers in F is incorrect");
	else if (main->place.error == 32)
		ft_putstr("fnot enough inputs in R");
	else if (main->place.error == 33)
		ft_putstr("fnot enough inputs in C");
	else if (main->place.error == 34)
		ft_putstr("too many inputs in F, fix F");
	else if (main->place.error == 35)
		ft_putstr("double C");
	else if (main->place.error == 36)
		ft_putstr("double SO");
}

static void		error_check_four(t_struct_m *main)
{
	if (main->place.error == 37)
		ft_putstr("SO info after link, remove this info");
	else if (main->place.error == 38)
		ft_putstr("double WE");
	else if (main->place.error == 39)
		ft_putstr("WE info after link, remove this info");
	else if (main->place.error == 40)
		ft_putstr("double NO");
	else if (main->place.error == 41)
		ft_putstr("NO info after link, remove this info");
	else if (main->place.error == 42)
		ft_putstr("double EA");
	else if (main->place.error == 43)
		ft_putstr("EA info after link, remove this info");
	else if (main->place.error == 44)
		ft_putstr("double S");
	else if (main->place.error == 45)
		ft_putstr("S info after link, remove this info");
	else if (main->place.error == 46)
		ft_putstr("malloc error in check_fill");
	else if (main->place.error == 47)
		ft_putstr("empty line in map");
}

void			ft_error(t_struct_m *main)
{
	if (main->place.error_n < 0)
	{
		ft_putstr("Error\n");
		main->place.error_n = 0;
	}
	if (main->place.error == 1)
	{
		ft_putstr("you got double lines, fix your map\n");
		main->place.check_double = 0;
	}
	error_check_one(main);
	error_check_two(main);
	error_check_three(main);
	error_check_four(main);
	main->place.error = 0;
}
