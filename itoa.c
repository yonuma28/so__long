/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:17:57 by yonuma            #+#    #+#             */
/*   Updated: 2025/01/24 17:21:12 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	itoa(int num, char *str)
{
	int		i;
	int		isNegative;
	int		start;
	int		end;
	char	temp;

	i = 0;
	isNegative = 0;
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return ;
	}
	if (num < 0)
	{
		isNegative = 1;
		num = -num;
	}
	while (num != 0)
	{
		str[i++] = num % 10 + '0';
		num = num / 10;
	}
	if (isNegative)
	{
		str[i++] = '-';
	}
	str[i] = '\0';
	start = 0;
	end = i - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
