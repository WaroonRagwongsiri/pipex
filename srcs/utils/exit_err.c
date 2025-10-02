/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:42:51 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/02 15:58:04 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_pipes(int pipes[99][2], int io_fd[2], int process_num)
{
	close_pipes(pipes, io_fd, process_num);
	perror("Error creating pipes");
	exit(EXIT_FAILURE);
}

void	exit_fork(int pipes[99][2], int io_fd[2], int process_num)
{
	close_pipes(pipes, io_fd, process_num);
	perror("Error fork");
	exit(EXIT_FAILURE);
}

void	close_io_error(int argc, char **argv, char **env, int io_fd[2])
{
	if (io_fd[0] == -1 || io_fd[1] == -1)
	{
		if (io_fd[0] == -1)
		{
			perror("Error opening input file");
			if (io_fd[1] > 0)
				close(io_fd[1]);
		}
		if (io_fd[1] == -1)
		{
			perror("Error opening output file");
			if (io_fd[0] > 0)
				close(io_fd[0]);
		}
		exit(EXIT_FAILURE);
	}
	if (!check_command(argc, argv, env))
	{
		if (io_fd[1] > 0)
			close(io_fd[1]);
		if (io_fd[0] > 0)
			close(io_fd[0]);
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
}
