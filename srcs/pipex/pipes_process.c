/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:26:28 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/28 12:32:25 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_pipes(int pipes[99][2], int process_num)
{
	int	i;

	i = 0;
	while (i < process_num - 1)
	{
		if (pipe(pipes[i]) == -1)
			return (0);
		i++;
	}
	return (1);
}

void	close_pipes(int pipes[99][2], int io_fd[2], int process_num)
{
	int	i;

	i = 0;
	while (i < process_num - 1)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
	close(io_fd[0]);
	close(io_fd[1]);
}

void	dup_process(int index_process, int pipes[99][2], int io_fd[2], int process_num)
{
	if (index_process == 0)
	{
		dup2(io_fd[0], STDIN_FILENO);
		dup2(pipes[index_process][1], STDOUT_FILENO);
	}
	else if (index_process == process_num - 1)
	{
		dup2(pipes[index_process - 1][0], STDIN_FILENO);
		dup2(io_fd[1], STDOUT_FILENO);
	}
	else
	{
		dup2(pipes[index_process - 1][0], STDIN_FILENO);
		dup2(pipes[index_process][1], STDOUT_FILENO);
	}
}
