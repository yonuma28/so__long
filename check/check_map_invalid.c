/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_invalid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:01:56 by yonuma            #+#    #+#             */
/*   Updated: 2025/06/14 10:25:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

void	search_player(t_map *map, int *x, int *y)
{
	*y = 0;
	while (*y < map->height)
	{
		*x = 0;
		while (*x < map->width)
		{
			if (map->map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

static char	**create_map_copy(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->map[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map_copy, int height, int width, int y, int x)
{
	if (y < 0 || y >= height || x < 0 || x >= width || map_copy[y][x] == '1'
		|| map_copy[y][x] == 'F')
		return ;
	map_copy[y][x] = 'F';
	flood_fill(map_copy, height, width, y + 1, x);
	flood_fill(map_copy, height, width, y - 1, x);
	flood_fill(map_copy, height, width, y, x + 1);
	flood_fill(map_copy, height, width, y, x - 1);
}

static void	free_map_copy(char **map_copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

int	check_map_invalid(t_map *map)
{
	char	**map_copy;
	int		y;
	int		x;

	map_copy = create_map_copy(map);
	if (!map_copy)
		return (-1);
	search_player(map, &x, &y);
	flood_fill(map_copy, map->height, map->width, y, x);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if ((map->map[y][x] == 'C' || map->map[y][x] == 'E')
				&& map_copy[y][x] != 'F')
			{
				map->is_invalid = 1;
				free_map_copy(map_copy, map->height);
				return (-1);
			}
			x++;
		}
		y++;
	}
	free_map_copy(map_copy, map->height);
	return (0);
}
