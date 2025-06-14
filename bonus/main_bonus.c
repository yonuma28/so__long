/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:46:56 by marvin            #+#    #+#             */
/*   Updated: 2025/06/14 16:54:53 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

void	move(int keycode, t_map *struct_map)
{
	int	prev_count;

	prev_count = struct_map->count;
	if (keycode == XK_Escape)
		cleanup_and_exit(struct_map);
	if (keycode == XK_a)
		move_a(struct_map);
	if (keycode == XK_d)
		move_d(struct_map);
	if (keycode == XK_w)
		move_w(struct_map);
	if (keycode == XK_s)
		move_s(struct_map);
	if (prev_count != struct_map->count)
		printf("count: %d\n", struct_map->count); // printf
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
		printf("count: %d\n", struct_map->count); // printf
}

int	handle_keypress(int keycode, t_map *struct_map)
{
	if (!struct_map->goal2)
		move(keycode, struct_map);
	else
	{
		if (struct_map->is_falling)
			return (0);
		move_bonus(keycode, struct_map);
	}
	draw_map(struct_map);
	if (struct_map->count_tea == struct_map->count_teas)
	{
		struct_map->goal1 = true;
		set_enemy(struct_map);
		struct_map->count_tea++;
		draw_map(struct_map);
	}
	return (0);
}


void	set_mlx_win(struct map *map_struct, char *file_name)
{
	int	map_width;
	int	map_height;
	int	window_width;
	int	window_height;

	map_width = get_map_width(file_name);
	map_height = get_map_height(file_name);
	window_width = map_width * 64;
	window_height = map_height * 64;
	map_struct->mlx = mlx_init();
	if (map_struct->mlx == NULL)
	{
		fprintf(stderr, "Error\n");
		exit(1);
	}
	map_struct->win = mlx_new_window(map_struct->mlx, window_width, window_height, "so_long");
	if (map_struct->win == NULL)
	{
		fprintf(stderr, "Error\n");
		exit(1);
	}
}

int	apply_gravity(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	search_player(map, &x, &y);
	if (map->goal2)
	{
		usleep(50000);
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

int	loop_hook(t_map *map)
{
	apply_gravity(map);
	enemy(map);
	return (0);
}

int	main(int argc, char **argv)
{
	struct map		map_struct;

	(void)argc;
	map_init(&map_struct);
	if (read_map(&map_struct, argv[1]) != 0)
	{
		printf("Error\n");
		return (1);
	}
	set_mlx_win(&map_struct, argv[1]);
	map_struct.texture = set_texture();
	if (map_struct.is_invalid == 1)
		return (1);
	draw_map(&map_struct);
	mlx_key_hook(map_struct.win, handle_keypress, &map_struct);
	mlx_loop_hook(map_struct.mlx, loop_hook, &map_struct);
	mlx_loop(map_struct.mlx);
	return (0);
}
