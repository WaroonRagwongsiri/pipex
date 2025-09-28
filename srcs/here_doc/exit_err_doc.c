/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_err_doc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:42:51 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/28 15:15:18 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_pipes_heredoc(int pipes[99][2], int io_fd[2], int process_num)
{
	close_pipes_heredoc(pipes, io_fd, process_num);
	perror("Error creating pipes");
	exit(EXIT_FAILURE);
}

void	exit_fork_heredoc(int pipes[99][2], int io_fd[2], int process_num)
{
	close_pipes_heredoc(pipes, io_fd, process_num);
	perror("Error fork");
	exit(EXIT_FAILURE);
}
