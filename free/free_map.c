/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 12:19:41 by marvin            #+#    #+#             */
/*   Updated: 2025/06/14 12:19:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map_data(t_map *map)
{
	int	i;

	if (map == NULL || map->map == NULL)
		return ;
	i = 0;
	while (i < map->height)
	{
		if (map->map[i])
		{
			free(map->map[i]);
			map->map[i] = NULL;
		}
		i++;
	}
	free(map->map);
	map->map = NULL;
}

int	cleanup_and_exit(t_map *map)
{
	if (map == NULL)
		exit(1);
	free_map_data(map);
	if (map->win)
		mlx_destroy_window(map->mlx, map->win);
	if (map->mlx)
	{
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	exit(0);
	return (0);
}
