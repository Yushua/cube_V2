/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   functions.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 11:35:00 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/18 14:53:06 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void		spritesnumb(t_struct_m *main)
{
	int	y = 0;
	int	x = 0;
	while (y <= main->Ray.yy)
	{
		while (main->place.cubemap[y][x])
		{
			if (main->place.cubemap[y][x] == '2')//place with the where yu look
			{
				main->numSprites++;
			}
			x++;
		}
		y++;
		x = 0;
	}
	main->sprites = ft_calloc(main->numSprites, sizeof(t_sprites));

	main->ZBuffer = ft_calloc(main->place.s_width, sizeof(double));
	main->spriteDistance = ft_calloc(main->numSprites, sizeof(double));
	main->spriteOrder = ft_calloc(main->numSprites, sizeof(int));
	y = 0;
	x = 0;

	int	numsprites = 0;

	while (y <= main->Ray.yy)
	{
		while (main->place.cubemap[y][x] != '\0')
		{
			if (main->place.cubemap[y][x] == '2')
			{
				main->sprites[numsprites].x = (double)x + 0.5;
				main->sprites[numsprites].y = (double)y + 0.5;
				numsprites++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void  		swap(t_struct_m *main , int j)
{
	int		temp_order;
	double	temp_dist;

	temp_dist = (main->spriteDistance)[j];
	temp_order = (main->spriteOrder)[j];
	(main->spriteDistance)[j] = (main->spriteDistance)[j + 1];
	(main->spriteDistance)[j + 1] = temp_dist;
	(main->spriteOrder)[j] = (main->spriteOrder)[j + 1];
	(main->spriteOrder)[j + 1] = temp_order;
}

void        bubble_sort(t_struct_m *main)
{
	int     swapped;
	int     i;
	int     j;
	swapped = 1;
	i = 0;
	j = 0;
	while (main->numSprites - i > 1 && swapped == 1)
	{
		swapped = 0;
		j = 0;
		while (j < main->numSprites - i - 1)
		{
			if ((main->spriteDistance)[j] < (main->spriteDistance)[j + 1])
			{
				swap(main, j);
				swapped = 1;
			}
			j++;
		}
		i++;
	}
}

int		ft_atoi_cube(char *str, t_struct_m *main, int i)
{
	int		res;
	int		sign;

	res = 0;
	sign = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	main->place.i = i;
	return (res);
}

int	ft_isalnummer(int i, char *str)	//check if everything is a number
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
}

int	ft_strlenght(char *s)
{
	int i;

	i = 0;
	while (s[i] != ' ')
		i += 1;
	return (i);
}

int			ft_strleng(char *str, int i)
{
	int		r;

	r = 0;
	while (str[i])
	{
		r++;
		i++;
	}
	return (r);
}

void ft_putstr(char *str)
{
	int i;

	i = ft_strlen(str);
	write(1, str, i);
	write(1, "\n", 1);
}

void		printmap(t_struct_m *main)
{
	int	y = 0;

	ft_putstr("-original-");
	while (y <= main->Ray.yy)
	{
		ft_putstr(main->place.cubemap[y]);
		y++;
	}
	ft_putstr("-copy-");
	y = 0;
	while (y <= main->Ray.yy)
	{
		ft_putstr(main->cubecopy[y]);
		y++;
	}
}

int		create_trgb(int r, int g, int b)
{
	return(r << 16 | g << 8 | b);
}
