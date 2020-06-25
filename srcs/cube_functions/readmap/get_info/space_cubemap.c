/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   space_cubemap.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 11:49:54 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/25 13:31:54 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

static void			ft_fill_empty_string(t_struct_m *main, int y)
{
	int		x;

	x = 0;
	while (x <= main->Ray.xx)
	{
		main->place.cubemap[y][x] = ' ';
		main->cubecopy[y][x] = ' ';
		x++;
	}
	main->place.cubemap[y][main->Ray.xx] = '\0';
	main->cubecopy[y][main->Ray.xx] = '\0';
}

static int			ft_substr_save(char *map, t_struct_m *main, int y)
{
	size_t	i;

	if (!map)
		return (1);
	main->place.cubemap[y] = NULL;
	main->cubecopy[y] = NULL;
	main->place.cubemap[y] = (char *)malloc((main->Ray.xx + 1) * sizeof(char));
	main->cubecopy[y] = (char *)malloc((main->Ray.xx + 1) * sizeof(char));
	if (!main->place.cubemap[y] || !main->cubecopy[y])
		return (1);
	ft_fill_empty_string(main, y);
	i = 0;
	while (map[i])
	{
		main->place.cubemap[y][i] = (char)map[i];
		main->cubecopy[y][i] = (char)map[i];
		i++;
	}
	return (0);
}

static int			ft_print_map(t_struct_m *main)
{
	int		count;
	int		fd;
	char	*map;
	int		y;
	int		yy;
	int		yyy;

	count = 1;
	y = main->Ray.yyy;
	yy = main->Ray.yy;
	yyy = 0;
	fd = open(main->map, O_RDONLY);
	printf("y=[%i]x=[%i]\n", main->Ray.yy, main->Ray.xx);
	if (fd < 0)
	{
		main->place.error = 24;
		ft_error(main);
	}
	while (count > 0)
	{
		count = get_next_line(fd, &map);
		if (y != 0)
			y--;
		else if (yy != 0)
		{
			yy--;
			if (ft_substr_save(map, main, yyy) == 1)
				return (1);
			yyy++;
		}
		free(map);
	}
	return (0);
}

void				space_cubemap(t_struct_m *main)
{
	main->place.cubemap = (char**)malloc(sizeof(char*) * (main->Ray.yy));
	main->cubecopy = (char**)malloc(sizeof(char*) * (main->Ray.yy));
	if (!main->place.cubemap || !main->cubecopy)
	{
		main->place.error = 13;
		ft_error(main);
	}
	if (ft_print_map(main) == 1)
	{
		main->place.error = 13;
		ft_error(main);
	}
}
