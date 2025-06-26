/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-26 15:04:26 by yonuma            #+#    #+#             */
/*   Updated: 2025-06-26 15:04:26 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	execute_enemy_move(t_map *map, t_coord old_pos, t_coord new_pos)
{
	if (map->map[new_pos.y][new_pos.x] == 'P')
		game_over(map);
	map->map[old_pos.y][old_pos.x] = '0';
	map->map[new_pos.y][new_pos.x] = 'N';
}

bool	try_specific_move(t_map *map, t_coord enemy_pos, t_coord next_pos)
{
	if (map->map[next_pos.y][next_pos.x] == '0'
		|| map->map[next_pos.y][next_pos.x] == 'P')
	{
		execute_enemy_move(map, enemy_pos, next_pos);
		return (true);
	}
	return (false);
}

bool	try_move_x_axis(t_map *map, t_coord enemy_pos, t_coord player_pos)
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

bool	try_move_y_axis(t_map *map, t_coord enemy_pos, t_coord player_pos)
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

bool	try_move_enemy_in_direction(t_map *map, t_coord enemy_pos,
		t_coord player_pos)
{
	if (try_move_x_axis(map, enemy_pos, player_pos))
		return (true);
	if (try_move_y_axis(map, enemy_pos, player_pos))
		return (true);
	return (false);
}
