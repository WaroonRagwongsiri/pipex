/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:59:54 by marvin            #+#    #+#             */
/*   Updated: 2025/06/19 16:59:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;
	t_list	*node;

	if (!f || !del)
		return (NULL);
	current = lst;
	new_list = NULL;
	while (current != NULL)
	{
		node = ft_lstnew(f(current->content));
		if (node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		current = current->next;
	}
	return (new_list);
}

// #include <stdio.h>

// void	*set_zero(void *p)
// {
// 	unsigned char	*new_p;

// 	new_p = p;
// 	*new_p = 0;
// 	return (new_p);
// }

// int	main(void)
// {
// 	t_list	*list_1;
// 	t_list	*list_map;

// 	list_1 = NULL;
// 	list_map = NULL;
// 	ft_lstadd_back(&list_1, ft_lstnew(malloc(1)));
// 	ft_lstadd_back(&list_1, ft_lstnew(malloc(1)));
// 	ft_lstadd_back(&list_1, ft_lstnew(malloc(1)));
// 	list_map = ft_lstmap(list_1, set_zero, free);
// 	printf("%p\n", list_map->content);
// 	return (0);
// }
