/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:49:04 by yonuma            #+#    #+#             */
/*   Updated: 2025/06/14 13:05:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	process_single_enemy_movement(t_map *map)
{
	t_coord	player_pos;
	t_coord	enemy_search_pos;

	search_player(map, &player_pos.x, &player_pos.y);
	enemy_search_pos.y = 0;
	while (enemy_search_pos.y < map->height)
	{
		enemy_search_pos.x = 0;
		while (enemy_search_pos.x < map->width)
		{
			if (map->map[enemy_search_pos.y][enemy_search_pos.x] == 'N')
			{
				if (try_move_enemy_in_direction(map, enemy_search_pos,
						player_pos))
					return ;
			}
			enemy_search_pos.x++;
		}
		enemy_search_pos.y++;
	}
}

int	enemy(t_map *map)
{
	static int	count = 0;

	count++;
	if (map->goal1 && count == 1)
	{
		process_single_enemy_movement(map);
		draw_map(map);
	}
	if (count == 100)
		count = 0;
	return (0);
}
