/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:00:21 by yonuma            #+#    #+#             */
/*   Updated: 2025/06/14 20:14:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"
#include <stdio.h>

int	check_map_char(t_map *map_struct)
{
	int	y;
	int	x;
	int	count_e;
	int	count_p;
	int	count_c;
	char current_char;

	y = 0;
	count_e = 0;
	count_p = 0;
	count_c = 0;
	while (y < map_struct->height)
	{
		x = 0;
		while (x < map_struct->width)
		{
			current_char = map_struct->map[y][x];
			if (!ft_strchr("10ECP", current_char))
			{
				map_struct->is_invalid = 1;
				return (-1);
			}
			if (current_char == 'E')
				count_e++;
			else if (current_char == 'P')
				count_p++;
			else if (current_char == 'C')
				count_c++;
			x++;
		}
		y++;
	}
	if (count_e != 1 || count_p != 1)
	{
		map_struct->is_invalid = 1;
		return (-1);
	}
	map_struct->count_teas = count_c;
	return (0);
}
