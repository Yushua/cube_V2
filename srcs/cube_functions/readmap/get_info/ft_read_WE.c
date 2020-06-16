/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_WE.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:08:39 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/16 19:01:55 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int     ft_read_WE(t_struct_m *main, char *map)
{
    int     i;
    int     r;

    i = 0;
    r = 0;
    if (main->Double.D_WE > 0)
    {
        main->place.error = 38;//not enough information
        ft_error(main);
    }
    else
    {
        while (map[i] == ' ')
            i++;
        if (map[i] == 'W')
            i++;
        if (map[i] == 'E')
            i++;
        while (map[i] == ' ')
                i++;
        if (map[i] != ' ')//what if null?
        {
            r = ft_strleng(map, i);
            main->place.WE = ft_substr(map, i, r);
            i = i + r;
            r = 1;
            main->Double.D_WE = 1;
        }
        if (map[i] != '\0')
        {
            main->place.error = 39;
            ft_error(main);    
        }
    }
    printf("WE == [%s]\n", main->place.WE);
    return (0);    
}