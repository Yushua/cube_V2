/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   functions_pthree.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 18:50:30 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/23 18:50:48 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int			ft_isalnummer(int i, char *str)
{
	int y;

	y = i;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
				i++;
			return (y);
		}
		else
			return (-1);
	}
	return (0);
}

int			ft_strlenght(char *s)
{
	int i;

	i = 0;
	while (s[i] != ' ')
		i += 1;
	return (i);
}
