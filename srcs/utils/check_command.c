/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:44:56 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/02 16:00:17 by waragwon         ###   ########.fr       */
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
		cmd = parse_command(argv[i], env);
		if (!cmd)
			return (0);
		if (!cmd[0])
			return (free_arr(cmd), 0);
	}
	return (1);
}
