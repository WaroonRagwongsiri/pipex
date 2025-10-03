/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_here_doc_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:57:22 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/03 12:53:50 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_heredoc(int index_process, int pipes[99][2],\
	int io_fd[2], int process_num)
{
	if (index_process == 0)
	{
		dup2(pipes[HEREDOC_PIPES][0], STDIN_FILENO);
		dup2(pipes[index_process][1], STDOUT_FILENO);
	}
	else if (index_process == process_num - 1)
	{
		read_to_end(io_fd[1]);
		dup2(pipes[index_process - 1][0], STDIN_FILENO);
		dup2(io_fd[1], STDOUT_FILENO);
	}
	else
	{
		dup2(pipes[index_process - 1][0], STDIN_FILENO);
		dup2(pipes[index_process][1], STDOUT_FILENO);
	}
}

int	open_pipes_heredoc(int pipes[99][2], int process_num)
{
	int	i;

	i = 0;
	while (i < process_num - 1)
	{
		if (pipe(pipes[i]) == -1)
			return (0);
		i++;
	}
	if (pipe(pipes[HEREDOC_PIPES]) == -1)
		return (0);
	return (1);
}

void	close_pipes_heredoc(int pipes[99][2], int process_num)
{
	int	i;

	i = 0;
	while (i < process_num - 1)
	{
		close_fd(pipes[i][0]);
		close_fd(pipes[i][1]);
		i++;
	}
	close_fd(pipes[HEREDOC_PIPES][0]);
	close_fd(pipes[HEREDOC_PIPES][1]);
}

void	read_to_end(int out_fd)
{
	char	buffer[1024];
	int		byte_reads;

	byte_reads = 1;
	while (byte_reads > 0)
	{
		byte_reads = read(out_fd, buffer, sizeof(buffer));
	}
}
