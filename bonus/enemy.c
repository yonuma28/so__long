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

static void	execute_enemy_move(t_map *map, t_coord old_pos, t_coord new_pos)
{
	if (map->map[new_pos.y][new_pos.x] == 'P')
		game_over(map);
	map->map[old_pos.y][old_pos.x] = '0';
	map->map[new_pos.y][new_pos.x] = 'N';
}

static bool	try_specific_move(t_map *map, t_coord enemy_pos, t_coord next_pos)
{
	if (map->map[next_pos.y][next_pos.x] == '0'
		|| map->map[next_pos.y][next_pos.x] == 'P')
	{
		execute_enemy_move(map, enemy_pos, next_pos);
		return (true);
	}
	return (false);
}

static bool	try_move_x_axis(t_map *map, t_coord enemy_pos, t_coord player_pos)
{
	t_coord	next_pos;

	next_pos.y = enemy_pos.y;
	if (enemy_pos.x < player_pos.x)
	{
		next_pos.x = enemy_pos.x + 1;
		if (try_specific_move(map, enemy_pos, next_pos))
			return (true);
	}
	else if (enemy_pos.x > player_pos.x)
	{
		next_pos.x = enemy_pos.x - 1;
		if (try_specific_move(map, enemy_pos, next_pos))
			return (true);
	}
	return (false);
}

static bool	try_move_y_axis(t_map *map, t_coord enemy_pos, t_coord player_pos)
{
	t_coord	next_pos;

	next_pos.x = enemy_pos.x;
	if (enemy_pos.y < player_pos.y)
	{
		next_pos.y = enemy_pos.y + 1;
		if (try_specific_move(map, enemy_pos, next_pos))
			return (true);
	}
	else if (enemy_pos.y > player_pos.y)
	{
		next_pos.y = enemy_pos.y - 1;
		if (try_specific_move(map, enemy_pos, next_pos))
			return (true);
	}
	return (false);
}

static bool	try_move_enemy_in_direction(t_map *map, t_coord enemy_pos,
		t_coord player_pos)
{
	if (try_move_x_axis(map, enemy_pos, player_pos))
		return (true);
	if (try_move_y_axis(map, enemy_pos, player_pos))
		return (true);
	return (false);
}

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
