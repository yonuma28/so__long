/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 03:24:38 by yonuma            #+#    #+#             */
/*   Updated: 2025/06/14 20:58:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	find_player(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	check_and_exit_on_goal(t_map *map)
{
	if (map->count_tea == map->count_teas)
	{
		map->count++;
		printf("count: %d\n", map->count);
		printf("GOAL!!\n");
		cleanup_and_exit(map);
	}
	map->goal2 = true;
}

static void	update_player_position(t_map *map, int next_x, int next_y)
{
	char	target_tile;

	target_tile = map->map[next_y][next_x];
	if (target_tile == 'C')
		map->count_tea++;
	map->map[map->player_y][map->player_x] = '0';
	map->map[next_y][next_x] = 'P';
	map->player_x = next_x;
	map->player_y = next_y;
	map->count++;
}

static void	process_move(t_map *map, int next_x, int next_y)
{
	char	target_tile;

	target_tile = map->map[next_y][next_x];
	if (target_tile == '0' || target_tile == 'C')
		update_player_position(map, next_x, next_y);
	else if (target_tile == 'E')
		check_and_exit_on_goal(map);
}

void	move_player(t_map *map, int dx, int dy)
{
	int	next_x;
	int	next_y;

	find_player(map);
	next_x = map->player_x + dx;
	next_y = map->player_y + dy;
	if (next_x < 0 || next_x >= map->width || \
		next_y < 0 || next_y >= map->height)
		return ;
	if (map->map[next_y][next_x] == '1')
		return ;
	process_move(map, next_x, next_y);
}
