/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_C.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:08:39 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/16 19:34:57 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int     ft_read_C(t_struct_m *main, char *map)
{
    int     i;
    int     r;

    i = 0;
    r = 0;
    if (main->Double.D_C > 0)
    {
        main->place.error = 35;//not enough information
        ft_error(main);
    }
    else
    {
        while (map[i] == ' ')
            i++;
        while (map[i] == 'C')
            i++;
        while (map[i] == ' ')
            i++;
        while (map[i])
        {
            if(map[i] >= '0' && map[i] <= '9')
            {
                i = ft_isalnummer(i, map);
                if (i < 0)
                {
                    main->place.error = 31;//not enough information
                    ft_error(main);
                }
                else
                {
                    if (r == 0)
                    {
                        main->place.Ccol1 = ft_atoi_cube(map, main, i);
                        i = main->place.i;
                        main->place.i = 0;
                    }
                    else if (r == 1)
                    {
                        main->place.Ccol2 = ft_atoi_cube(map, main, i);
                        i = main->place.i;
                        main->place.i = 0;
                    }
                    else if (r == 2)
                    {
                        main->place.Ccol3 = ft_atoi_cube(map, main, i);
                        i = main->place.i;
                        main->place.i = 0;
                        main->Double.D_C = 1;
                    }
                    else
                    {
                        main->place.error = 34;//not enough information
                        ft_error(main);
                        return (0);
                    }
                    i++;//comma
                }
            }
            r++;
        }
    }
    if (main->Double.D_C != 1)
	{
		main->place.error = 33;//not enough information
		ft_error(main);
		return (0);  
	}
    printf(" c = [%d][%d][%d]\n", main->place.Ccol1, main->place.Ccol2, main->place.Ccol3);
    return (0);
}