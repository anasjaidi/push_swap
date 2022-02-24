CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
NAME = push_swap
bonus = checker_mac
M_SRCS = push_swap.c \
		in_check/checker.c \
		stack/LinkedList.c \
		operations/opr.c \
		sort/sort_min.c \
		sort/sort_index.c \
		stack/LinkedList_utils.c \
		sort/sort_index_utils.c \
		sort/sort.c \
		in_check/ft_split.c \
		in_check/checker_utils.c 

B_SRCS = checker_bonus.c \
		get_next_line.c \
		get_next_line_utils.c \
		in_check/checker.c \
		stack/LinkedList.c \
		operations/opr.c \
		sort/sort_min.c \
		sort/sort_index.c \
		stack/LinkedList_utils.c \
		sort/sort_index_utils.c \
		sort/sort.c \
		in_check/ft_split.c \
		in_check/checker_utils.c 

M_OBJS = $(M_SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
all : $(NAME) clean
bonus : $(bonus)

$(bonus) : $(B_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME) : $(M_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(M_OBJS) $(B_OBJS)

fclean: clean
	rm -rf $(NAME) $(bonus) 

re: fclean all