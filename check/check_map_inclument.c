/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_inclument.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:30:13 by marvin            #+#    #+#             */
/*   Updated: 2025/06/13 09:30:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map_inclument(struct map *map_struct)
{
	int is_E;
	int is_P;
	int is_C;
	int width;
	int height;

	is_E = 0;
	is_P = 0;
	is_C = 0;
	width = map_struct->width;
	height = map_struct->height;
	while (height)
	{
		width = map_struct->width;
		while (width)
		{
			if (map_struct->map[height - 1][width - 1] == 'E')
				is_E++;
			if (map_struct->map[height - 1][width - 1] == 'P')
				is_P++;
			if (map_struct->map[height - 1][width - 1] == 'C')
				is_C++;
			width--;
		}
		height--;
	}
	if (is_E == 0 || is_P == 0 || is_C == 0)
	{
		map_struct->is_invalid = 1;
		return (-1);
	}
	map_struct->count_teas = is_C;
	return (0);
}
