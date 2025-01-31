/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:57:14 by yonuma            #+#    #+#             */
/*   Updated: 2024/04/28 15:56:29 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	if (ft_isascii('d'))
// 		puts("d");
// 	if (ft_isascii('l'))
// 		puts("l");
// 	if (isascii('d'))
// 		puts("d");
// 	if (isascii('l'))
// 		puts("l");
// }