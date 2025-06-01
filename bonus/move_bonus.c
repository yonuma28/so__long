/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:57:26 by yonuma            #+#    #+#             */
/*   Updated: 2025/01/25 16:41:15 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	process_goal_achievement(t_map *map)
{
	printf("GOAL!!\nresult: %d\n", map->count);
	exit(0);
}

static void	collect_item_if_any(t_map *map, t_coord pos)
{
	if (map->map[pos.y][pos.x] == 'C')
	{
		map->count_tea++;
		map->map[pos.y][pos.x] = '0';
	}
	else if (map->map[pos.y][pos.x] == 'O')
	{
		map->count_tea++;
		map->map[pos.y][pos.x] = '0';
	}
}

static void	move_player_on_map(t_map *map, t_coord old_pos, t_coord new_pos)
{
	map->map[new_pos.y][new_pos.x] = 'P';
	map->map[old_pos.y][old_pos.x] = '0';
	map->count++;
}

static void	handle_horizontal_move(t_map *map, t_coord p_pos, int dx)
{
	t_coord	next_pos;

	next_pos.y = p_pos.y;
	next_pos.x = p_pos.x + dx;
	if (next_pos.x < 0 || next_pos.x >= map->width)
		return;
	if (map->map[next_pos.y][next_pos.x] == 'E')
		process_goal_achievement(map);
	if (map->map[next_pos.y][next_pos.x] == '0' ||
		map->map[next_pos.y][next_pos.x] == 'C' ||
		map->map[next_pos.y][next_pos.x] == 'O')
	{
		collect_item_if_any(map, next_pos);
		move_player_on_map(map, p_pos, next_pos);
	}
}

void	move_a_bonus(t_map *map)
{
	t_coord	p_pos;

	if (map->is_jumping)
		return;
	search_player(map, &p_pos.x, &p_pos.y);
	handle_horizontal_move(map, p_pos, -1);
}

void	move_d_bonus(t_map *map)
{
	t_coord	p_pos;

	if (map->is_jumping)
		return;
	search_player(map, &p_pos.x, &p_pos.y);
	handle_horizontal_move(map, p_pos, 1);
}

static void	perform_jump_one_step(t_map *map, t_player_state *p_state)
{
	t_coord	next_pos;

	next_pos.x = p_state->pos.x;
	next_pos.y = p_state->pos.y - 1;
	if (next_pos.y < 0 || map->map[next_pos.y][next_pos.x] == '1')
	{
		p_state->jump_remaining = 0;
		return;
	}
	if (map->map[next_pos.y][next_pos.x] == 'E')
		process_goal_achievement(map);
	collect_item_if_any(map, next_pos);
	move_player_on_map(map, p_state->pos, next_pos);
	p_state->pos.y = next_pos.y;
	p_state->jump_remaining--;
}

static void	perform_jump_over_obstacle(t_map *map, t_player_state *p_state)
{
	t_coord	landing_pos;

	landing_pos.x = p_state->pos.x;
	landing_pos.y = p_state->pos.y - 2;
	if (landing_pos.y < 0 || map->map[landing_pos.y][landing_pos.x] == '1')
	{
		p_state->jump_remaining = 0;
		return;
	}
	if (map->map[p_state->pos.y - 1][p_state->pos.x] != 'O')
	{
		p_state->jump_remaining = 0;
		return;
	}
	if (map->map[landing_pos.y][landing_pos.x] == 'E')
	{
		map->goal3 = true;
		process_goal_achievement(map);
	}
	collect_item_if_any(map, landing_pos);
	move_player_on_map(map, p_state->pos, landing_pos);
	map->map[p_state->pos.y - 1][p_state->pos.x] = '0';
	p_state->pos.y = landing_pos.y;
	p_state->jump_remaining -= 2;
	if (p_state->jump_remaining < 0)
		p_state->jump_remaining = 0;
}

void	move_w_bonus(t_map *map)
{
	t_player_state	p_state;
	t_coord			next_tile_up;

	if (map->is_jumping)
		return;
	search_player(map, &p_state.pos.x, &p_state.pos.y);
	p_state.jump_remaining = 3;
	map->is_jumping = true;
	while (p_state.jump_remaining > 0)
	{
		next_tile_up.x = p_state.pos.x;
		next_tile_up.y = p_state.pos.y - 1;
		if (next_tile_up.y < 0 || map->map[next_tile_up.y][next_tile_up.x] == '1')
			break;
		if (map->map[next_tile_up.y][next_tile_up.x] == 'O')
			perform_jump_over_obstacle(map, &p_state);
		else if (map->map[next_tile_up.y][next_tile_up.x] == '0' ||
			map->map[next_tile_up.y][next_tile_up.x] == 'C' ||
			map->map[next_tile_up.y][next_tile_up.x] == 'E')
			perform_jump_one_step(map, &p_state);
		else
			break;
	}
	map->is_jumping = false;
}

void	move_s_bonus(t_map *map)
{
	t_coord	p_pos;
	t_coord	obstacle_pos;
	t_coord	landing_pos;

	if (map->is_jumping)
		return;
	search_player(map, &p_pos.x, &p_pos.y);
	obstacle_pos.x = p_pos.x;
	obstacle_pos.y = p_pos.y + 1;
	landing_pos.x = p_pos.x;
	landing_pos.y = p_pos.y + 2;
	if (obstacle_pos.y >= map->height || landing_pos.y >= map->height)
		return;
	if (map->map[obstacle_pos.y][obstacle_pos.x] == 'O' &&
		(map->map[landing_pos.y][landing_pos.x] == '0' ||
		map->map[landing_pos.y][landing_pos.x] == 'C' ||
		map->map[landing_pos.y][landing_pos.x] == 'E'))
	{
		if (map->map[landing_pos.y][landing_pos.x] == 'E')
			process_goal_achievement(map);
		collect_item_if_any(map, landing_pos);
		move_player_on_map(map, p_pos, landing_pos);
		map->map[obstacle_pos.y][obstacle_pos.x] = '0';
	}
}

void	set_obstacle(t_map *map)
{
	t_coord	p_pos;
	t_coord	obstacle_target_pos;

	search_player(map, &p_pos.x, &p_pos.y);
	obstacle_target_pos.x = p_pos.x;
	obstacle_target_pos.y = p_pos.y - 1;
	if (obstacle_target_pos.y < 0)
		return;
	if (map->map[obstacle_target_pos.y][obstacle_target_pos.x] == '0')
	{
		map->map[obstacle_target_pos.y][obstacle_target_pos.x] = 'O';
	}
}
