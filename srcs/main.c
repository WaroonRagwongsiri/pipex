/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:48:33 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/26 18:33:18 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex infile cmd cmd outfile
int	main(int argc, char **argv, char **env)
{
	int	pid[argc];
	int	pipes[argc - 3][2];
	int	i;
	int	j;
	int	in_fd;
	int	out_fd;

	if (argc < 5)
		return (0);
	in_fd = open(argv[1], O_RDONLY);
	out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC);
	i = 0;
	while (i < argc - 3)
	{
		if (pipe(pipes[i]) == -1)
		{
			printf("Error createing pipes");
			return (errno);
		}
		i++;
	}
	i = 0;
	while (i < argc - 2)
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
			else if (i == argc - 3)
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
			while (j < argc - 3)
			{
				close(pipes[j][0]);
				close(pipes[j][1]);
				j++;
			}
			close(in_fd);
			close(out_fd);
			if (i == argc - 3)
				execve("/usr/bin/wc", (char *[]){"wc", NULL}, env);
			else
				execve("/bin/cat", (char *[]){"cat", "-e", NULL}, env);
			printf("Error executing command");
			return (errno);
		}
		i++;
	}
	j = 0;
	while (j < argc - 3)
	{
		close(pipes[j][0]);
		close(pipes[j][1]);
		j++;
	}
	close(in_fd);
	close(out_fd);
	i = 0;
	while (i < argc - 2)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
	return (0);
}
