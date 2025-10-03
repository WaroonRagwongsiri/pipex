# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 14:50:41 by waroonwork@       #+#    #+#              #
#    Updated: 2025/07/10 14:50:41 by waroonwork@      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	pipex
BONUS_NAME		:=	pipex_bonus

CC				:=	cc
CFLAG			:=	-Wall -Wextra -Werror -g3

INC_DIR			:=	includes/
SRCS_DIR		:=	srcs/

# Mandatory source files
SRCS_FILES		:=	main.c \
					utils/parse_command.c utils/exit_err.c \
					utils/check_command.c utils/wait_pid_process.c \
					utils/open_file.c \
					pipex/pipex.c pipex/pipes_process.c \

SRCS			:=	$(SRCS_FILES:%.c=$(SRCS_DIR)%.c)
OBJS			:=	$(SRCS:%.c=%.o)

# Shared utils objects (exclude main.o)
UTILS_OBJS		:=	$(filter-out $(SRCS_DIR)main.o, $(OBJS))

# Bonus source files (only bonus-specific files)
BONUS_DIR		:=	bonus/
BONUS_FILES		:=	main_bonus.c \
					gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c \
					gnl/get_next_line_lim_bonus.c \
					here_doc/dup_here_doc_bonus.c here_doc/exit_err_doc_bonus.c \
					here_doc/here_doc_bonus.c \

BONUS			:=	$(BONUS_FILES:%.c=$(SRCS_DIR)$(BONUS_DIR)%.c)
BONUS_OBJS		:=	$(BONUS:%.c=%.o)

all				:	$(NAME)

$(NAME)			:	$(OBJS)
	@make -C libft
	@cp libft/libft.a .
	$(CC) $(CFLAG) -I$(INC_DIR) $(OBJS) libft.a -o $@

%.o				:	%.c
	$(CC) $(CFLAG) -I$(INC_DIR) -c $< -o $@

bonus			:	$(BONUS_NAME)

$(BONUS_NAME)	:	$(BONUS_OBJS) $(UTILS_OBJS)
	@make -C libft
	@cp libft/libft.a .
	$(CC) $(CFLAG) -I$(INC_DIR) $(BONUS_OBJS) $(UTILS_OBJS) libft.a -o $@

clean			:
	rm -rf $(OBJS) $(BONUS_OBJS)
	@make -C libft clean

fclean			:	clean
	rm -rf $(NAME) $(BONUS_NAME) libft.a
	@make -C libft fclean

re				:	fclean all

.PHONY			:	all clean fclean re bonus