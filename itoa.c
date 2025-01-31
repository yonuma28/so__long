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

# include "so_long.h"

static int	get_num_len(int n)
{
	int len = 0;

	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void itoa(int num, char *str)
{
    int i = 0;
    int isNegative = 0;

    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return;
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
    int start = 0;
    int end = i - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
