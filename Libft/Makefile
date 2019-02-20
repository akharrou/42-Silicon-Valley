# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 16:23:01 by akharrou          #+#    #+#              #
#    Updated: 2019/02/19 17:04:48 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

CC          =	gcc
CFLAGS      =	-Wall -Wextra -Werror

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

NAME        =	libft.a

SRCS        =   ft_atoi.c               \
                ft_bzero.c              \
                ft_isalnum.c            \
                ft_isalpha.c            \
                ft_isascii.c            \
                ft_isdigit.c            \
                ft_isprint.c            \
                ft_memccpy.c            \
                ft_memchr.c             \
                ft_memcmp.c             \
                ft_memcpy.c             \
                ft_memmove.c            \
                ft_memset.c             \
                ft_strcat.c             \
                ft_strchr.c             \
                ft_strcmp.c             \
                ft_strcpy.c             \
                ft_strdup.c             \
                ft_strlcat.c            \
                ft_strlen.c             \
                ft_strncat.c            \
                ft_strncmp.c            \
                ft_strncpy.c            \
                ft_strnlen.c            \
                ft_strnstr.c            \
                ft_strrchr.c            \
                ft_strstr.c             \
                ft_tolower.c            \
                ft_toupper.c            \
                                        \
                ft_itoa.c               \√
                ft_memalloc.c           \√
                ft_memdel.c             \√
                ft_putchar.c            \√
                ft_putchar_fd.c         \√
                ft_putendl.c            \√
                ft_putendl_fd.c         \√
                ft_putnbr.c             \√
                ft_putnbr_fd.c          \√
                ft_putstr.c             \√
                ft_putstr_fd.c          \√
                ft_strclr.c             \√
                ft_strdel.c             \√
                ft_strequ.c             \
                ft_striter.c            \√
                ft_striteri.c           \√
                ft_strjoin.c            \
                ft_strmap.c             \
                ft_strmapi.c            \
                ft_strnequ.c            \
                ft_strnew.c             \√
                ft_strsplit.c           \√
                ft_strsub.c             \
                ft_strtrim.c            \
                                        \
                ft_islower.c            \
                ft_isupper.c            \
                ft_intlen.c             \
                ft_pow.c                \
                ft_strdup_range.c       \
                ft_ischarset.c          \
                ft_wcount.c             \
                ft_wcount_char.c        \




OBJS        =	$(SRCS:.c=.o)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rvs $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

DEL = /bin/rm -rf

clean:
	@$(DEL) *.o

fclean: clean
	@$(DEL) $(NAME)

re: fclean all

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 
