/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:42:36 by yonuma            #+#    #+#             */
/*   Updated: 2025/01/31 18:00:06 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

static void	*load_img_checked(void *mlx_ptr, char *path, int *width,
		int *height)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx_ptr, path, width, height);
	if (img == NULL)
	{
		fprintf(stderr, "Error: Failed to load image: %s\n", path);
		exit(EXIT_FAILURE);
	}
	return (img);
}

static void	load_game_images(t_map *map, t_images *imgs)
{
	imgs->window = load_img_checked(map->mlx, (char *)map->texture.img_window,
			&map->texture.img_width, &map->texture.img_height);
	imgs->wall = load_img_checked(map->mlx, (char *)map->texture.img_wall,
			&map->texture.img_width, &map->texture.img_height);
	imgs->pc1 = load_img_checked(map->mlx, (char *)map->texture.img_PC1,
			&map->texture.img_width, &map->texture.img_height);
	imgs->pc2 = load_img_checked(map->mlx, (char *)map->texture.img_PC2,
			&map->texture.img_width, &map->texture.img_height);
	imgs->exit_img = load_img_checked(map->mlx, (char *)map->texture.img_E,
			&map->texture.img_width, &map->texture.img_height);
	imgs->person1 = load_img_checked(map->mlx, (char *)map->texture.img_Person1,
			&map->texture.img_width, &map->texture.img_height);
	imgs->person2 = load_img_checked(map->mlx, (char *)map->texture.img_Person2,
			&map->texture.img_width, &map->texture.img_height);
	imgs->collectible = load_img_checked(map->mlx, (char *)map->texture.img_tea,
			&map->texture.img_width, &map->texture.img_height);
	imgs->empty_space = load_img_checked(map->mlx, (char *)map->texture.img_0,
			&map->texture.img_width, &map->texture.img_height);
	imgs->enemy_img = load_img_checked(map->mlx, (char *)map->texture.enemy,
			&map->texture.img_width, &map->texture.img_height);
	imgs->object_img = load_img_checked(map->mlx, (char *)map->texture.object,
			&map->texture.img_width, &map->texture.img_height);
}

static void	destroy_game_images(void *mlx_ptr, t_images *imgs)
{
	mlx_destroy_image(mlx_ptr, imgs->window);
	mlx_destroy_image(mlx_ptr, imgs->wall);
	mlx_destroy_image(mlx_ptr, imgs->pc1);
	mlx_destroy_image(mlx_ptr, imgs->pc2);
	mlx_destroy_image(mlx_ptr, imgs->exit_img);
	mlx_destroy_image(mlx_ptr, imgs->person1);
	mlx_destroy_image(mlx_ptr, imgs->person2);
	mlx_destroy_image(mlx_ptr, imgs->collectible);
	mlx_destroy_image(mlx_ptr, imgs->empty_space);
	mlx_destroy_image(mlx_ptr, imgs->enemy_img);
	mlx_destroy_image(mlx_ptr, imgs->object_img);
}

static void	update_textures_for_stage(t_map *map, bool *stage_loaded_flag)
{
	if (!map->goal1)
		map->texture = set_texture();
	else if (map->goal1 && !map->goal2)
		map->texture = set_new_texture();
	else if (map->goal1 && map->goal2 && !(*stage_loaded_flag))
	{
		map->texture = next_stage_texture();
		load_new_map(map);
		*stage_loaded_flag = true;
	}
}

static void	draw_wall_variant_tile(t_map *map, t_images *imgs, t_coord pos,
		bool *next_pc1_flag)
{
	void	*img_to_draw;

	if (pos.x == 0 || pos.x == map->width - 1)
		img_to_draw = imgs->wall;
	else if (pos.y == 0)
		img_to_draw = imgs->window;
	else if (pos.y == map->height - 1)
		img_to_draw = imgs->pc2;
	else if (pos.y == 1)
		img_to_draw = imgs->pc1;
	else
	{
		if (*next_pc1_flag)
			img_to_draw = imgs->pc1;
		else
			img_to_draw = imgs->pc2;
		*next_pc1_flag = !(*next_pc1_flag);
	}
	mlx_put_image_to_window(map->mlx, map->win, img_to_draw, pos.x
		* map->texture.img_width, pos.y * map->texture.img_height);
}

static void	draw_player_tile_animated(t_map *map, t_images *imgs, t_coord pos,
		bool *anim_state)
{
	void	*img_to_draw;

	if (*anim_state)
		img_to_draw = imgs->person1;
	else
		img_to_draw = imgs->person2;
	*anim_state = !(*anim_state);
	mlx_put_image_to_window(map->mlx, map->win, img_to_draw, pos.x
		* map->texture.img_width, pos.y * map->texture.img_height);
}

static void	draw_single_tile(t_map *map, t_images *imgs, t_coord pos,
		t_render_flags *flags)
{
	char	tile_char;

	tile_char = map->map[pos.y][pos.x];
	if (tile_char == '1')
		draw_wall_variant_tile(map, imgs, pos, flags->next_pc1_tile_flag);
	else if (tile_char == 'E')
		mlx_put_image_to_window(map->mlx, map->win, imgs->exit_img, pos.x
			* map->texture.img_width, pos.y * map->texture.img_height);
	else if (tile_char == 'P')
		draw_player_tile_animated(map, imgs, pos, flags->player_anim_state);
	else if (tile_char == 'C')
		mlx_put_image_to_window(map->mlx, map->win, imgs->collectible, pos.x
			* map->texture.img_width, pos.y * map->texture.img_height);
	else if (tile_char == '0')
		mlx_put_image_to_window(map->mlx, map->win, imgs->empty_space, pos.x
			* map->texture.img_width, pos.y * map->texture.img_height);
	else if (tile_char == 'O')
		mlx_put_image_to_window(map->mlx, map->win, imgs->object_img, pos.x
			* map->texture.img_width, pos.y * map->texture.img_height);
	else if (tile_char == 'N')
		mlx_put_image_to_window(map->mlx, map->win, imgs->enemy_img, pos.x
			* map->texture.img_width, pos.y * map->texture.img_height);
}

static void	render_map_tiles(t_map *map, t_images *imgs,
		bool *player_anim_state)
{
	t_coord			pos;
	bool			next_pc1_tile_local;
	t_render_flags	flags;

	next_pc1_tile_local = true;
	flags.next_pc1_tile_flag = &next_pc1_tile_local;
	flags.player_anim_state = player_anim_state;
	pos.y = 0;
	while (pos.y < map->height)
	{
		pos.x = 0;
		while (pos.x < map->width)
		{
			draw_single_tile(map, imgs, pos, &flags);
			pos.x++;
		}
		pos.y++;
	}
}

static void	display_game_hud(t_map *map)
{
	char	step_buffer[50];
	int		dx;
	int		dy;

	sprintf(step_buffer, "%d", map->count);
	dx = 0;
	while (dx <= 1)
	{
		dy = 0;
		while (dy <= 1)
		{
			mlx_string_put(map->mlx, map->win, 10 + dx, 10 + dy, 0xFF1493,
				"count: ");
			mlx_string_put(map->mlx, map->win, 100 + dx, 10 + dy, 0xFF1493,
				step_buffer);
			dy++;
		}
		dx++;
	}
}

int	draw_map(t_map *map)
{
	t_images	images;
	static bool	new_stage_loaded = false;
	static bool	player_animation = true;

	update_textures_for_stage(map, &new_stage_loaded);
	load_game_images(map, &images);
	render_map_tiles(map, &images, &player_animation);
	display_game_hud(map);
	destroy_game_images(map->mlx, &images);
	return (0);
}
