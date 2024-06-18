# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 04:50:58 by njeanbou          #+#    #+#              #
#    Updated: 2024/06/18 16:49:00 by vboxuser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = $(wildcard srcs/ms_utils/*.c srcs/ms_parsing/*.c srcs/ms_exec/*.c srcs/ms_cmds/*.c srcs/ms_errors/*.c main.c)

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Werror -Wextra -Wall -fsanitize=address -static-libasan

RM = rm -rf

# Colors:
GREEN   = \e[92;5;118m
YELLOW  = \e[93;5;226m
RESET   = \e[0m
CURSIVE = \e[33;3m

all: ${NAME}

${NAME}: ${OBJS}
				@printf "$(CURSIVE)- Compiling $(NAME)...$(RESET)\n"
				@${MAKE} -C ./ms_libft
				@${CC} ${CFLAGS} ${OBJS} ./ms_libft/libft.a -o ${NAME} -lreadline
				@printf "$(GREEN)- Executable ready.$(RESET)\n"

%.o: %.c
				@${CC} ${CFLAGS} -c $< -o $@

clean:
				@${MAKE} -C ./ms_libft fclean
				@${RM} ${OBJS}
				@printf "$(YELLOW)- Executable removed.$(RESET)\n"

fclean: clean
				@${RM} ${NAME}
				@printf "$(YELLOW)- Executable removed.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re

