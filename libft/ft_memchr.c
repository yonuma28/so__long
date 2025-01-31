/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:51:14 by yonuma            #+#    #+#             */
/*   Updated: 2024/04/28 18:25:36 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str1;
	unsigned char		str2;
	size_t				i;

	str1 = s;
	str2 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str1[i] == str2)
			return ((void *)&str1[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[] = "Hello, world!";
// 	char	*result;

// 	// テストケース1: 文字 'o' を検索する
// 	result = ft_memchr(str, 'o', sizeof(str));
// 	assert(result != NULL);
// 	printf("Character 'o' found at position: %ld\n", result - str);
// 	// テストケース2: 文字 'z' を検索する (存在しない場合)
// 	result = ft_memchr(str, 'z', sizeof(str));
// 	assert(result == NULL);
// 	printf("Character 'z' not found.\n");
// 	return (0);
// }
