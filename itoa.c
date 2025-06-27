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

static void	reverse_str(char *str, int len)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = len - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

static int	itoa_zero(char *str, int n, int i)
{
	if (n == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (0);
	}
	return (1);
}

void	itoa(int num, char *str)
{
	int	i;
	int	is_negative;
	int	n;

	i = 0;
	is_negative = 0;
	n = num;
	if (itoa_zero(str, n, i) == 0)
		return ;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	while (n != 0)
	{
		str[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (is_negative)
		str[i++] = '-';
	str[i] = '\0';
	reverse_str(str, i);
}
