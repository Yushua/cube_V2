/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_F.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:08:39 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/16 15:49:55 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int     t_read_F(t_struct_m *main, char *map)
{
    int     i;
    int     r;

    i = 0;
    r = 0;
    if (main->Double.D_F > 0)
    {
        main->place.error = 29;//not enough information
        ft_error(main);
    }
    else
    {

    }
    return (0);
}