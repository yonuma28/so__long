/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:21:38 by marvin            #+#    #+#             */
/*   Updated: 2025/06/14 21:21:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

static void	update_map_size(char *line, int *height, int *width)
{
	int	line_length;

	line_length = ft_strlen(line);
	if (line_length > 0 && line[line_length - 1] == '\n')
		line_length--;
	if (line_length > *width)
		*width = line_length;
	(*height)++;
}

int	get_map_height_and_width(char *filename, int *height, int *width)
{
	int		fd;
	char	*line;

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
		update_map_size(line, height, width);
		free(line);
		line = get_next_line(fd);
	}
	if (*height == 0)
		return (0);
	close(fd);
	return (1);
}

char	**allocate_map(t_map *map, int height)
{
	map->height = height;
	map->map = malloc(sizeof(char *) * (height + 1));
	return (map->map);
}

void	count_items(t_map *map)
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
