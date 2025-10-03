/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 20:18:39 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/03 15:25:16 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_command(char *str, char **env)
{
	char		*cmd;
	char		**command;

	if (count_word_split(str, ' ') == 0)
		return (NULL);
	command = ft_split(str, ' ');
	if (!command || !env)
		return (NULL);
	cmd = find_command_path(command[0], env);
	if (!cmd)
		return (free_arr(command), NULL);
	free(command[0]);
	command[0] = cmd;
	return (command);
}

char	*find_command_path(char *cmd, char **env)
{
	char	*path;
	char	**all_path;

	path = NULL;
	while (*env)
	{
		if (ft_strnstr(*env, "PATH=", 5))
			path = *env;
		env++;
	}
	if (!path)
		return (NULL);
	all_path = ft_split(&path[5], ':');
	if (!all_path)
		return (NULL);
	return (find_usable_path(cmd, all_path));
}

char	*find_usable_path(char *cmd, char **all_path)
{
	int		i;
	char	*cmd_path;

	i = 0;
	while (all_path[i])
	{
		cmd_path = ft_calloc(ft_strlen(cmd) + ft_strlen(all_path[i]) + 2, 1);
		if (!cmd_path)
			return (free_arr(all_path), NULL);
		ft_strlcat(cmd_path, all_path[i], ft_strlen(all_path[i]) + 1);
		ft_strlcat(cmd_path, "/", ft_strlen(all_path[i]) + 2);
		ft_strlcat(cmd_path, cmd, ft_strlen(cmd) + ft_strlen(all_path[i]) + 2);
		if (access(cmd_path, F_OK | X_OK) != -1)
			return (free_arr(all_path), cmd_path);
		free(cmd_path);
		i++;
	}
	return (free_arr(all_path), NULL);
}
