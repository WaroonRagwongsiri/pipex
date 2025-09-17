/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:14:21 by marvin            #+#    #+#             */
/*   Updated: 2025/06/19 15:14:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*current;

	len = 0;
	current = lst;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	return (len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	**head;
// 	t_list	*n1;
// 	t_list	*n2;
// 	t_list	*n3;
// 	t_list	*n4;

// 	head = NULL;
// 	n1 = ft_lstnew("abc");
// 	n2 = ft_lstnew("def");
// 	n3 = ft_lstnew("ghi");
// 	n4 = ft_lstnew("jkl");
// 	head = &n4;
// 	ft_lstadd_front(head, n3);
// 	ft_lstadd_front(head, n2);
// 	ft_lstadd_front(head, n1);
// 	printf("len : %d\n", ft_lstsize(*head));
// 	return (0);
// }
