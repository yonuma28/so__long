/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:02:47 by marvin            #+#    #+#             */
/*   Updated: 2025/06/14 18:02:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_game_images(t_map *map, t_images *imgs)
{
	imgs->window = load_img_checked(map->mlx, (char *)map->texture.img_window,
			&map->texture.img_width, &map->texture.img_height);
	imgs->wall = load_img_checked(map->mlx, (char *)map->texture.img_wall,
			&map->texture.img_width, &map->texture.img_height);
	imgs->pc1 = load_img_checked(map->mlx, (char *)map->texture.img_pc1,
			&map->texture.img_width, &map->texture.img_height);
	imgs->pc2 = load_img_checked(map->mlx, (char *)map->texture.img_pc2,
			&map->texture.img_width, &map->texture.img_height);
	imgs->exit_img = load_img_checked(map->mlx, (char *)map->texture.img_e,
			&map->texture.img_width, &map->texture.img_height);
	imgs->person1 = load_img_checked(map->mlx, (char *)map->texture.img_person1,
			&map->texture.img_width, &map->texture.img_height);
	imgs->person2 = load_img_checked(map->mlx, (char *)map->texture.img_person2,
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

void	destroy_game_images(void *mlx_ptr, t_images *imgs)
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

void	draw_player_tile_animated(t_map *map, t_images *imgs, t_coord pos,
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

void	draw_single_tile(t_map *map, t_images *imgs, t_coord pos,
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

void	render_map_tiles(t_map *map, t_images *imgs, bool *player_anim_state)
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
