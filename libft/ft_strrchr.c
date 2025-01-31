/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:23:04 by yonuma            #+#    #+#             */
/*   Updated: 2024/04/29 12:28:38 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int	len;

	c &= 0xff;
	len = ft_strlen(string);
	if (c == '\0')
		return ((char *)&string[len]);
	while (len >= 0)
	{
		if (string[len] == c)
			return ((char *)&string[len]);
		len--;
	}
	return (NULL);
}
