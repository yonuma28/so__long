/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:46:56 by marvin            #+#    #+#             */
/*   Updated: 2025/01/31 18:09:15 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move(int keycode, t_map *struct_map)
{
	int	prev_count;

	prev_count = struct_map->count;
	if (keycode == XK_Escape)
		exit(0);
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
		exit(0);
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

void	set_mlx_win(struct map *map_struct)
{
	map_struct->mlx = mlx_init();
	if (map_struct->mlx == NULL)
	{
		fprintf(stderr, "Error\n");
		exit(1);
	}
	map_struct->win = mlx_new_window(map_struct->mlx, 1800, 600, "so_long");
	if (map_struct->win == NULL)
	{
		fprintf(stderr, "Error\n");
		exit(1);
	}
}

void	search_player(t_map *map, int *x, int *y)
{
	*y = 0;
	while (*y < map->height)
	{
		*x = 0;
		while (*x < map->width)
		{
			if (map->map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
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
			exit(0);
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
	set_mlx_win(&map_struct);
	map_init(&map_struct);
	read_map(&map_struct, argv[1]);
	if (check_map_inclument(&map_struct) == -1)
		return (1); // error書いといて
	if (map_struct.is_invalid == 1)
		return (1); // error書いといて
	draw_map(&map_struct);
	mlx_key_hook(map_struct.win, handle_keypress, &map_struct);
	mlx_loop_hook(map_struct.mlx, loop_hook, &map_struct);
	mlx_loop(map_struct.mlx);
	return (0);
}
