/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:26:54 by marvin            #+#    #+#             */
/*   Updated: 2025/06/18 18:26:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = (*lst);
	*lst = new;
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	**head;
// 	t_list	*n1;
// 	t_list	*n2;
// 	t_list	*n3;

// 	n1 = ft_lstnew("abc");
// 	n2 = ft_lstnew("def");
// 	n3 = ft_lstnew("ghi");
// 	n1->next = n2;
// 	head = &n1;
// 	ft_lstadd_front(head, n3);
// 	printf("%s\n", ((char *) (*head)->content));
// }
