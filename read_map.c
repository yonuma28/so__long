/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:50:19 by yonuma            #+#    #+#             */
/*   Updated: 2025/06/14 21:21:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

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
	status |= check_map_char(map);
	status |= check_map_wall(map);
	status |= check_map_invalid(map);
	if (status == -1)
		return (status);
	return (0);
}
