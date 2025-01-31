/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:28:44 by marvin            #+#    #+#             */
/*   Updated: 2024/04/28 16:06:49 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		*str = 0;
		i++;
		str++;
	}
}

// int main(void)
// {
//     char str0[10] = "daaaaaaaaa";
//     char str1[10] = "daaaaaaaaa";

//     bzero(str0, 5);
//     printf("str0: %s\n", str0);
//     ft_bzero(str1, 5);
//     printf("str1: %s\n", str1);

//     return (0);
// }