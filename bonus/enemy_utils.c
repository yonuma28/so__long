/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-26 15:03:33 by yonuma            #+#    #+#             */
/*   Updated: 2025-06-26 15:03:33 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_over(t_map *map)
{
	mlx_string_put(map->mlx, map->win, 100, 100, 0x00FF0000, "Game Over");
	printf("Game Over\n");
	cleanup_and_exit(map);
}

void	set_enemy(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == '0')
			{
				map->map[y][x] = 'N';
				return ;
			}
			x++;
		}
		y++;
	}
}
