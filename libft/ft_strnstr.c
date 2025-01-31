/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:55:45 by yonuma            #+#    #+#             */
/*   Updated: 2024/04/28 16:00:49 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] != '\0' && i + j < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	const char	*big = NULL;
// 	const char	*little = "world";
// 	size_t		len;
// 	char		*result_ft;
// 	char		*result_str;

// 	len = 3;
// 	// ft_strnstrを使ってサブストリングを探す
// 	result_ft = ft_strnstr(big, little, len);
// 	if (result_ft != NULL)
// 	{
// 		printf("ft_strnstr: Substring found at position: %ld\n", result_ft
// 			- big);
// 	}
// 	else
// 	{
// 		printf("ft_strnstr: Substring not found\n");
// 	}
// 	// strnstrを使ってサブストリングを探す
// 	result_str = strnstr(big, little, len);
// 	if (result_str != NULL)
// 	{
// 		printf("strnstr   : Substring found at position: %ld\n", result_str
// 			- big);
// 	}
// 	else
// 	{
// 		printf("strnstr   : Substring not found\n");
// 	}
// 	return (0);
// }
