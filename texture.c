/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:10:04 by yonuma            #+#    #+#             */
/*   Updated: 2025/01/25 16:23:04 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

struct texture	next_stage_texture(void)
{
	struct texture	texture;

	texture.img_window = "image/sora.xpm";
	texture.img_wall = "image/sora.xpm";
	texture.img_PC1 = "image/ground.xpm";
	texture.img_PC2 = "image/ground.xpm";
	texture.img_0 = "image/sora.xpm";
	texture.img_E = "image/kaidan.xpm";
	texture.img_Person1 = "image/hito_soto.xpm";
	texture.img_Person2 = "image/hito_soto2.xpm";
	texture.img_tea = "image/tea_soto.xpm";
	texture.object = "image/hashigo_1_.xpm";
	texture.enemy = "image/akamite_dot.xpm";
	texture.character = "image/character.xpm";

	return (texture);
}

struct texture	set_new_texture(void)
{
	struct texture	texture;

	texture.img_window = "image/window_ura.xpm";
	texture.img_wall = "image/wall.xpm";
	texture.img_PC1 = "image/PC1_ura1.xpm";
	texture.img_PC2 = "image/PC2_ura1.xpm";
	texture.img_0 = "image/yuka_ura.xpm";
	texture.img_E = "image/kaidan.xpm";
	texture.img_Person1 = "image/Person1_ura.xpm";
	texture.img_Person2 = "image/hito2_ura.xpm";
	texture.img_tea = "image/tea.xpm";
	texture.object = "image/object.xpm";
	texture.enemy = "image/akamite_dot.xpm";
	texture.character = "image/character.xpm";

	return (texture);
}

struct texture	set_texture(void)
{
	struct texture	texture;

	texture.img_window = "image/window.xpm";
	texture.img_wall = "image/wall.xpm";
	texture.img_PC1 = "image/PC1.xpm";
	texture.img_PC2 = "image/PC2.xpm";
	texture.img_0 = "image/collidor.xpm";
	texture.img_E = "image/kaidan.xpm";
	texture.img_Person1 = "image/person1.xpm";
	texture.img_Person2 = "image/person2.xpm";
	texture.img_tea = "image/tea.xpm";
	texture.object = "image/object.xpm";
	texture.enemy = "image/akamite_dot.xpm";
	texture.character = "image/character.xpm";

	return (texture);
}
