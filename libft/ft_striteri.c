/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:45:36 by marvin            #+#    #+#             */
/*   Updated: 2024/05/02 11:02:56 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	n;

	i = 0;
	if (!s)
		return ;
	n = ft_strlen(s);
	while (i < n)
	{
		(*f)(i, s);
		i++;
		s++;
	}
}
