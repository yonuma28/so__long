/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_new_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:18:38 by yonuma            #+#    #+#             */
/*   Updated: 2025/06/28 12:41:10 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

void	load_new_map(struct map *map_struct)
{
	free_map_data(map_struct);
	map_struct->map = (char **)malloc(sizeof(char *) * 10);
	if (map_struct->map == NULL)
	{
		cleanup_and_exit(map_struct);
	}
	map_struct->map[0] = ft_strdup("111111111111111111111111111");
	map_struct->map[1] = ft_strdup("100000000000000000000000001");
	map_struct->map[2] = ft_strdup("10000C000000000000000000001");
	map_struct->map[3] = ft_strdup("100000000000000000000000001");
	map_struct->map[4] = ft_strdup("100000000001110000000100001");
	map_struct->map[5] = ft_strdup("100111000000000000000010001");
	map_struct->map[6] = ft_strdup("100000000000000000000100001");
	map_struct->map[7] = ft_strdup("100000111100000000000010E01");
	map_struct->map[8] = ft_strdup("1P0000000000000000000010001");
	map_struct->map[9] = ft_strdup("111111111111111111111111111");
	map_struct->height = 10;
	map_struct->width = 27;
}
