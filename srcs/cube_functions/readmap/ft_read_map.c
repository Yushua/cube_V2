/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 14:09:41 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/24 16:23:09 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int				ft_check_for_map(char *map, t_struct_m *main)
{
	int		x;

	x = 0;
	while (map[x] == ' ')
		x++;
	if (map[x] == '0' || map[x] == '1' || map[x] == '2')
		return (1);
	return (0);
}

static void			check_map_symbol(t_struct_m *main, char *map)
{
	if (ft_strnstr_map(map, "R ", strlen(map)) == 1)
		ft_read_R(main, map);
	else if (ft_strnstr_map(map, "SO ", strlen(map)) == 1)
		ft_read_SO(main, map);
	else if (ft_strnstr_map(map, "S ", strlen(map)) == 1)
		ft_read_S(main, map);
	else if (ft_strnstr_map(map, "NO ", strlen(map)) == 1)
		ft_read_NO(main, map);
	else if (ft_strnstr_map(map, "EA ", strlen(map)) == 1)
		ft_read_EA(main, map);
	else if (ft_strnstr_map(map, "WE ", strlen(map)) == 1)
		ft_read_WE(main, map);
	else if (ft_strnstr_map(map, "F ", strlen(map)) == 1)
		ft_read_F(main, map);
	else if (ft_strnstr_map(map, "C ", strlen(map)) == 1)
		ft_read_C(main, map);
}

int				ft_get_info(t_struct_m *main, char *map)
{
	int		x;

	x = 0;
	if (!(*map))
		return (0);
	while (map[x] == ' ')
		x++;
	if (map[x])
		check_map_symbol(main, map);//don't forget check if there is something else
	else
	{
		main->place.error = 2;
		ft_error(main);
	}
	return (0);
}

static int		ft_check_empty_line_check(t_struct_m *main, char *map)
{
	int		i;

	i = 0;
	while (map[i] == ' ')
		i++;
	if (map[i] != '\0')
		return (0);
	else
		return (1);
}

int				ft_read_map_where(t_struct_m *main, char *map)
{
	if (ft_get_info(main, map) == 2)
	{
		return (2);
	}
	return (0);
}

int				ft_read_map(t_struct_m *main)
{
	int		count;
	int		fd;
	char	*map;
	int		i;
	int		ii;

	i = 0;
	ii = 0;
	count = 1;
	main->Ray.yyy = 0;
	fd = open(main->map, O_RDONLY);
	if (fd < 0)
	{
		main->place.error = 24;
		ft_error(main);
		return (2);
	}
	while (count > 0)
	{
		count = get_next_line(fd, &map);
		if (count < 0)
		{
			main->place.error = 24;
			ft_error(main);
			free(map);
			return (2);
		}
		if (ft_check_for_map(map, main) == 1)
		{
			ii = 1;
			count = count;
		}
		if (ii != 1)
		{
			main->Ray.yyy++;
			if (ft_check_empty_line_check(main, map) == 1)
				count = count;
			else if (ft_read_map_where(main, map) == 2)
				i = 2;
		}
		free(map);
	}
	if (main->Double.D_R != 1 && main->Double.D_NO != 1 &&
			main->Double.D_SO != 1 && main->Double.D_EA != 1 &&
			main->Double.D_S != 1 && main->Double.D_WE != 1 &&
			main->Double.D_F != 1 && main->Double.D_C != 1)
		i = 2;
	if (i == 2)
		return (2);
	return (0);
}
