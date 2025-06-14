/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:00:21 by yonuma            #+#    #+#             */
/*   Updated: 2025/06/14 11:32:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"
#include <stdio.h>

int	check_map_char(t_map *map_struct)
{
	int	y;
	int	x;
	int	count_E;
	int	count_P;
	int	count_C;

	y = 0;
	count_E = 0;
	count_P = 0;
	count_C = 0;
	while (y < map_struct->height)
	{
		x = 0;
		while (x < map_struct->width)
		{
			char	current_char;

			current_char = map_struct->map[y][x];
			if (!ft_strchr("10ECP", current_char))
			{
				map_struct->is_invalid = 1;
				return (-1);
			}
			if (current_char == 'E')
				count_E++;
			else if (current_char == 'P')
				count_P++;
			else if (current_char == 'C')
				count_C++;
			x++;
		}
		y++;
	}
	if (count_E != 1 || count_P != 1)
	{
		map_struct->is_invalid = 1;
		return (-1);
	}
	map_struct->count_teas = count_C;
	return (0);
}
