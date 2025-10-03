/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:23:15 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/03 13:27:58 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file(int io_fd[2], char *infile, char *outfile)
{
	if (!infile)
	{
		io_fd[0] = 0;
		io_fd[1] = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		io_fd[0] = open(infile, O_RDONLY);
		io_fd[1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
}
