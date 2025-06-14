/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-30 03:24:38 by yonuma            #+#    #+#             */
/*   Updated: 2025-05-30 03:24:38 by yonuma           ###   ########.fr       */
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

void	move_a(t_map *map)
{
	int		x;
	int		y;
	char	target_tile;

	find_player(map);
	x = map->player_x;
	y = map->player_y;
	if (x > 0)
	{
		target_tile = map->map[y][x - 1];
		if (target_tile == '0' || target_tile == 'C')
		{
			if (target_tile == 'C')
				map->count_tea++;
			map->map[y][x - 1] = 'P';
			map->map[y][x] = '0';
			map->count++;
			map->player_x--;
		}
		else if (target_tile == 'E')
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
	}
}

void	move_d(t_map *map)
{
	int		x;
	int		y;
	char	target_tile;

	find_player(map);
	x = map->player_x;
	y = map->player_y;
	if (x < map->width - 1)
	{
		target_tile = map->map[y][x + 1];
		if (target_tile == '0' || target_tile == 'C')
		{
			if (target_tile == 'C')
				map->count_tea++;
			map->map[y][x + 1] = 'P';
			map->map[y][x] = '0';
			map->count++;
			map->player_x++;
		}
		else if (target_tile == 'E')
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
	}
}

void	move_w(t_map *map)
{
	int		x;
	int		y;
	char	target_tile;

	find_player(map);
	x = map->player_x;
	y = map->player_y;
	if (y > 0)
	{
		target_tile = map->map[y - 1][x];
		if (target_tile == '0' || target_tile == 'C')
		{
			if (target_tile == 'C')
				map->count_tea++;
			map->map[y - 1][x] = 'P';
			map->map[y][x] = '0';
			map->count++;
			map->player_y--;
		}
		else if (target_tile == 'E')
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
	}
}

void	move_s(t_map *map)
{
	find_player(map);
	int x = map->player_x;
	int y = map->player_y;
	char target_tile;

	if (y < map->height - 1)
	{
		target_tile = map->map[y + 1][x];
		if (target_tile == '0' || target_tile == 'C')
		{
			if (target_tile == 'C')
				map->count_tea++;
			map->map[y + 1][x] = 'P';
			map->map[y][x] = '0';
			map->count++;
			map->player_y++;
		}
		else if (target_tile == 'E')
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
	}
}