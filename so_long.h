/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:49:47 by marvin            #+#    #+#             */
/*   Updated: 2025/06/28 13:34:54 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libmlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

typedef struct texture
{
	void		*img_0;
	void		*img_window;
	void		*img_wall;
	void		*img_pc1;
	void		*img_pc2;
	void		*img_e;
	void		*img_person1;
	void		*img_person2;
	void		*img_tea;
	void		*enemy;
	void		*character;
	void		*object;
	int			img_width;
	int			img_height;
}				t_texture;

typedef struct map
{
	char		**map;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			is_invalid;
	int			count;
	int			count_tea;
	int			count_teas;
	int			player_x;
	int			player_y;
	bool		is_jumping;
	bool		is_falling;
	bool		goal1;
	bool		goal2;
	bool		goal3;
	t_texture	texture;
}				t_map;

typedef struct s_images
{
	void		*window;
	void		*wall;
	void		*pc1;
	void		*pc2;
	void		*exit_img;
	void		*person1;
	void		*person2;
	void		*collectible;
	void		*empty_space;
	void		*enemy_img;
	void		*object_img;
}				t_images;

typedef struct s_render_flags
{
	bool		*next_pc1_tile_flag;
	bool		*player_anim_state;
}				t_render_flags;

typedef struct s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct s_player_state
{
	t_coord		pos;
	int			jump_remaining;
}				t_player_state;

typedef struct s_jump_result
{
	t_coord		final_pos;
	int			distance;
	bool		reached_exit;
}				t_jump_result;

// texture
struct texture	set_new_texture(void);
struct texture	set_texture(void);
struct texture	next_stage_texture(void);

// move_bonus
void			move_a_bonus(struct map *map);
void			move_d_bonus(struct map *map);
void			move_w_bonus(struct map *map);
void			move_s_bonus(struct map *map);
void			set_obstacle(struct map *map);

// map_check_init
int				check_map_inclument(struct map *map_struct);
void			map_init(struct map *map_struct);

// draw_map
int				draw_map(struct map *map);

// utils
void			search_player(struct map *map, int *x, int *y);

// read_map
int				read_map(struct map *map, char *filename);

// size
int				get_map_height(char *file_name);
int				get_map_width(char *file_name);

// enemy
void			set_enemy(struct map *map);
int				enemy(struct map *map);
void			game_over(struct map *map);

// load_new_map
void			load_new_map(struct map *map_struct);

// gnl
char			*get_next_line(int fd);

// check
int				check_map_invalid(t_map *map);
int				check_map_char(t_map *map);
int				check_map_inclument(t_map *map);
int				check_map_wall(t_map *map);

// free
void			free_map_data(t_map *map);
int				cleanup_and_exit(t_map *map);
void			draw_single_tile(t_map *map, t_images *imgs, t_coord pos,
					t_render_flags *flags);
void			load_game_images(t_map *map, t_images *imgs);
void			destroy_game_images(void *mlx_ptr, t_images *imgs);
void			*load_img_checked(void *mlx_ptr, char *path, int *width,
					int *height);
void			draw_wall_variant_tile(t_map *map, t_images *imgs, t_coord pos,
					bool *next_pc1_flag);
void			render_map_tiles(t_map *map, t_images *imgs,
					bool *player_anim_state);
void			move_player(t_map *map, int dx, int dy);

// move
void			move_d_bonus(t_map *map);
void			move_a_bonus(t_map *map);
void			move_s_bonus(t_map *map);
void			move_w_bonus(t_map *map);

// move3
void			process_goal_achievement(t_map *map);
void			collect_item_at_pos(t_map *map, t_coord pos);
void			update_player_position_on_map(t_map *map, t_coord old_pos,
					t_coord new_pos);
void			handle_horizontal_move(t_map *map, t_coord p_pos, int dx);
bool			process_one_gravity_step(t_map *map, t_coord *current_pos);

// read_map
int				get_map_height_and_width(char *filename, int *height,
					int *width);
char			**allocate_map(t_map *map, int height);
void			count_items(t_map *map);

// enemy
void			execute_enemy_move(t_map *map, t_coord old_pos,
					t_coord new_pos);
bool			try_specific_move(t_map *map, t_coord enemy_pos,
					t_coord next_pos);
bool			try_move_x_axis(t_map *map, t_coord enemy_pos,
					t_coord player_pos);
bool			try_move_y_axis(t_map *map, t_coord enemy_pos,
					t_coord player_pos);
bool			try_move_enemy_in_direction(t_map *map, t_coord enemy_pos,
					t_coord player_pos);
void			game_over(t_map *map);
void			set_enemy(t_map *map);

// bonus
void			move(int keycode, t_map *struct_map);
void			move_bonus(int keycode, t_map *struct_map);
int				apply_gravity(t_map *map);
void			apply_gravity_after_jump(t_map *map);
void			apply_continuous_gravity(t_map *map);
void			collect_on_jump_path(t_map *map, t_coord start_pos,
					int jump_distance);
void			calculate_jump_destination(t_map *map, t_coord start_pos,
					t_jump_result *result);
void			process_goal_achievement(t_map *map);

#endif