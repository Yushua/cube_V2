/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 14:09:41 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/16 15:27:19 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int     ft_check_for_map(char *map)
{
    int     x;

    x = 0;
    while (map[x] == ' ')
        x++;
    while (map[x])
    {
        if (map[x] == '0' || map[x] == '1' || map[x] == '2')
			return (1);
        x++;
    }
	return (0);
}

int	ft_strnstr_map(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!(*needle))
		return (0);
	i = 0;
	while (*(haystack + i) && i < len)
	{
		if (*needle == *(haystack + i))
		{
			j = 0;
			while ((*(haystack + i + j) == *(needle + j)) && (i + j < len))
			{
				j += 1;
				if (!(*(needle + j)))
					return (1);
			}
		}
		i += 1;
	}
	return (0);
}

int     ft_get_info(t_struct_m *main, char *map)
{
	int     x;

    x = 0;
	if (!(*map))
		return (0);
    while (map[x] == ' ')
        x++;
	if (map[x])
	{
		if (ft_strnstr(map, "R", strlen(map)) == 1)
			ft_read_R(main, map);
		else if (ft_strnstr(map, "F", strlen(map)) == 1)
			ft_read_F(main, map);
		else if (ft_strnstr(map, "C", strlen(map)) == 1)
			ft_read_C(main, map);
		else if (ft_strnstr(map, "S", strlen(map)) == 1)
			ft_read_S(main, map);
		else if (ft_strnstr(map, "NO", strlen(map)) == 1)
			ft_read_NO(main, map);
		else if (ft_strnstr(map, "SO", strlen(map)) == 1)
			ft_read_SO(main, map);
		else if (ft_strnstr(map, "EA", strlen(map)) == 1)
			ft_read_EA(main, map);
		else if (ft_strnstr(map, "WE", strlen(map)) == 1)
			ft_read_WE(main, map);
	}
	else
	{
		main->place.error = 2;
        ft_error(main);
	}
	return (0);
}

int    ft_read_map(t_struct_m *main, char *map)
{
    //read every string, make sure which you've gotten, if you get map before you've got everything, then error
    int     i;

    i = ft_check_for_map(map);
    if (i == 1)
    {
        if (main->Double.D_R == 1 && main->Double.D_NO == 1 && main->Double.D_SO == 1 &&
        main->Double.D_EA == 1 && main->Double.D_S == 1 && main->Double.D_WE == 1 &&
        main->Double.D_F == 1 && main->Double.D_C == 1)
            read_cube(main, map);
        else
        {
            main->place.error = 25;//not enough information
            ft_error(main);
			return (2)
        }
    }
    else if (ft_get_info(main, map) == 2)//read de info and stores it
			return (2);
	return (0);
}

int     ft_read_map(t_struct_m *main)
{
    int count;
    int fd;
    char *map;
    count = 1;
    fd = open("./srcs/maps/mape_5.cub", O_RDONLY);
    if (fd < 0)
    {
        main->place.error = 24;
        ft_error(main);
    }
    else
    {
        while (count > 0)
        {
            count = get_next_line(fd, &map);//wait until end of line because GNl returns 0 is
            if (count < 0)
            {
                main->place.error = 24;
                ft_error(main);
                free(map);
                return (2);
            }
            else
            {
                count = ft_read_map(main, map);
                free(map);
            }
			if (count == 2)//not enough information so stop program
				return (2);
        }
    }
}