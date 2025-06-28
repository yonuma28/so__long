/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:58:04 by yonuma            #+#    #+#             */
/*   Updated: 2025/06/28 12:58:09 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	process_goal_achievement(t_map *map)
{
	printf("GOAL!!\nresult: %d\n", map->count);
	cleanup_and_exit(map);
}
