CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
NAME = push_swap
M_SRCS = push_swap.c \
		in_check/checker.c \
		in_check/fil_in.c \
		stack/LinkedList.c \
		operations/opr.c \
		sort/sort_min.c \
		sort/sort_index.c \
		stack/LinkedList_utils.c
M_OBJS = $(M_SRCS:.c=.o)
all : $(NAME) clean

$(NAME) : $(M_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(M_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all