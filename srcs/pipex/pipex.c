/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:30:46 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/02 15:39:04 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex infile cmd cmd outfile
void	pipex(int argc, char **argv, char **env, int io_fd[2])
{
	int		pid[100];
	int		pipes[99][2];
	int		i;

	if (!open_pipes(pipes, (argc - 3)))
		exit_pipes(pipes, io_fd, (argc - 3));
	i = -1;
	while (++i < (argc - 3))
	{
		pid[i] = fork();
		if (pid[i] == -1)
			exit_fork(pipes, io_fd, (argc - 3));
		if (pid[i] == 0)
		{
			dup_process(i, pipes, io_fd, (argc - 3));
			close_pipes(pipes, io_fd, (argc - 3));
			exec_cmd((i + 2), argv, env);
		}
	}
	close_pipes(pipes, io_fd, (argc - 3));
	i = -1;
	while (++i < (argc - 3))
		waitpid(pid[i], NULL, 0);
}

void	exec_cmd(int index_cmd, char **argv, char **env)
{
	char	**cmd;

	cmd = parse_command(argv[index_cmd], env);
	if (!cmd)
	{
		perror("Error at exec");
		exit(EXIT_FAILURE);
	}
	execve(cmd[0], cmd, env);
	free_arr(cmd);
	perror("Error at exec");
	exit(EXIT_FAILURE);
}
