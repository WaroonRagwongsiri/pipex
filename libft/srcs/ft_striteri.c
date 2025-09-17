/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.C                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:35:48 by marvin            #+#    #+#             */
/*   Updated: 2025/06/18 17:35:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>

// void	print_char(unsigned int index, char *s)
// {
// 	printf("%d : %c\n", index, s[0]);
// }

// int	main(void)
// {
// 	char	c[] = "abcdef";
// 	ft_striteri(c, print_char);
// 	return (0);
// }
