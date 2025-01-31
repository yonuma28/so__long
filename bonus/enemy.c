/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:49:04 by yonuma            #+#    #+#             */
/*   Updated: 2025/01/18 12:50:18 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void	game_over(t_map *map)
{
	mlx_string_put(map->mlx, map->win, 100, 100, 0x00FF0000, "Game Over");
	printf("Game Over\n"); // printf
	exit(0);
}

void	set_ememy(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == '0')
			{
				map->map[y][x] = 'N';
				return ;
			}
			x++;
		}
		y++;
	}
}

int	enemy(t_map *map)
{
	int	x;
	int	y;
	int	ex;
	int	ey;
	static int	count = 0;

	count++;
	if (map->goal1 && count == 1)
	{
		search_player(map, &x, &y);
		ey = 0;
		while (ey < map->height)
		{
			ex = 0;
			while (ex < map->width)
			{
				if (map->map[ey][ex] == 'N')
				{
					if (ex < x && (map->map[ey][ex + 1] == '0' || map->map[ey][ex + 1] == 'P'))
					{
						if (map->map[ey][ex + 1] == 'P')
							game_over(map);
						map->map[ey][ex] = '0';
						map->map[ey][ex + 1] = 'N';
						break;
					}
					else if (ex > x && (map->map[ey][ex - 1] == '0' || map->map[ey][ex - 1] == 'P'))
					{
						if (map->map[ey][ex - 1] == 'P')
							game_over(map);
						map->map[ey][ex] = '0';
						map->map[ey][ex - 1] = 'N';
						break;
					}
					else if (ey < y && (map->map[ey + 1][ex] == '0' || map->map[ey + 1][ex] == 'P'))
					{
						if (map->map[ey + 1][ex] == 'P')
							game_over(map);
						map->map[ey][ex] = '0';
						map->map[ey + 1][ex] = 'N';
						break;
					}
					else if (ey > y && (map->map[ey - 1][ex] == '0' || map->map[ey - 1][ex] == 'P'))
					{
						if (map->map[ey - 1][ex] == 'P')
							game_over(map);
						map->map[ey][ex] = '0';
						map->map[ey - 1][ex] = 'N';
						break;
					}
				}
				ex++;
			}
			ey++;
		}
		draw_map(map);
	}
	if (count == 200)
		count = 0;
	return (0);
}
