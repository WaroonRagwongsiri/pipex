/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:51:07 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/28 15:43:59 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define HEREDOC_PIPES 98

# include "../libft/includes/libft.h"
# include "get_next_line.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdio.h>
# include <errno.h>

// Parse Command
char	**parse_command(char *str, char **env);
char	*find_command_path(char *cmd, char **env);
char	*find_usable_path(char *cmd, char **all_path);

// Pipex
void	pipex(int argc, char **argv, char **env, int io_fd[2]);
int		open_pipes(int pipes[99][2], int process_num);
void	close_pipes(int pipes[99][2], int io_fd[2], int process_num);
void	dup_process(int index_process, int pipes[99][2],\
	int io_fd[2], int process_num);
void	exec_cmd(int index_cmd, char **argv, char **env);

// Utils
void	exit_pipes(int pipes[99][2], int io_fd[2], int process_num);
void	exit_fork(int pipes[99][2], int io_fd[2], int process_num);
void	close_io_error(int io_fd[2]);

// heredoc
void	here_doc(int argc, char **argv, char **env, int io_fd[2]);
void	dup_heredoc(int index_process, int pipes[99][2],\
	int io_fd[2], int process_num);
int		open_pipes_heredoc(int pipes[99][2], int process_num);
int		read_until_lim(int pipes[99][2], char *lim);
void	close_pipes_heredoc(int pipes[99][2], int process_num);
void	exit_pipes_heredoc(int pipes[99][2], int io_fd[2], int process_num);
void	exit_fork_heredoc(int pipes[99][2], int io_fd[2], int process_num);

// GNL_lim
char	*get_next_line_lim(int fd, char *lim);

#endif
