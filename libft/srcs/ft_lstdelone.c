/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:25:37 by marvin            #+#    #+#             */
/*   Updated: 2025/06/19 16:25:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || !del)
		return ;
	if (lst->content != NULL)
		del(lst->content);
	free(lst);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*l;

// 	l = NULL;
// 	ft_lstadd_back(&l, ft_lstnew(malloc(1)));
// 	ft_lstdelone(l, free);
// 	return (0);
// }
