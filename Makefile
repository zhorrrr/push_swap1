NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =  swap_operations.c \
        push_operations.c \
        rotate-operations.c \
        reverse_rotate_operatins.c \
        stack_utils.c \
        index.c \
        sort_small_numbers.c \
        chunk_utils.c \
        chunk_sort.c \
        stack_sort_all.c \
	main.c \
       	helpers.c	

OBJS = $(SRCS:.c=.o)

INCLUDES = -I .

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

