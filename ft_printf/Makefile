# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 00:49:17 by akharrou          #+#    #+#              #
#    Updated: 2019/04/15 01:19:48 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          =   gcc
CFLAGS      =   -Wall -Wextra -Werror

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

NAME        =   libftprintf.a

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

SOURCES     =   ft_printf.c                                                   \
                # utils.c                                                       \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

HEADERS     =   ft_printf.h

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

OBJECTS     =   $(SOURCES:.c=.o)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

all: $(NAME)

$(NAME): libft.a $(OBJECTS)
	@ar -rcs $(NAME) $^
	@echo && echo $(GREEN) "[√]     [Library Successfully Compiled!]" && echo

libft.a:
	@make -C Libft
	@mv Libft/libft.a .

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling => " $<

# House Keeping — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

DEL = /bin/rm -rf

clean:
	@$(DEL) $(shell find . -maxdepth 1 -name '*.o')
	@make clean -C Libft

fclean: clean
	@$(DEL) $(shell find . -maxdepth 1 -name '*.a')
	@make fclean -C Libft

re: fclean all

# Text Colorization — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

GREEN = "\033[1;32m"
WHITE = "\033[1;37m"

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
