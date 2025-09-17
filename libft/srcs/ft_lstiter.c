/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:50:41 by marvin            #+#    #+#             */
/*   Updated: 2025/06/19 16:50:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	current = lst;
	if (!f)
		return ;
	while (current != NULL)
	{
		f(current->content);
		current = current->next;
	}
}

// #include <stdio.h>

// void	print_p(void *p)
// {
// 	printf("%p\n", p);
// }

// int	main(void)
// {
// 	t_list	*l;

// 	l = NULL;
// 	ft_lstadd_back(&l, ft_lstnew(malloc(1)));
// 	ft_lstadd_back(&l, ft_lstnew(malloc(1)));
// 	ft_lstadd_back(&l, ft_lstnew(malloc(1)));
// 	ft_lstadd_back(&l, ft_lstnew(malloc(1)));
// 	ft_lstiter(l, print_p);
// 	ft_lstclear(&l, free);
// 	return (0);
// }
