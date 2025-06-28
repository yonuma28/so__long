/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:46:56 by marvin            #+#    #+#             */
/*   Updated: 2025/06/14 11:59:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

int	handle_keypress(int keycode, t_map *struct_map)
{
	static int	tmp = 0;

	if (keycode == XK_Escape)
		cleanup_and_exit(struct_map);
	if (keycode == XK_w)
		move_player(struct_map, 0, -1);
	if (keycode == XK_a)
		move_player(struct_map, -1, 0);
	if (keycode == XK_s)
		move_player(struct_map, 0, 1);
	if (keycode == XK_d)
		move_player(struct_map, 1, 0);
	if (tmp != struct_map->count)
		printf("count: %d\n", struct_map->count);
	draw_map(struct_map);
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
	window_width = map_width * 50;
	window_height = map_height * 50;
	map_struct->mlx = mlx_init();
	if (map_struct->mlx == NULL)
	{
		fprintf(stderr, "Error\n");
		exit(1);
	}
	map_struct->win = mlx_new_window(map_struct->mlx, window_width,
			window_height, "so_long");
	if (map_struct->win == NULL)
	{
		fprintf(stderr, "Error\n");
		exit(1);
	}
}

int	handle_destroy(t_map *map)
{
	cleanup_and_exit(map);
	return (0);
}

int	main(int argc, char **argv)
{
	struct map	map_struct;

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
	mlx_hook(map_struct.win, 17, 0L, handle_destroy, &map_struct);
	mlx_loop(map_struct.mlx);
	return (0);
}
