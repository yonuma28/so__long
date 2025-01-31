/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:04:15 by marvin            #+#    #+#             */
/*   Updated: 2024/04/28 16:06:37 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c
			&& c <= '9'))
		return (1);
	return (0);
}

// int main(void)
// {
//     if (isalnum('a'))
//         puts("a");
//     if (isalnum('4'))
//         puts("4");
//     if (isalnum('+'))
//         puts("+");
//     if (ft_isalnum('a'))
//         puts("a");
//     if (isalnum('4'))
//         puts("4");
//     if (ft_isalnum('+'))
//         puts("+");
// }