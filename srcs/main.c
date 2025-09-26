/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:48:33 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/26 17:35:19 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define PROCESS_NUM 3

int	main(void)
{
	int	pid[PROCESS_NUM];
	int	pipes[PROCESS_NUM + 1][2];
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (i < PROCESS_NUM + 1)
	{
		if (pipe(pipes[i]) == -1)
		{
			printf("Error createing pipes");
			return (errno);
		}
		i++;
	}
	i = 0;
	while (i < PROCESS_NUM)
	{
		pid[i] = fork();
		if (pid[i] == -1)
		{
			printf("Error creating process");
			return (errno);
		}
		if (pid[i] == 0)
		{
			j = 0;
			while (j < PROCESS_NUM + 1)
			{
				if (i != j)
					close(pipes[j][0]);
				if (j != i + 1)
					close(pipes[j][1]);
				j++;
			}
			if (read(pipes[i][0], &x, sizeof(x)) == -1)
			{
				printf("Error at reading");
				return (errno);
			}
			++x;
			if (write(pipes[i + 1][1], &x, sizeof(x)) == -1)
			{
				printf("Error at writing");
				return (errno);
			}
			close(pipes[i][0]);
			close(pipes[i + 1][0]);
			return (0);
		}
		i++;
	}
	j = 0;
	while (j < PROCESS_NUM + 1)
	{
		if (j != PROCESS_NUM)
			close(pipes[j][0]);
		if (j != 0)
			close(pipes[j][1]);
		j++;
	}
	y = 1;
	printf("Send is %d", y);
	if (write(pipes[0][1], &y, sizeof(y)) == -1)
	{
		printf("Error at writing");
		return (errno);
	}
	if (read(pipes[PROCESS_NUM][0], &y, sizeof(y)) == -1)
	{
		printf("Error at reading");
		return (errno);
	}
	printf("Result is %d", y);
	close(pipes[0][1]);
	close(pipes[PROCESS_NUM][0]);
	i = 0;
	while (i < PROCESS_NUM)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
	return (0);
}
