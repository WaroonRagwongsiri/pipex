/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:22:57 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/28 15:44:14 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex here_doc LIMITER cmd cmd outfile
void	here_doc(int argc, char **argv, char **env, int io_fd[2])
{
	int		pid[100];
	int		pipes[99][2];
	int		i;

	if (!open_pipes_heredoc(pipes, (argc - 4)))
		exit_pipes_heredoc(pipes, io_fd, (argc - 4));
	if (!read_until_lim(pipes, argv[2]))
	{
		close_pipes_heredoc(pipes, (argc - 4));
		exit(EXIT_FAILURE);
	}
	close(pipes[HEREDOC_PIPES][1]);
	i = -1;
	while (++i < (argc - 4))
	{
		pid[i] = fork();
		if (pid[i] == -1)
			exit_fork_heredoc(pipes, io_fd, (argc - 4));
		if (pid[i] == 0)
		{
			dup_heredoc(i, pipes, io_fd, (argc - 4));
			close_pipes_heredoc(pipes, (argc - 4));
			exec_cmd((i + 3), argv, env);
		}
	}
	close_pipes_heredoc(pipes, (argc - 4));
	i = -1;
	while (++i < (argc - 4))
		waitpid(pid[i], NULL, 0);
}

int	read_until_lim(int pipes[99][2], char *lim)
{
	char	*lim_n;
	char	*doc;

	lim_n = ft_calloc(ft_strlen(lim) + 2, sizeof(char));
	if (!lim_n)
		return (0);
	ft_strlcat(lim_n, lim, ft_strlen(lim) + 1);
	ft_strlcat(lim_n, "\n", ft_strlen(lim) + 2);
	
	doc = get_next_line_lim(0, lim_n);
	while (doc)
	{
		if (write(pipes[HEREDOC_PIPES][1], doc, ft_strlen(doc)) == -1)
		{
			free(doc);
			free(lim_n);
			return (0);
		}
		free(doc);
		doc = get_next_line_lim(0, lim_n);
	}
	free(doc);
	free(lim_n);
	return (1);
}
