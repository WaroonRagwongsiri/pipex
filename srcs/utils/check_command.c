/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:44:56 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/02 16:33:53 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_command(int argc, char **argv, char **env)
{
	char	**cmd;
	int		i;

	i = -1;
	while (++i < (argc - 3))
	{
		cmd = parse_command(argv[i + 2], env);
		if (!cmd)
			return (0);
		free_arr(cmd);
	}
	return (1);
}

int	check_command_heredoc(int argc, char **argv, char **env)
{
	char	**cmd;
	int		i;

	i = -1;
	while (++i < (argc - 4))
	{
		cmd = parse_command(argv[i + 3], env);
		if (!cmd)
			return (0);
		free_arr(cmd);
	}
	return (1);
}
