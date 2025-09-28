/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:51:07 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/28 12:32:07 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
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
void	dup_process(int index_process, int pipes[99][2], int io_fd[2], int process_num);

// Exit
void	exit_pipes(int pipes[99][2], int io_fd[2], int process_num);
void	exit_fork(int pipes[99][2], int io_fd[2], int process_num);
void	exit_exec(int pipes[99][2], int io_fd[2], int process_num);

#endif
