/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:01:58 by marvin            #+#    #+#             */
/*   Updated: 2024/04/28 16:04:10 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*result;

	result = NULL;
	while (lst)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		new->content = f(lst->content);
		if (!new->content)
		{
			free(new);
			ft_lstclear(&result, del);
			return (NULL);
		}
		new->next = NULL;
		ft_lstadd_back(&result, new);
		lst = lst->next;
	}
	return (result);
}
