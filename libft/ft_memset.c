/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:40:09 by yonuma            #+#    #+#             */
/*   Updated: 2024/04/29 12:56:05 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		*str = value;
		str++;
		i++;
	}
	return ((void *)ptr);
}

// int main(void)
// {
//         char str[] = "0123456789";

//         memset(str+2, '*', 5);

//         printf("%s\n",str);

//         return (0);
// }