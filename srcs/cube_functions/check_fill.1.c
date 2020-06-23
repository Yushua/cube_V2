/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_fill.1.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 11:13:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/23 19:53:33 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char			copy_map_two(char **copy, char **org, int y)
{
	int		i;
	int		x;
	int		yy;

	i = 0;
	x = 1;
	yy = y--;
	while (org[y][i])
	{
		copy[yy][x] = org[y][i];
		x++;
		i++;
	}
	copy[y][x] = '\0';
	return (0);
}

int				map_copy_two(t_struct_m *main)
{
	int		y;
	int		yy;
	int		len;

	yy = (main->Ray.yy + 2);
	if (!main->cubecopy)
		return (1);
	main->cubecopytwo = (char**)malloc(sizeof(char*) * (yy + 1));
	if (!main->cubecopytwo)
		return (1);
	y = 0;
	len = (ft_strlen(main->cubecopy[y]) + 2);
	main->cubecopytwo[y] = (char *)malloc((len + 1) * sizeof(char));
	empty_map_two(main, y, len);
	y = 1;
	while (y < (yy - 1))
	{
		len = ft_strlen(main->cubecopy[y - 1]) + 2;
		main->cubecopytwo[y] = (char *)malloc((len + 1) * sizeof(char));
		if (!main->cubecopytwo[y])
			return (1);
		empty_map_two(main, y, len);
		copy_map_two(main->cubecopytwo, main->cubecopy, y);
		y++;
	}
	main->cubecopytwo[y] = (char *)malloc((len + 1) * sizeof(char));
	if (!main->cubecopytwo[y])
		return (1);
	empty_map_two(main, y, len);
	return (0);
}

int				check_fill(t_struct_m *main)
{
	int	x;
	int	y;

	ft_empty_space(main);
	x = (int)(main->Ray.posX);
	y = (int)(main->Ray.posY);
	main->cubecopy[y][x] = '0';
	flood_fill(x, y, main);
	if (map_copy_two(main) == 1)
	{
		main->place.error = 46;
		ft_error(main);
		return (1);
	}
	y = 0;
	x = 0;
	ft_putstr("start");
	while (y < (main->Ray.yy))
	{
		main->cubecopytwo[y] = ft_strjoin(main->cubecopytwo[y], " ");
		y++;
	}
	y = 0;
	while (y < main->Ray.yy)
	{
		while (main->cubecopytwo[y][x])
		{
			if (main->cubecopytwo[y][x] == 'X')
				ft_check_empty(x, y, main);
			x++;
		}
		y++;
	}
	return (0);
}
