/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 00:17:47 by yonuma            #+#    #+#             */
/*   Updated: 2024/04/27 13:14:39 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	if (ft_isprint('d'))
// 		puts("d");
// 	if (ft_isprint('l'))
// 		puts("l");
// 	if (isprint('d'))
// 		puts("d");
// 	if (isprint('l'))
// 		puts("l");
// }