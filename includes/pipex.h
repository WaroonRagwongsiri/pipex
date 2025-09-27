/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:51:07 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/27 11:52:33 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdio.h>
# include <errno.h>

// Parse Command
char	**parse_command(char *str, char **env);
char	*find_command_path(char *cmd, char **env);
char	*find_usable_path(char *cmd, char **all_path);

#endif
