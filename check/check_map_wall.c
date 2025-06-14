/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:01:22 by yonuma            #+#    #+#             */
/*   Updated: 2025/06/14 10:54:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map_wall(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width)
	{
		if (map->map[0][x] != '1' || map->map[map->height - 1][x] != '1')
		{
			map->is_invalid = 1;
			return (-1);
		}
		x++;
	}
	y = 1;
	while (y < map->height - 1)
	{
		if (map->map[y][0] != '1' || map->map[y][map->width - 1] != '1')
		{
			map->is_invalid = 1;
			return (-1);
		}
		y++;
	}
	return (0);
}
