/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:07:39 by marvin            #+#    #+#             */
/*   Updated: 2025/06/14 21:07:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_w_bonus(t_map *map)
{
	t_coord			start_pos;
	t_jump_result	jump_res;

	if (map->is_jumping)
		return ;
	search_player(map, &start_pos.x, &start_pos.y);
	map->is_jumping = true;
	calculate_jump_destination(map, start_pos, &jump_res);
	if (jump_res.distance > 0)
	{
		collect_on_jump_path(map, start_pos, jump_res.distance);
		update_player_position_on_map(map, start_pos, jump_res.final_pos);
		if (jump_res.reached_exit)
		{
			process_goal_achievement(map);
			return ;
		}
	}
	map->is_jumping = false;
	apply_gravity_after_jump(map);
}

void	move_s_bonus(t_map *map)
{
	t_coord	p_pos;
	t_coord	obstacle_pos;
	t_coord	landing_pos;

	if (map->is_jumping)
		return ;
	search_player(map, &p_pos.x, &p_pos.y);
	obstacle_pos.x = p_pos.x;
	obstacle_pos.y = p_pos.y + 1;
	landing_pos.x = p_pos.x;
	landing_pos.y = p_pos.y + 2;
	if (obstacle_pos.y >= map->height || landing_pos.y >= map->height)
		return ;
	if (map->map[obstacle_pos.y][obstacle_pos.x] == 'O'
		&& (map->map[landing_pos.y][landing_pos.x] == '0'
			|| map->map[landing_pos.y][landing_pos.x] == 'C'
			|| map->map[landing_pos.y][landing_pos.x] == 'E'))
	{
		if (map->map[landing_pos.y][landing_pos.x] == 'E')
			process_goal_achievement(map);
		collect_item_at_pos(map, landing_pos);
		update_player_position_on_map(map, p_pos, landing_pos);
		map->map[obstacle_pos.y][obstacle_pos.x] = '0';
	}
}

void	move_a_bonus(t_map *map)
{
	t_coord	p_pos;

	if (map->is_jumping)
		return ;
	search_player(map, &p_pos.x, &p_pos.y);
	handle_horizontal_move(map, p_pos, -1);
}

void	move_d_bonus(t_map *map)
{
	t_coord	p_pos;

	if (map->is_jumping)
		return ;
	search_player(map, &p_pos.x, &p_pos.y);
	handle_horizontal_move(map, p_pos, 1);
}
