# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 16:23:01 by akharrou          #+#    #+#              #
#    Updated: 2019/02/17 20:23:06 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC          =	gcc
CFLAGS      =	-Wall -Wextra -Werror

NAME        =	libft.a

SRCS        =	memset.c \
    			bzero.c \
    			memcpy.c \
    			x4.c \
    			x5.c

OBJS        =	memset.o \
             	bzero.o \
             	memcpy.o \
             	x4 \
             	x5

DEL         =    /bin/rm -rf


all: $(NAME)

$(NAME): $(OBJS)
	@ar -rvs $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(INC_DIR) $^

clean:
	@$(DEL) *.o

fclean: clean
	@$(DEL) $(NAME)

re: fclean all
