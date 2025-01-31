/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:22:18 by yonuma            #+#    #+#             */
/*   Updated: 2024/05/02 20:48:04 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_join2(char *result, char const *s2, size_t size, size_t size2)
{
	size_t	i;

	i = 0;
	while (i < size2)
	{
		result[size + i] = s2[i];
		i++;
	}
	return (result);
}

static char	*ft_join1(char *result, char const *s1, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		result[i] = s1[i];
		i++;
	}
	return (result);
}

static char	*null_strjoin(char const *s)
{
	char	*result;
	size_t	size;

	size = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result = ft_join1(result, s, size);
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	size;
	size_t	size2;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (null_strjoin(s1));
	if (!s1)
		return (null_strjoin(s2));
	size = ft_strlen(s1);
	size2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (size + size2 + 1));
	if (!result)
		return (NULL);
	result = ft_join1(result, s1, size);
	result = ft_join2(result, s2, size, size2);
	result[size + size2] = '\0';
	return (result);
}

// #include <stdio.h>

// int main(void)
// {
// 	char str1[20] = "Hello";
// 	char str2[20] = "world";

// 	printf("%s\n", ft_strjoin(str1, str2));
// }
