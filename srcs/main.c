/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:48:33 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/26 22:12:11 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex infile cmd cmd outfile
int	main(int argc, char **argv, char **env)
{
	int		pid[argc - 3];
	int		pipes[argc - 4][2];
	int		i;
	int		j;
	int		in_fd;
	int		out_fd;
	char	**cmd;

	if (argc < 5)
		return (0);
	in_fd = open(argv[1], O_RDONLY);
	if (in_fd == -1)
		return (errno);
	out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC);
	if (out_fd == -1)
		return (errno);
	i = 0;
	while (i < argc - 4)
	{
		if (pipe(pipes[i]) == -1)
		{
			printf("Error createing pipes");
			return (errno);
		}
		i++;
	}
	i = 0;
	while (i < argc - 3)
	{
		pid[i] = fork();
		if (pid[i] == -1)
		{
			printf("Error creating process");
			return (errno);
		}
		if (pid[i] == 0)
		{
			if (i == 0)
			{
				dup2(in_fd, STDIN_FILENO);
				dup2(pipes[i][1], STDOUT_FILENO);
			}
			else if (i == argc - 4)
			{
				dup2(pipes[i - 1][0], STDIN_FILENO);
				dup2(out_fd, STDOUT_FILENO);
			}
			else
			{
				dup2(pipes[i - 1][0], STDIN_FILENO);
				dup2(pipes[i][1], STDOUT_FILENO);
			}
			j = 0;
			while (j < argc - 4)
			{
				close(pipes[j][0]);
				close(pipes[j][1]);
				j++;
			}
			close(in_fd);
			close(out_fd);
			cmd = parse_command(argv[i + 2]);
			execve(cmd[0], cmd, env);
			printf("Error executing command");
			return (errno);
		}
		i++;
	}
	j = 0;
	while (j < argc - 4)
	{
		close(pipes[j][0]);
		close(pipes[j][1]);
		j++;
	}
	close(in_fd);
	close(out_fd);
	i = 0;
	while (i < argc - 3)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
	return (0);
}
