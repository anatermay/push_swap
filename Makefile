NAME 			= push_swap
NAME_BONUS		= checker

CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra -g

SRCS = bso.c \
	cost_algorithm_0.c \
	cost_algorithm_1.c \
	if_nbr_args.c \
	min_handling.c \
	push_swap.c \

LIBFT_SRCS = libft.c \
	libft_continue.c \

COMMON_FILES_SRCS = argv_checker.c \
	memory_handling.c \
	push.c \
	reverse_rotate.c \
	rotate.c \
	stack_handling.c \
	swap.c \

BONUS_SRCS = checker.c \
	get_next_line.c \

OBJECTS = $(SRCS:.c=.o)
LIBFT_OBJECTS = $(LIBFT_SRCS:.c=.o)
COMMON_FILES_OBJECTS = $(COMMON_FILES_SRCS:.c=.o)
BONUS_OBJECTS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(COMMON_FILES_OBJECTS) $(LIBFT_OBJECTS)
	@${CC} ${CFLAGS} -o ${NAME} ${OBJECTS} $(COMMON_FILES_OBJECTS) ${LIBFT_OBJECTS}
	@chmod +x $(NAME)
	@echo "OK"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJECTS) $(COMMON_FILES_OBJECTS) $(LIBFT_OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(BONUS_OBJECTS) $(COMMON_FILES_OBJECTS) $(LIBFT_OBJECTS)
	@chmod +x $(NAME_BONUS)
	@echo "OK"

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -f $(OBJECTS) $(BONUS_OBJECTS) $(COMMON_FILES_OBJECTS) $(LIBFT_OBJECTS)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
