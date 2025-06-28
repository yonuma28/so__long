/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:42:36 by yonuma            #+#    #+#             */
/*   Updated: 2025/06/28 13:19:32 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

void	*load_img_checked(void *mlx_ptr, char *path, int *width, int *height)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx_ptr, path, width, height);
	if (img == NULL)
	{
		ft_printf("Error: Failed to load image: %s\n", path);
		exit(EXIT_FAILURE);
	}
	return (img);
}

void	update_textures_for_stage(t_map *map, bool *stage_loaded_flag)
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

void	draw_wall_variant_tile(t_map *map, t_images *imgs, t_coord pos,
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

void	display_game_hud(t_map *map)
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
