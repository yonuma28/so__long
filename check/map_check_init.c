/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:54:11 by yonuma            #+#    #+#             */
/*   Updated: 2025/06/13 09:30:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_init(struct map *map_struct)
{
	map_struct->map = NULL;
	map_struct->width = 0;
	map_struct->height = 0;
	map_struct->is_invalid = 0;
	map_struct->count = 0;
	map_struct->count_tea = 0;
	map_struct->count_teas = 0;
	map_struct->goal1 = false;
	map_struct->goal2 = false;
	map_struct->goal3 = false;
}
