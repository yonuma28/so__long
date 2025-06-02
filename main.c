/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:46:56 by marvin            #+#    #+#             */
/*   Updated: 2025/01/25 16:52:36 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

int	handle_keypress(int keycode, t_map *struct_map)
{
	static int	tmp = 0;

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
	if (tmp != struct_map->count)
		printf("count: %d\n", struct_map->count);
	draw_map(struct_map);
	if (struct_map->count_tea == struct_map->count_teas && struct_map->goal2)
		exit(0);
	return (0);
}

static int	get_map_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height ++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static int	get_map_width(char *file_name)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	width = ft_strlen(line);
	if (line[width - 1] == '\n')
		width--;
	free(line);
	close(fd);
	return (width);
}

void	read_map1(struct map *map_struct, char *file_name)
{
	int		fd;
	int		height;
	char	*line;
	char	*tmp;

	fd = open(file_name, O_RDONLY);
	map_struct->map = (char **)malloc(sizeof(char *) * 9);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = ft_strchr(line, '\n');
		if (tmp)
			*tmp = '\0';
		map_struct->map[height] = ft_strdup(line);
		free(line);
		height++;
	}
	if (check_map_inclument(map_struct) == -1)
		map_struct->is_invalid = 1;
	// if (check_map_structure(map_struct) == -1) // マップの構造が正しいかチェック
	// 	map_struct.is_invalid = 1;
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
	if (window_width < 320)
		window_width = 320;
	if (window_height < 240)
		window_height = 240;
	if (window_width > 1920)
		window_width = 1920;
	if (window_height > 1080)
		window_height = 1080;
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

int	main(int args, char **argv)
{
	struct map		map_struct;

	(void)args;
	map_init(&map_struct);
	set_mlx_win(&map_struct, argv[1]);
	map_struct.texture = set_texture();
	if (read_map(&map_struct, argv[1]) == 0)
	{
		printf("Error\n");
	}
	if (map_struct.is_invalid == 1)
		return (1);
	draw_map(&map_struct);
	mlx_key_hook(map_struct.win, handle_keypress, &map_struct);
	mlx_loop(map_struct.mlx);
	return (0);
}
