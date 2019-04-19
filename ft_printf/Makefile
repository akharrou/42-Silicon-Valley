# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 00:49:17 by akharrou          #+#    #+#              #
#    Updated: 2019/04/18 21:57:14 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          =   gcc
CFLAGS      =   -Wall -Wextra -Werror -g -fsanitize=address -fsanitize=undefined

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

NAME        =   libftprintf.a

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

SOURCES     =   ft_printf.c                                                   \
                parsers.c                                                     \
                format_string.c                                               \
                $(HANDLERS)                                                   \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

HANDLERS    =   Handlers/c_handler.c                                 \
                Handlers/s_handler.c                                 \
                Handlers/p_handler.c                                 \
                Handlers/d_handler.c                                 \
                Handlers/i_handler.c                                 \
                Handlers/f_handler.c                                 \
                Handlers/o_handler.c                                 \
                Handlers/u_handler.c                                 \
                Handlers/x_handler.c                                 \
                Handlers/X_handler.c                                 \

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
