/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:07:31 by yonuma            #+#    #+#             */
/*   Updated: 2024/04/28 15:59:42 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length_dest;
	size_t	length_src;
	size_t	i;

	if (!dst && size == 0)
		return (ft_strlen(src));
	length_dest = ft_strlen(dst);
	length_src = ft_strlen(src);
	i = 0;
	if (size <= length_dest)
		return (size + length_src);
	while (src[i] != '\0' && i < size - length_dest - 1)
	{
		dst[length_dest + i] = src[i];
		i++;
	}
	dst[length_dest + i] = '\0';
	return (length_dest + length_src);
}

// #include <stdio.h>
// #include <string.h>

// int main (void)
// {
// 	printf("ft : %lu\n",ft_strlcat(NULL, "42tokyo", 0));
// //	printf("%lu\n",strlcat(NULL, "42tokyo", 0));
// }