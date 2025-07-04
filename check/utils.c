/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-26 14:45:57 by yonuma            #+#    #+#             */
/*   Updated: 2025-06-26 14:45:57 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			{
				map->player_x = *x;
				map->player_y = *y;
				return ;
			}
			(*x)++;
		}
		(*y)++;
	}
}
