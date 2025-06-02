/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:57:26 by yonuma            #+#    #+#             */
/*   Updated: 2025/01/25 16:41:15 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void process_goal_achievement(t_map *map)
{
    printf("GOAL!!\nresult: %d\n", map->count);
    exit(0);
}

static void collect_item_at_pos(t_map *map, t_coord pos)
{
    if (map->map[pos.y][pos.x] == 'C')
    {
        map->count_tea++;
        map->map[pos.y][pos.x] = '0';
    }
}

static void update_player_position_on_map(t_map *map,
        t_coord old_pos, t_coord new_pos)
{
    map->map[new_pos.y][new_pos.x] = 'P';
    map->map[old_pos.y][old_pos.x] = '0';
    map->player_x = new_pos.x;
    map->player_y = new_pos.y;
    map->count++;
}

static void handle_horizontal_move(t_map *map, t_coord p_pos, int dx)
{
    t_coord next_pos;

    next_pos.y = p_pos.y;
    next_pos.x = p_pos.x + dx;

    if (next_pos.x < 0 || next_pos.x >= map->width)
        return;
    if (map->map[next_pos.y][next_pos.x] == 'E')
        process_goal_achievement(map);
    if (map->map[next_pos.y][next_pos.x] == '0' ||
        map->map[next_pos.y][next_pos.x] == 'C')
    {
        collect_item_at_pos(map, next_pos);
        update_player_position_on_map(map, p_pos, next_pos);
    }
}

void    move_a_bonus(t_map *map)
{
    t_coord p_pos;

    if (map->is_jumping)
        return;
    search_player(map, &p_pos.x, &p_pos.y);
    handle_horizontal_move(map, p_pos, -1);
}

void    move_d_bonus(t_map *map)
{
    t_coord p_pos;

    if (map->is_jumping)
        return;
    search_player(map, &p_pos.x, &p_pos.y);
    handle_horizontal_move(map, p_pos, 1);
}

static void perform_jump_one_step(t_map *map, t_player_state *p_state)
{
    t_coord next_pos;

    next_pos.x = p_state->pos.x;
    next_pos.y = p_state->pos.y - 1;

    if (next_pos.y < 0 || map->map[next_pos.y][next_pos.x] == '1')
    {
        p_state->jump_remaining = 0;
        return;
    }

    if (map->map[next_pos.y][next_pos.x] == 'E')
        process_goal_achievement(map);

    collect_item_at_pos(map, next_pos);
    update_player_position_on_map(map, p_state->pos, next_pos);
    p_state->pos = next_pos;
    p_state->jump_remaining--;
}

static void perform_jump_over_obstacle(t_map *map, t_player_state *p_state)
{
    t_coord landing_pos;
    t_coord obstacle_pos;

    obstacle_pos.x = p_state->pos.x;
    obstacle_pos.y = p_state->pos.y - 1;
    landing_pos.x = p_state->pos.x;
    landing_pos.y = p_state->pos.y - 2;

    if (landing_pos.y < 0 || map->map[landing_pos.y][landing_pos.x] == '1' ||
        map->map[obstacle_pos.y][obstacle_pos.x] != 'O')
    {
        p_state->jump_remaining = 0;
        return;
    }

    if (map->map[landing_pos.y][landing_pos.x] == 'E')
    {
        map->goal3 = true;
        process_goal_achievement(map);
    }

    if (map->map[landing_pos.y][landing_pos.x] == 'C')
    {
        map->count_tea++;
        map->map[landing_pos.y][landing_pos.x] = '0';
    }

    update_player_position_on_map(map, p_state->pos, landing_pos);

    p_state->pos = landing_pos;
    p_state->jump_remaining -= 2;
    if (p_state->jump_remaining < 0)
        p_state->jump_remaining = 0;
}

static bool process_one_gravity_step(t_map *map, t_coord *current_pos)
{
    t_coord next_pos_down;
    char    tile_below;

    next_pos_down.x = current_pos->x;
    next_pos_down.y = current_pos->y + 1;
    if (next_pos_down.y >= map->height)
        return (false);
    tile_below = map->map[next_pos_down.y][next_pos_down.x];
    if (tile_below == '1' || tile_below == 'O')
        return (false);
    else if (tile_below == 'E')
    {
        process_goal_achievement(map);
        return (false);
    }
    else if (tile_below == '0' || tile_below == 'C')
    {
        if (tile_below == 'C')
        {
            map->count_tea++;
            map->map[next_pos_down.y][next_pos_down.x] = '0';
        }
        update_player_position_on_map(map, *current_pos, next_pos_down);
        *current_pos = next_pos_down;
        return (true);
    }
    return (false);
}

static void apply_gravity_after_jump(t_map *map)
{
    t_coord current_pos;

    current_pos.x = map->player_x;
    current_pos.y = map->player_y;
    
    // 重力を1ステップだけ適用（ゆっくりと落下）
    process_one_gravity_step(map, &current_pos);
}

// 継続的な重力適用のための関数
void    apply_continuous_gravity(t_map *map)
{
    t_coord current_pos;

    if (map->is_jumping)
        return;
    
    current_pos.x = map->player_x;
    current_pos.y = map->player_y;
    
    // 1ステップずつ重力を適用
    process_one_gravity_step(map, &current_pos);
}

static void calculate_jump_destination(t_map *map, t_coord start_pos,
                t_jump_result *result)
{
    int     i;
    t_coord check_pos;
    char    tile_at_check_pos;

    result->final_pos = start_pos;
    result->distance = 0;
    result->reached_exit = false;
    i = 1;
    while (i <= 4)
    {
        check_pos.x = start_pos.x;
        check_pos.y = start_pos.y - i;
        if (check_pos.y < 0)
            break ;
        tile_at_check_pos = map->map[check_pos.y][check_pos.x];
        // 障害物判定：'1'（壁）のみを障害物として扱い、'O'（梯子）は無視
        if (tile_at_check_pos == '1')
            break ;
        result->final_pos = check_pos;
        result->distance = i;
        if (tile_at_check_pos == 'E')
        {
            result->reached_exit = true;
            break ;
        }
        i++;
    }
}

static void collect_on_jump_path(t_map *map, t_coord start_pos,
                int jump_distance)
{
    int     i;
    t_coord path_pos;

    i = 1;
    while (i <= jump_distance)
    {
        path_pos.x = start_pos.x;
        path_pos.y = start_pos.y - i;
        if (map->map[path_pos.y][path_pos.x] == 'C')
        {
            map->count_tea++;
            map->map[path_pos.y][path_pos.x] = '0';
        }
        i++;
    }
}

void    move_w_bonus(t_map *map)
{
    t_coord         start_pos;
    t_jump_result   jump_res;

    if (map->is_jumping)
        return ;
    search_player(map, &start_pos.x, &start_pos.y);
    map->is_jumping = true;
    calculate_jump_destination(map, start_pos, &jump_res);
    if (jump_res.distance > 0)
    {
        collect_on_jump_path(map, start_pos, jump_res.distance);
        update_player_position_on_map(map, start_pos, jump_res.final_pos);
        if (jump_res.reached_exit)
        {
            process_goal_achievement(map);
            return ;
        }
    }
    map->is_jumping = false;
    apply_gravity_after_jump(map);
}

void    move_s_bonus(t_map *map)
{
    t_coord p_pos;
    t_coord obstacle_pos;
    t_coord landing_pos;

    if (map->is_jumping)
        return;
    search_player(map, &p_pos.x, &p_pos.y);

    obstacle_pos.x = p_pos.x;
    obstacle_pos.y = p_pos.y + 1;
    landing_pos.x = p_pos.x;
    landing_pos.y = p_pos.y + 2;

    if (obstacle_pos.y >= map->height || landing_pos.y >= map->height)
        return;

    if (map->map[obstacle_pos.y][obstacle_pos.x] == 'O' &&
        (map->map[landing_pos.y][landing_pos.x] == '0' ||
         map->map[landing_pos.y][landing_pos.x] == 'C' ||
         map->map[landing_pos.y][landing_pos.x] == 'E'))
    {
        if (map->map[landing_pos.y][landing_pos.x] == 'E')
            process_goal_achievement(map);
        collect_item_at_pos(map, landing_pos);
        update_player_position_on_map(map, p_pos, landing_pos);
        map->map[obstacle_pos.y][obstacle_pos.x] = '0';
    }
}

void    set_obstacle(t_map *map)
{
    t_coord p_pos;
    t_coord obstacle_target_pos;

    search_player(map, &p_pos.x, &p_pos.y);

    obstacle_target_pos.x = p_pos.x;
    obstacle_target_pos.y = p_pos.y - 1;

    if (obstacle_target_pos.y < 0)
        return;

    if (map->map[obstacle_target_pos.y][obstacle_target_pos.x] == '0')
    {
        map->map[obstacle_target_pos.y][obstacle_target_pos.x] = 'O';
    }
}
