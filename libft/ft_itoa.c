/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:48:09 by yonuma            #+#    #+#             */
/*   Updated: 2024/04/27 13:14:45 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_digit(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*set_itoa(long int n, int size)
{
	size_t	i;
	char	*result;

	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		result[size - 1] = '-';
		n *= -1;
	}
	else if (n == 0)
		result[i++] = '0';
	while (n != 0)
	{
		result[i++] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*number;
	char	*result;
	int		j;

	size = ft_check_digit(n);
	number = set_itoa(n, size);
	if (!number)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
	{
		free(number);
		return (NULL);
	}
	j = 0;
	while (size > 0)
	{
		result[j++] = number[size - 1];
		size--;
	}
	free(number);
	result[j] = '\0';
	return (result);
}

// #include <limits.h>
// int	main(void)
// {
// 	char	*result;

// 	result = ft_itoa(INT_MIN);
// 	printf("%s\n", result);
// 	free(result);
// 	return (0);
// }
