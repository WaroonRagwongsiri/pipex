/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:30:46 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/28 12:43:12 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int argc, char **argv, char **env, int io_fd[2])
{
	int		pid[100];
	int		pipes[99][2];
	char	**cmd;
	int		i;

	if (!open_pipes(pipes, (argc - 3)))
		exit_pipes(pipes, io_fd, (argc - 3));
	i = 0;
	while (i < (argc - 3))
	{
		pid[i] = fork();
		if (pid[i] == -1)
			exit_fork(pipes, io_fd, (argc - 3));
		if (pid[i] == 0)
		{
			dup_process(i, pipes, io_fd, (argc - 3));
			close_pipes(pipes, io_fd, (argc - 3));
			cmd = parse_command(argv[i + 2], env);
			execve(cmd[0], cmd, env);
			free_arr(cmd);
			perror("Error at exec");
			return (errno);
		}
		i++;
	}
	close_pipes(pipes, io_fd, (argc - 3));
	i = 0;
	while (i < (argc - 3))
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
	return (1);
}
