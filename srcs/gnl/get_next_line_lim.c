/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_lim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 22:45:18 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/28 14:38:44 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_next_line_lim(int fd, char *lim)
{
	static char	*readed = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readed = update_readed(fd, readed);
	if (!readed)
		return (NULL);
	line = get_line(readed);
	readed = trim_read(readed);
	if (!line)
		return (NULL);
	if (ft_strncmp(line, lim, ft_strlen(lim) + 1) == 0)
		return (free(readed), free(line), NULL);
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}
