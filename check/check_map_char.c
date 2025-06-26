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

static int	is_valid_map_char(char c)
{
	return (ft_strchr("10ECP", c) != NULL);
}

static void	count_map_chars(char c, int *count_e, int *count_p, int *count_c)
{
	if (c == 'E')
		(*count_e)++;
	else if (c == 'P')
		(*count_p)++;
	else if (c == 'C')
		(*count_c)++;
}

static int	check_map_char_loop(t_map *map_struct, int *count_e, int *count_p,
		int *count_c)
{
	int		y;
	int		x;
	char	current_char;

	y = 0;
	while (y < map_struct->height)
	{
		x = 0;
		while (x < map_struct->width)
		{
			current_char = map_struct->map[y][x];
			if (!is_valid_map_char(current_char))
			{
				map_struct->is_invalid = 1;
				return (-1);
			}
			count_map_chars(current_char, count_e, count_p, count_c);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_map_char(t_map *map_struct)
{
	int	count_e;
	int	count_p;
	int	count_c;
	int	result;

	count_e = 0;
	count_p = 0;
	count_c = 0;
	result = check_map_char_loop(map_struct, &count_e, &count_p, &count_c);
	if (result == -1)
		return (-1);
	if (count_e != 1 || count_p != 1)
	{
		map_struct->is_invalid = 1;
		return (-1);
	}
	map_struct->count_teas = count_c;
	return (0);
}
