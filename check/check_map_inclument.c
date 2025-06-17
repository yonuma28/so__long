/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_inclument.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:30:13 by marvin            #+#    #+#             */
/*   Updated: 2025/06/14 21:29:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	count_elements(t_map *map, int *e, int *p, int *c)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'E')
				(*e)++;
			if (map->map[y][x] == 'P')
				(*p)++;
			if (map->map[y][x] == 'C')
				(*c)++;
			x++;
		}
		y++;
	}
}

int	check_map_inclument(struct map *map_struct)
{
	int	is_e;
	int	is_p;
	int	is_c;

	is_e = 0;
	is_p = 0;
	is_c = 0;
	count_elements(map_struct, &is_e, &is_p, &is_c);
	if (is_e == 0 || is_p == 0 || is_c == 0)
	{
		map_struct->is_invalid = 1;
		return (-1);
	}
	map_struct->count_teas = is_c;
	return (0);
}
