/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 20:18:39 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/26 21:52:56 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_command(char *str)
{
	char		*cmd;
	char		**command;

	command = ft_split(str, ' ');
	if (!command)
		return (NULL);
	cmd = ft_calloc(6 + ft_strlen(command[0]), sizeof(char));
	if (!cmd)
		return (free_arr(command), NULL);
	ft_strlcat(cmd, "/bin/", 6);
	ft_strlcat(cmd, command[0], 6 + ft_strlen(command[0]));
	free(command[0]);
	command[0] = cmd;
	printf("\n%s\n", command[0]);
	return (command);
}
