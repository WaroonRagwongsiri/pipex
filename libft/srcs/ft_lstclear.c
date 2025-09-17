/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:37:35 by marvin            #+#    #+#             */
/*   Updated: 2025/06/19 16:37:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	current = *lst;
	if (current == NULL)
	{
		*lst = NULL;
		return ;
	}
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		if (tmp->content != NULL)
			del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	**head;
// 	t_list	*lst;

// 	head = &lst;
// 	lst = NULL;
// 	ft_lstadd_back(&lst, ft_lstnew(malloc(1)));
// 	printf("%p\n", *head);
// 	ft_lstadd_back(&lst, ft_lstnew(malloc(1)));
// 	ft_lstadd_back(&lst, ft_lstnew(malloc(1)));
// 	ft_lstadd_back(&lst, ft_lstnew(malloc(1)));
// 	ft_lstclear(head, free);
// 	printf("%p\n", *head);
// 	return (0);
// }
