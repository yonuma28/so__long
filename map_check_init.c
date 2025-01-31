/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:54:11 by yonuma            #+#    #+#             */
/*   Updated: 2025/01/18 14:56:29 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		fprintf(stderr, "Error: Map is invalid\n");
		map_struct->is_invalid = 1;
		return (-1);
	}
	map_struct->count_teas = is_C;
	return (0);
}

void	map_init(struct map *map_struct)
{
	map_struct->map = NULL;
	map_struct->width = 0;
	map_struct->height = 0;
	map_struct->is_invalid = 0;
	map_struct->count = 0;
	map_struct->count_tea = 0;
	map_struct->count_teas = 0;
	map_struct->goal1 = false;
	map_struct->goal2 = false;
	map_struct->goal3 = false;
}
