/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pid_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 22:01:25 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/02 22:13:54 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	wait_pid_process(int pid[100], int process_num)
{
	int	status[100];
	int	closed[100];
	int	closed_process;
	int	i;

	ft_bzero(closed, sizeof(closed));
	closed_process = 0;
	while (closed_process < process_num)
	{
		i = -1;
		while (++i < process_num)
		{
			if (closed[i])
				continue ;
			waitpid(pid[i], &status[i], WNOHANG);
			WEXITSTATUS(status[i]);
			closed[i] = 1;
			closed_process++;
		}
	}
	return (status[process_num - 1]);
}
