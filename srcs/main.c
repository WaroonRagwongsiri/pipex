/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:48:33 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/03 14:33:18 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex infile cmd cmd outfile
int	main(int argc, char **argv, char **env)
{
	static int	io_fd[2] = {0};

	if (argc < 5 || argc > 103)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		return (1);
	}
	open_file(io_fd, argv[1], argv[argc - 1]);
	close_io_error(argc, argv, env, io_fd);
	pipex(argc, argv, env, io_fd);
	return (0);
}
