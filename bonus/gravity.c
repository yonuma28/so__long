/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gravity.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:14:57 by yonuma            #+#    #+#             */
/*   Updated: 2025/06/28 12:26:43 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	apply_gravity(t_map *map)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	search_player(map, &x, &y);
	if (map->goal2)
	{
		usleep(15000);
		if (map->map[y + 1][x] == '1' || map->map[y + 1][x] == 'O')
		{
			map->is_falling = false;
			return (0);
		}
		if (map->map[y + 1][x] == 'E')
		{
			map->goal3 = true;
			printf("GOAL!!\nresult: %d\n", map->count);
			cleanup_and_exit(map);
		}
		map->is_falling = true;
		if (map->map[y][x] == 'P' && map->map[y + 1][x] == '0')
		{
			map->map[y + 1][x] = 'P';
			map->map[y][x] = '0';
		}
	}
	draw_map(map);
	return (0);
}

void	apply_gravity_after_jump(t_map *map)
{
	t_coord	current_pos;

	current_pos.x = map->player_x;
	current_pos.y = map->player_y;
	process_one_gravity_step(map, &current_pos);
}

void	apply_continuous_gravity(t_map *map)
{
	t_coord	current_pos;

	if (map->is_jumping)
		return ;
	current_pos.x = map->player_x;
	current_pos.y = map->player_y;
	process_one_gravity_step(map, &current_pos);
}
