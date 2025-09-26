/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:51:07 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/26 21:03:27 by waroonwork@      ###   ########.fr       */
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

char	**parse_command(char *str);

#endif
