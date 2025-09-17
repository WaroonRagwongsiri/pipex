/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:25:49 by marvin            #+#    #+#             */
/*   Updated: 2025/06/15 19:25:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*new_dest;
	unsigned const char	*new_src;

	i = 0;
	if (!dest || !src)
		return (dest);
	new_dest = dest;
	new_src = src;
	while (i < n)
	{
		new_dest[i] = new_src[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	src1[] = "abcdef";
// 	char	dest1[] = "dest";
// 	char	src2[] = "abcdef";
// 	char	dest2[] = "dest";
// 	memcpy(dest1, src1, 5);
// 	ft_memcpy(dest2, src2, 5);
// 	printf("real : %s\n", dest1);
// 	printf("fake : %s\n", dest2);
// 	return (0);
// }
