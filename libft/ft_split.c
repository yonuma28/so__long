/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:05:01 by yonuma            #+#    #+#             */
/*   Updated: 2024/05/07 19:23:01 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_words(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str)
	{
		if (*str != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*str == c)
			j = 0;
		str++;
	}
	return (i);
}

static int	get_next_index(char const *s, char c, int i)
{
	int	j;
	int	len;

	len = ft_strlen(s);
	j = 0;
	while ((i + j) < len && s[i + j] != '\0' && s[i + j] != c)
		j++;
	return (j);
}

static void	free_result(char **str, int n)
{
	while (n--)
		free(str[n]);
	free(str);
}

char	**make_split(char **result, char const *s, char c)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		j = get_next_index(s, c, i);
		if (j > 0)
		{
			result[k] = ft_strndup(&s[i], j);
			if (!result[k])
			{
				free_result(result, k);
				return (NULL);
			}
			k++;
			i += j;
		}
		i++;
	}
	result[k] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	return (make_split(result, s, c));
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str[] = "hello!";
// 	char **result = ft_split(str, ' ');

// 	if (result)
// 	{
// 		int i = 0;
// 		while (result[i])
// 		{
// 			printf("%s\n", result[i]);
// 			i++;
// 		}
// 		printf("%s\n", result[i]);
// 		free(result);
// 	}
// 	return (0);
// }