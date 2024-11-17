# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 17:29:12 by aternero          #+#    #+#              #
#    Updated: 2024/11/17 17:57:53 by aternero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = argv_checker.c \
	bso.c \
	cost_algorithm_0.c \
	cost_algorithm_1.c \
	if_nbr_args.c \
	libft.c \
	memory_handling.c \
	min_handling.c \
	push_swap.c \
	push.c \
	reverse_rotate.c \
	rotate.c \
	stack_handling.c \
	swap.c \

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)
	chmod +x $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

all: $(NAME)

.PHONY: all clean fclean re
