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

CC				:=	cc
CFLAG			:=	-Wall -Wextra -Werror -g3

INC_DIR			:=	includes/
SRCS_DIR		:=	srcs/

SRCS_FILES		:=	main.c \
					utils/parse_command.c

SRCS			:=	$(SRCS_FILES:%.c=$(SRCS_DIR)%.c)
OBJS			:=	$(SRCS:%.c=%.o)

all				:	$(NAME) Makefile

$(NAME)			:	$(OBJS) Makefile
	@make -C libft
	@cp libft/libft.a .
	$(CC) $(CFLAG) -I$(INC_DIR) $(OBJS) libft.a -o $@

$(OBJS)			:	%.o : %.c
	$(CC) $(CFLAG) -I$(INC_DIR) -c $< -o $@

clean			:
	rm -rf $(OBJS)
	@make -C libft clean

fclean			:	clean
	rm -rf $(NAME)
	rm -rf libft.a
	@make -C libft fclean

re				:	fclean all

.PHONY			:	all clean fclean re bonus