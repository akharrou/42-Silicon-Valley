# fillit Makefile

CC = gcc
NAME = fillit
HDRS = *.h
SRCS := check_input.c get_next_line.c \
        helpers.c main.c fillit.c
OBJS := check_input.o get_next_line.o \
        helpers.o main.o fillit.o

CFLAGS = -Wall -Wextra -Werror -I./libft/includes
LDFLAGS = -v -L./libft -lft

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft/ re
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $^

.PHONY : clean
clean :
	@rm -f $(OBJS)

.PHONY : fclean
fclean : clean
	@rm -f $(NAME)

.PHONY : re 
re : fclean all 