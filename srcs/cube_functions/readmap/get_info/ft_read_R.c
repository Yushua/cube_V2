/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_R.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:08:39 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/16 19:31:00 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int     ft_read_R(t_struct_m *main, char *map)
{
    int     i;
    int     r;

    i = 0;
    r = 0;
    if (main->Double.D_R > 0)
    {
        main->place.error = 26;//not enough information
        ft_error(main);
    }
    else
    {
        while (map[i] == ' ')
            i++;
        while (map[i] == 'R')
            i++;
        while(map[i])
        {
            while (map[i] == ' ')
                    i++;
            if(map[i] >= '1' && map[i] <= '9')
            {
                i = ft_isalnummer(i, map);
                if (i < 0)
                {
                    main->place.error = 27;//not enough information
                    ft_error(main);
                }
                else
                {
                    if (r == 0)
                    {
                        main->place.s_height = ft_atoi_cube(map, main, i);
                        i = main->place.i;
                        main->place.i = 0;
                    }
                    else if (r == 1)
                    {
                        main->place.s_width = ft_atoi_cube(map, main, i);
                        i = main->place.i;
                        main->place.i = 0;
                        main->Double.D_R = 1;
                    }
                    else
                    {
                        main->place.error = 28;//not enough information
                        ft_error(main);
                        return (0);
                    }
                    i++;
                }
                r++;
            }
        }
    }
    if (main->Double.D_R != 1)
	{
		main->place.error = 3;//not enough information
		ft_error(main);
		return (0);  
	}
    printf("R == [%d][%d]\n", main->place.s_height, main->place.s_width);
    return (0);
}