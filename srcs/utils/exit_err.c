/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:42:51 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/03 14:11:40 by waragwon         ###   ########.fr       */
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

void	close_fd(int fd)
{
	if (fd > 0)
		close(fd);
}
