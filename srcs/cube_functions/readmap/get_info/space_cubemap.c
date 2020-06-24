/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   space_cubemap.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 11:49:54 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/24 16:55:21 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

static void			**ft_substr_save(char const *s, t_struct_m *main, int y)
{
	char	**substring;
	size_t	i;
	size_t	length;
	unsigned int start;
	size_t len;

	len = main->place.mapx;
	if (!s)
		return (0);
	main->place.cubemap[y] = NULL;
	main->cubecopy[y] = NULL;
	main->place.cubemap[y] = (char *)malloc((len + 1) * sizeof(char));
	main->cubecopy[y] = (char *)malloc((len + 1) * sizeof(char));
	main->Ray.yy = y;
	if (!main->place.cubemap[y])
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		main->place.cubemap[y][i] = (char)s[i];
		main->cubecopy[y][i] = main->place.cubemap[y][i];
		i++;
	}
	main->place.cubemap[y][i] = '\0';
	main->cubecopy[y][i] = '\0';
}

void				space_cubemap(t_struct_m *main)
{
	main->place.cubemap = (char**)malloc(sizeof(char*) * (main->Ray.yy + 1));
	main->cubecopy = (char**)malloc(sizeof(char*) * (main->Ray.yy + 1));
	if (!main->place.cubemap || !main->cubecopy)
	{
		main->place.error = 13;
		ft_error(main);
	}
	// ft_substr_save(map, main, y);
}
