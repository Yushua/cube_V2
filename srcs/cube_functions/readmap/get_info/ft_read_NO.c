/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_NO.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:08:39 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/16 19:00:17 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int     ft_read_NO(t_struct_m *main, char *map)
{
    int     i;
    int     r;

    i = 0;
    r = 0;
    if (main->Double.D_NO > 0)
    {
        main->place.error = 40;//not enough information
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
        if (map[i] != ' ')//what if null?
        {
            r = ft_strleng(map, i);
            main->place.NO = ft_substr(map, i, r);
            i = i + r;
            r = 1;
            main->Double.D_NO = 1;
        }
        if (map[i] != '\0')
        {
            main->place.error = 41;
            ft_error(main);    
        }
    }
    printf("NO == [%s]\n", main->place.NO);
    return (0);
}