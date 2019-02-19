# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 16:23:01 by akharrou          #+#    #+#              #
#    Updated: 2019/02/18 20:59:23 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC          =	gcc
CFLAGS      =	-Wall -Wextra -Werror

NAME        =	libft.a

SRCS        =   ft_atoi.c          \
                ft_bzero.c         \
                ft_isalnum.c       \
                ft_isalpha.c       \
                ft_isascii.c       \
                ft_isdigit.c       \
                ft_islower.c       \
                ft_isprint.c       \
                ft_isupper.c       \
                ft_memccpy.c       \
                ft_memchr.c        \
                ft_memcmp.c        \
                ft_memcpy.c        \
                ft_memmove.c       \
                ft_memset.c        \
                ft_strcat.c        \
                ft_strchr.c        \
                ft_strcmp.c        \
                ft_strcpy.c        \
                ft_strdup.c        \
                ft_strlcat.c       \
                ft_strlen.c        \
                ft_strncat.c       \
                ft_strncmp.c       \
                ft_strncpy.c       \
                ft_strnlen.c       \
                ft_strnstr.c       \
                ft_strrchr.c       \
                ft_strstr.c        \
                ft_tolower.c       \
                ft_toupperc

OBJS        =	$(SRCS:.c=.o)

DEL         =    /bin/rm -rf


all: $(NAME)

$(NAME): $(OBJS)
	@ar -rvs $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	@$(DEL) *.o

fclean: clean
	@$(DEL) $(NAME)

re: fclean all
