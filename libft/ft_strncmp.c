/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:40:00 by yonuma            #+#    #+#             */
/*   Updated: 2024/04/27 13:16:34 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	char *str = "libft-test-tokyo";
// 	char *cmp = "libft-test-tokyo";
// 	char *cmp2 = calloc(10, 1);
// 	strlcpy(cmp2, "libft", 10);
// 	int	len = strlen(str);
// 	cmp2[5] = -42;
// 	printf("%d\n", strncmp(str, cmp2, len));
// 	printf("%d", ft_strncmp(str, cmp2, len));
// }