/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:15:16 by marvin            #+#    #+#             */
/*   Updated: 2025/06/15 19:15:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	if (!s)
		return (NULL);
	ft_memset(s, 0, n);
	return (s);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	test[] = {1,2,3,4,5};
// 	int	i = 0;
// 	ft_bzero(test, 3);
// 	while (i < 5)
// 	{
// 		printf("%d", test[i]);
// 		i++;
// 	}
// 	return (0);
// }
