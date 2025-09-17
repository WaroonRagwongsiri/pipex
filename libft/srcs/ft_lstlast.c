/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:24:54 by marvin            #+#    #+#             */
/*   Updated: 2025/06/19 15:24:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	if (current == NULL)
		return (NULL);
	while (current->next != NULL)
		current = current->next;
	return (current);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*l1;
// 	t_list	*l2;

// 	l1 = NULL;
// 	l2 = NULL;
// 	ft_lstadd_back(&l1, ft_lstnew((void *) 1));
// 	ft_lstadd_back(&l1, ft_lstnew((void *) 2));
// 	ft_lstadd_back(&l2, ft_lstnew((void *) 3));
// 	ft_lstadd_back(&l2, ft_lstnew((void *) 4));
// 	ft_lstadd_back(&l1, l2);
// 	printf("%p\n", l1->next->next->next->content);
// 	return (0);
// }
