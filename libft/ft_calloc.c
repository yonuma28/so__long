/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:17:59 by yonuma            #+#    #+#             */
/*   Updated: 2024/04/28 14:53:28 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (count != 0 && size != 0)
	{
		if (SIZE_MAX / count < size)
			return (NULL);
	}
	result = (void *)malloc(count * size);
	if (!result)
		return (NULL);
	ft_memset(result, 0, count * size);
	return (result);
}

// int main(void)
// {
// 	ft_calloc(10, 4);
// }