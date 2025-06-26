/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_move_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-26 15:13:42 by yonuma            #+#    #+#             */
/*   Updated: 2025-06-26 15:13:42 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move(int keycode, t_map *struct_map)
{
	int	prev_count;

	prev_count = struct_map->count;
	if (keycode == XK_Escape)
		cleanup_and_exit(struct_map);
	if (keycode == XK_a)
		attempt_move(struct_map, -1, 0);
	if (keycode == XK_d)
		attempt_move(struct_map, 1, 0);
	if (keycode == XK_w)
		attempt_move(struct_map, 0, 1);
	if (keycode == XK_s)
		attempt_move(struct_map, 0, -1);
	if (prev_count != struct_map->count)
		printf("count: %d\n", struct_map->count);
}

void	move_bonus(int keycode, t_map *struct_map)
{
	int	prev_count;

	prev_count = struct_map->count;
	if (keycode == XK_Escape)
		cleanup_and_exit(struct_map);
	if (keycode == XK_a)
		move_a_bonus(struct_map);
	if (keycode == XK_d)
		move_d_bonus(struct_map);
	if (keycode == XK_w)
		move_w_bonus(struct_map);
	if (keycode == XK_s)
		move_s_bonus(struct_map);
	if (keycode == XK_space)
		set_obstacle(struct_map);
	if (prev_count != struct_map->count)
		printf("count: %d\n", struct_map->count);
}
