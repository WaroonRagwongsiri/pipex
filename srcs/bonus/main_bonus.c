/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:48:33 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/03 13:27:26 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex infile cmd cmd outfile
// ./pipex here_doc LIMITER cmd cmd outfile
int	main(int argc, char **argv, char **env)
{
	int	io_fd[2];

	if (argc < 5 || argc > 103)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		return (1);
	}
	if (ft_strncmp(argv[1], "here_doc", 9) == 0 && argc < 90 && argc >= 6)
	{
		open_file(io_fd, NULL, argv[argc - 1]);
		close_io_error_heredoc(argc, argv, env, io_fd);
		here_doc(argc, argv, env, io_fd);
	}
	else
	{
		open_file(io_fd, argv[1], argv[argc - 1]);
		close_io_error_heredoc(argc, argv, env, io_fd);
		pipex(argc, argv, env, io_fd);
	}
	return (0);
}
