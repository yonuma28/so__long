/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:16:30 by marvin            #+#    #+#             */
/*   Updated: 2025/06/14 21:16:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	collect_item_at_pos(t_map *map, t_coord pos)
{
	if (map->map[pos.y][pos.x] == 'C')
	{
		map->count_tea++;
		map->map[pos.y][pos.x] = '0';
	}
}

void	update_player_position_on_map(t_map *map, t_coord old_pos,
		t_coord new_pos)
{
	map->map[new_pos.y][new_pos.x] = 'P';
	map->map[old_pos.y][old_pos.x] = '0';
	map->player_x = new_pos.x;
	map->player_y = new_pos.y;
	map->count++;
}

void	handle_horizontal_move(t_map *map, t_coord p_pos, int dx)
{
	t_coord	next_pos;

	next_pos.y = p_pos.y;
	next_pos.x = p_pos.x + dx;
	if (next_pos.x < 0 || next_pos.x >= map->width)
		return ;
	if (map->map[next_pos.y][next_pos.x] == 'E')
		process_goal_achievement(map);
	if (map->map[next_pos.y][next_pos.x] == '0'
		|| map->map[next_pos.y][next_pos.x] == 'C')
	{
		collect_item_at_pos(map, next_pos);
		update_player_position_on_map(map, p_pos, next_pos);
	}
}

static bool	handle_gravity_collect_and_move(t_map *map, t_coord *current_pos,
		t_coord next_pos_down, char tile_below)
{
	if (tile_below == 'C')
	{
		map->count_tea++;
		map->map[next_pos_down.y][next_pos_down.x] = '0';
	}
	update_player_position_on_map(map, *current_pos, next_pos_down);
	*current_pos = next_pos_down;
	return (true);
}

bool	process_one_gravity_step(t_map *map, t_coord *current_pos)
{
	t_coord	next_pos_down;
	char	tile_below;

	next_pos_down.x = current_pos->x;
	next_pos_down.y = current_pos->y + 1;
	if (next_pos_down.y >= map->height)
		return (false);
	tile_below = map->map[next_pos_down.y][next_pos_down.x];
	if (tile_below == '1' || tile_below == 'O')
		return (false);
	if (tile_below == 'E')
	{
		process_goal_achievement(map);
		return (false);
	}
	if (tile_below == '0' || tile_below == 'C')
		return (handle_gravity_collect_and_move(map, current_pos, next_pos_down,
				tile_below));
	return (false);
}
