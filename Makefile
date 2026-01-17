NAME        = push_swap
BONUS_NAME  = checker_bonus
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

INCLUDES = -I. -Ilibft -Ichecker

LIBFT = libft/libft.a

SRCS = main.c \
       sort_2_3_numbers.c \
       sort_5_numbers.c \
       stack_utils.c \
       swap_operations.c \
       stack_sort_all.c \
       rotate_operations.c \
       reverse_rotate_operations.c \
       push_operations.c \
       index.c \
       helpers.c \
       chunk_sort.c \
       chunk_utils.c 

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = checker/checker_bonus.c \
             checker/checker_utils_bonus.c \
             checker/get_next_line.c \
             checker/get_next_line_utils.c \
             stack_utils.c \
             swap_operations.c \
             rotate_operations.c \
             reverse_rotate_operations.c \
             push_operations.c \
             helpers.c \
             index.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus





