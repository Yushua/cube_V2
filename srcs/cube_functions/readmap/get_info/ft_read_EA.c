/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_EA.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:08:39 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/16 18:14:18 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void     ft_read_EA(t_struct_m *main, char *map)
{
    int     i;
    int     r;

    i = 0;
    r = 0;
    if (main->Double.D_EA > 0)
    {
        main->place.error = 42;//EAt eEAugh information
        ft_error(main);
    }
    else
    {
        while (map[i] == ' ')
            i++;
        while (map[i] == 'EA')
            i++;
        while (map[i] == ' ')
                i++;
        if (map[i] != ' ')//what if null?
        {
            r = ft_strleng(map, i);
            main->place.EA = ft_substr(map, i, r);
            i = i + r;
            r = 1;
            main->Double.D_EA = 1;
        }
        if (map[i] != '\0')
        {
            main->place.error = 43;
            ft_error(main);    
        }
    }
    return (0);
}