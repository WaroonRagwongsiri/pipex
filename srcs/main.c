/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:48:33 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/25 22:54:13 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	p[2];
	int	pid1;
	int	pid2;

	if (pipe(p) == -1)
		return (errno);
	pid1 = fork();
	if (pid1 == -1)
		return (errno);
	if (pid1 == 0)
	{
		close(p[0]);
		dup2(p[1], STDOUT_FILENO);
		close(p[1]);
		execve("/bin/ls", (char *[]){"ls", NULL}, env);
		perror("execve ls");
		exit(errno);
	}
	pid2 = fork();
	if (pid2 == -1)
		return (errno);
	if (pid2 == 0)
	{
		close(p[1]);
		dup2(p[0], STDIN_FILENO);
		close(p[0]);
		execve("/bin/wc", (char *[]){"wc", NULL}, env);
		perror("execve wc");
		exit(errno);
	}
	close(p[0]);
	close(p[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
