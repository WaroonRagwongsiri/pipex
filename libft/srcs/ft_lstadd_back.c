/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:34:18 by marvin            #+#    #+#             */
/*   Updated: 2025/06/19 15:34:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!new || !lst)
		return ;
	current = *lst;
	if (current == NULL)
	{
		*lst = new;
		return ;
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*l =  NULL;
// 	t_list	*l2 =  NULL;
// 	ft_lstadd_back(&l, ft_lstnew((void*)1));
// 	ft_lstadd_back(&l, ft_lstnew((void*)2));
// 	ft_lstadd_back(&l2, ft_lstnew((void*)3));
// 	ft_lstadd_back(&l2, ft_lstnew((void*)4));
// 	ft_lstadd_back(&l, l2);
// 	printf("l %d\n", (l->content == (void*)1));
// 	printf("l2 %d\n", (((t_list *)
// 	(l->next))->content == (void*)2));
// 	printf("l3 %d\n", (((t_list *)(((t_list *)
// 	(l->next))->next))->content == (void*)3));
// 	printf("l4 %d\n", (((t_list *)((t_list *)
// 	(((t_list *)(l->next))->next))->next)->content == (void*)4));
// 	printf("next %d\n", (((t_list *)((t_list *)
// 	(((t_list *)(l->next))->next))->next)->next == 0));
// 	return (0);
// }
