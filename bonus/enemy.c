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

void game_over(t_map *map)
{
    mlx_string_put(map->mlx, map->win, 100, 100, 0x00FF0000, "Game Over");
    printf("Game Over\n");
    exit(0);
}

void set_enemy(t_map *map)
{
    int x;
    int y;

    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (map->map[y][x] == '0')
            {
                map->map[y][x] = 'N';
                return;
            }
            x++;
        }
        y++;
    }
}

static void execute_enemy_move(t_map *map, int old_ex, int old_ey, int new_ex, int new_ey)
{
    if (map->map[new_ey][new_ex] == 'P')
    {
        game_over(map);
    }
    map->map[old_ey][old_ex] = '0';
    map->map[new_ey][new_ex] = 'N';
}

static bool try_move_enemy_in_direction(t_map *map, int ex, int ey, int player_x, int player_y)
{
    if (ex < player_x && (map->map[ey][ex + 1] == '0' || map->map[ey][ex + 1] == 'P'))
    {
        execute_enemy_move(map, ex, ey, ex + 1, ey);
        return true;
    }
    else if (ex > player_x && (map->map[ey][ex - 1] == '0' || map->map[ey][ex - 1] == 'P'))
    {
        execute_enemy_move(map, ex, ey, ex - 1, ey);
        return true;
    }
    else if (ey < player_y && (map->map[ey + 1][ex] == '0' || map->map[ey + 1][ex] == 'P'))
    {
        execute_enemy_move(map, ex, ey, ex, ey + 1);
        return true;
    }
    else if (ey > player_y && (map->map[ey - 1][ex] == '0' || map->map[ey - 1][ex] == 'P'))
    {
        execute_enemy_move(map, ex, ey, ex, ey - 1);
        return true;
    }
    return false;
}

static void process_single_enemy_movement(t_map *map)
{
    int player_x, player_y;
    int ex_search, ey_search;

    search_player(map, &player_x, &player_y);

    ey_search = 0;
    while (ey_search < map->height)
    {
        ex_search = 0;
        while (ex_search < map->width)
        {
            if (map->map[ey_search][ex_search] == 'N')
            {
                if (try_move_enemy_in_direction(map, ex_search, ey_search, player_x, player_y))
                {
                    return;
                }
            }
            ex_search++;
        }
        ey_search++;
    }
}

int enemy(t_map *map)
{
    static int count = 0;

    count++;
    if (map->goal1 && count == 1)
    {
        process_single_enemy_movement(map);
        draw_map(map);
    }

    if (count == 100)
        count = 0;
    return (0);
}
