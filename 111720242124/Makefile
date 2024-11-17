NAME 			= push_swap
NAME_BONUS		= checker

CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra -g

SRCS = argv_checker.c \
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

BONUS_SRCS = checker.c \
	get_next_line.c \
	get_next_line_utils.c \
	libft_bonus.c \

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

OBJS_DIR = ./objs

all: $(NAME)

$(NAME): $(OBJS)
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	if [ -d "$(OBJS_DIR)" ]; then ${RM} -r $(OBJS_DIR); fi

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
