/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:50:19 by yonuma            #+#    #+#             */
/*   Updated: 2025/06/14 11:22:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

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
	if (!line)
		return (0);
	while (line)
	{
		line_length = ft_strlen(line);
		if (line_length > 0 && line[line_length - 1] == '\n')
		{
			line_length--;
		}
		if (line_length > *width)
			*width = line_length;
		(*height)++;
		free(line);
		line = get_next_line(fd);
	}
	if (*height == 0)
		return (0);
	close(fd);
	return (1);
}

static char	**allocate_map(t_map *map, int height)
{
	map->height = height;
	map->map = malloc(sizeof(char *) * (height + 1));
	return (map->map);
}

static void	count_items(t_map *map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	map->count_teas = count;
}

int	read_map(t_map *map, char *filename)
{
	int		height;
	int		status;
	int		fd;
	char	*line;
	char	*temp;

	if (get_map_height_and_width(filename, &map->height, &map->width) == 0)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (map->height == 0 || !allocate_map(map, map->height) || fd < 0)
		return (-1);
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
	status = 0;
	close(fd);
	count_items(map);
	status |= check_map_inclument(map);
	printf("status: %d\n", status);
	status |= check_map_char(map);
	printf("status: %d\n", status);
	status |= check_map_wall(map);
	printf("status: %d\n", status);
	status |= check_map_invalid(map);
	printf("status: %d\n", status);
	if (status == -1)
		return (status);
	return (0);
}
