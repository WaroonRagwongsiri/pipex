/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:28:00 by marvin            #+#    #+#             */
/*   Updated: 2025/06/17 18:28:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*new_ptr;
	size_t			i;

	i = 0;
	new_ptr = NULL;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if ((nmemb * size) > 2147483647
		|| nmemb > 2147483647
		|| size > 2147483647)
		return (NULL);
	new_ptr = malloc(nmemb * size);
	if (new_ptr == NULL)
		return (NULL);
	while (i < (size * nmemb))
	{
		new_ptr[i] = 0;
		i++;
	}
	return (new_ptr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	// int	*arr;
// 	unsigned long long n = -5;
// 	printf("%llu", (n));
// 	// arr = ft_calloc(0, -5);
// 	// for (size_t i = 0; i < 4; i++)
// 	// {
// 	// 	printf("%ld : %d\n", i, arr[i]);
// 	// }
// 	// free(arr);
// 	return (0);
// }
