/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:50:19 by yonuma            #+#    #+#             */
/*   Updated: 2025/01/31 18:04:41 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

static int	get_map_height_and_width(char *filename, int *height, int *width)
{
	int		fd;
	char	*line;
	int		line_length;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	*height = 0;
	*width = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_length = ft_strlen(line);
		if (line_length > *width)
			*width = line_length;
		(*height)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

static char	**allocate_map(t_map *map, int height)
{
	map->height = height;
	map->map = malloc(sizeof(char *) * (height + 1));
	return (map->map);
}

int	read_map(t_map *map, char *filename)
{
	int		height;
	int		fd;
	char	*line;
	char	*temp;

	if (!get_map_height_and_width(filename, &map->height, &map->width))
	{
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (map->height == 0 || !allocate_map(map, map->height) || fd < 0)
		return (0);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = ft_strchr(line, '\n');
		if (temp)
			*temp = '\0';
		map->map[height] = ft_strdup(line);
		free(line);
		height++;
	}
	map->map[height] = NULL;
	close(fd);
	// 文字が揃っているかを見る
	// check_map_inclument(map);
	// // 文字が多くないか見る
	// check_map_char(map);
	// // マップが１で囲まれているかをみる
	// check_map_wall(map);
	// // マップが有効か見る
	// check_map_invalid(map);
	return (0);
}
