/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:57:26 by yonuma            #+#    #+#             */
/*   Updated: 2025/06/28 12:53:18 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	search_jump_path(t_map *map, t_coord start_pos,
		t_jump_result *result)
{
	int		i;
	t_coord	check_pos;
	char	tile_at_check_pos;

	i = 1;
	while (i <= 3)
	{
		check_pos.x = start_pos.x;
		check_pos.y = start_pos.y - i;
		if (check_pos.y < 0)
			break ;
		tile_at_check_pos = map->map[check_pos.y][check_pos.x];
		if (tile_at_check_pos == '1')
			break ;
		result->final_pos = check_pos;
		result->distance = i;
		if (tile_at_check_pos == 'E')
		{
			result->reached_exit = true;
			break ;
		}
		i++;
	}
}

void	calculate_jump_destination(t_map *map, t_coord start_pos,
		t_jump_result *result)
{
	result->final_pos = start_pos;
	result->distance = 0;
	result->reached_exit = false;
	search_jump_path(map, start_pos, result);
}

void	collect_on_jump_path(t_map *map, t_coord start_pos, int jump_distance)
{
	int		i;
	t_coord	path_pos;

	i = 1;
	while (i <= jump_distance)
	{
		path_pos.x = start_pos.x;
		path_pos.y = start_pos.y - i;
		if (map->map[path_pos.y][path_pos.x] == 'C')
		{
			map->count_tea++;
			map->map[path_pos.y][path_pos.x] = '0';
		}
		i++;
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
		return ;
	if (map->map[obstacle_target_pos.y][obstacle_target_pos.x] == '0')
	{
		map->map[obstacle_target_pos.y][obstacle_target_pos.x] = 'O';
	}
}
