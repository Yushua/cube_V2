/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_ea.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:08:39 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/26 12:01:36 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int     ft_read_ea(t_struct_m *main, char *map)
{
    int     i;
    int     r;

    i = 0;
    r = 0;
    if (main->doublle.d_ea > 0)
    {
        main->place.error = 42;//eat eeaugh information
        ft_error(main);
    }
    else
    {
        while (map[i] == ' ')
            i++;
        if (map[i] == 'E')
            i++;
        if (map[i] == 'A')
            i++;
        while (map[i] == ' ')
                i++;
        if (map[i] != ' ')//what if null?
        {
            r = ft_strleng(map, i);
            main->place.ea = ft_substr(map, i, r);
            i = i + r;
            r = 1;
            main->doublle.d_ea = 1;
        }
        if (map[i] != '\0')
        {
            main->place.error = 43;
            ft_error(main);    
        }
    }
    return (0);
}