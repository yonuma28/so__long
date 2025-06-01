/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:49:47 by marvin            #+#    #+#             */
/*   Updated: 2024/12/20 11:49:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include "libmlx/mlx.h"

typedef struct texture
{
    void *img_0;
    void *img_window;
    void *img_wall;
    void *img_PC1;
    void *img_PC2;
    void *img_E;
    void *img_Person1;
    void *img_Person2;
    void *img_tea;
    void *enemy;
    void *character;
    void *object;
    int width;
    int height;
    int img_width;
    int img_height;
} texture;

typedef struct map
{
    char **map;
    void *mlx;
    void *win;
    int width;
    int height;
    int is_invalid;
    int map_height;
    int count;
    int count_tea;
    int count_teas;
    int player_x;
    int player_y;
    bool is_jumping;
    bool is_falling;
    double jump_velocity;
    double jump_time; 
    bool is_E;
    bool goal1;
    bool goal2;
    bool goal3;
    struct texture texture;
} t_map;

// texture
struct texture set_new_texture(void);
struct texture set_texture(void);
struct texture next_stage_texture(void);

// move
void    move_a(struct map *map);
void    move_d(struct map *map);
void    move_w(struct map *map);
void    move_s(struct map *map);

// move_bonus
void    move_a_bonus(struct map *map);
void    move_d_bonus(struct map *map);
void    move_w_bonus(struct map *map);
void    move_s_bonus(struct map *map);
void    set_obstacle(struct map *map);

// map_check_init
int     check_map_inclument(struct map *map_struct);
void    map_init(struct map *map_struct);

// draw_map
int     draw_map(struct map *map);

//utils
void    search_player(struct map *map, int *x, int *y);

// read_map
int     read_map(struct map *map, char *filename);

// enemy
void    set_ememy(struct map *map);
int     enemy(struct map *map);
void    game_over(struct map *map);

// load_new_map
void    load_new_map(struct map *map_struct);

// gnl
char	*get_next_line(int fd);

#endif