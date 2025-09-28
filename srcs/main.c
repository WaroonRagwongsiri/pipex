/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:48:33 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/28 12:50:54 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex infile cmd cmd outfile
int	main(int argc, char **argv, char **env)
{
	int	io_fd[2];

	if (argc < 5 || argc - 3 > 100)
		return (0);
	io_fd[0] = open(argv[1], O_RDONLY);
	io_fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC);
	if (io_fd[0] == -1 || io_fd[1] == -1)
	{
		perror("File without permission");
		return (close(io_fd[0]), close(io_fd[1]), errno);
	}
	pipex(argc, argv, env, io_fd);
	return (0);
}
