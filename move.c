/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:44:43 by marvin            #+#    #+#             */
/*   Updated: 2024/12/20 11:44:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void find_player(t_map *map)
{
    int x;
    int y;

    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (map->map[y][x] == 'P')
            {
                map->player_x = x;
                map->player_y = y;
                return;
            }
            x++;
        }
        y++;
    }
}

void move_a(t_map *map)
{
    find_player(map);
    int x;
    int y;

    x = map->player_x;
    y = map->player_y;
    if (x > 0 && (map->map[y][x - 1] == '0' || map->map[y][x - 1] == 'C'
        || (map->map[y][x - 1] == 'E' && map->count_tea - 1 == map->count_teas)))
    {
        if (map->map[y][x - 1] == 'C')
            map->count_tea++;
        if (map->map[y][x - 1] == 'E' && map->count_tea - 1 == map->count_teas)
            map->goal2 = true;
        map->map[y][x - 1] = 'P';
        map->map[y][x] = '0';
        map->count++;
        map->player_x--;
    }
}

void move_d(t_map *map)
{
    find_player(map);
    int x;
    int y;

    x = map->player_x;
    y = map->player_y;
    if (x < map->width - 1 && (map->map[y][x + 1] == '0' || map->map[y][x + 1] == 'C'
        || (map->map[y][x + 1] == 'E' && map->count_tea - 1 == map->count_teas)))
    {
        if (map->map[y][x + 1] == 'C')
            map->count_tea++;
        if (map->map[y][x + 1] == 'E' && map->count_tea - 1 == map->count_teas)
            map->goal2 = true;
        map->map[y][x + 1] = 'P';
        map->map[y][x] = '0';
        map->count++;
        map->player_x++;
    }
}

void move_w(t_map *map)
{
    find_player(map);
    int x;
    int y;

    x = map->player_x;
    y = map->player_y;
    if (y > 0 && (map->map[y - 1][x] == '0' || map->map[y - 1][x] == 'C'
        || (map->map[y - 1][x] == 'E' && map->count_tea - 1 == map->count_teas)))
    {
        if (map->map[y - 1][x] == 'C')
            map->count_tea++;
        if (map->map[y - 1][x] == 'E' && map->count_tea - 1 == map->count_teas)
            map->goal2 = true;
        map->map[y - 1][x] = 'P';
        map->map[y][x] = '0';
        map->count++;
        map->player_y--;
    }
}

void move_s(t_map *map)
{
    find_player(map);
    int x;
    int y;

    x = map->player_x;
    y = map->player_y;
    if (y < map->height - 1 && (map->map[y + 1][x] == '0' || map->map[y + 1][x] == 'C'
        || (map->map[y + 1][x] == 'E' && map->count_tea - 1 == map->count_teas)))
    {
        if (map->map[y + 1][x] == 'C')
            map->count_tea++;
        if (map->map[y + 1][x] == 'E' && map->count_tea - 1 == map->count_teas)
            map->goal2 = true;
        map->map[y + 1][x] = 'P';
        map->map[y][x] = '0';
        map->count++;
        map->player_y++;
    }
}
