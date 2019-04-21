# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 16:23:01 by akharrou          #+#    #+#              #
#    Updated: 2019/04/21 12:55:01 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

CC          =   gcc
CFLAGS      =   -Wall -Wextra -Werror

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

NAME        =   libftprintf.a

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

HEADERS     =   ft_printf.h

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

SOURCES     =   ft_printf.c                                                   \
                parser.c                                                      \
                converter.c                                                   \
                $(PLUGINS)                                                    \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

PLUGINS     =   Handlers/c_handler.c                                          \
                Handlers/i_handler.c                                          \
                Handlers/u_handler.c                                          \
                Handlers/f_handler.c                                          \
                Handlers/b_handler.c                                          \
                Handlers/o_handler.c                                          \
                Handlers/d_handler.c                                          \
                Handlers/x_handler.c                                          \
                Handlers/s_handler.c                                          \
                Handlers/r_handler.c                                          \
                Handlers/p_handler.c                                          \
                Handlers/mod_handler.c                                        \
                Handlers/style_handler.c                                      \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

OBJECTS     =   $(SOURCES:.c=.o)

# Main — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

all: $(NAME)

$(NAME): Libft/libft.a $(OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS) $(shell find Libft/ -name '*.o')
	@echo && echo $(GREEN) "[√]     [Extended Library Successfully Compiled!]"
	@echo

Libft/libft.a:
	@make -C Libft

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling => " $<

# House Keeping — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

DEL = /bin/rm -rf

clean:
	@$(DEL) $(shell find . -name '*.o')
	@make clean -C Libft/

fclean: clean
	@$(DEL) $(NAME)
	@make fclean -C Libft/

re: fclean all

# Text Colorization — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

GREEN = "\033[1;32m"
WHITE = "\033[1;37m"

# Norminette Check — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

nc:
	@echo && echo $(GREEN) "Checking Norme -- Source Files:" && echo $(WHITE);
	@norminette $(shell find . -name '*.c')

nh:
	@echo && echo $(GREEN) "Checking Norme -- Header Files:" && echo $(WHITE);
	@norminette $(shell find . -name '*.h')

na: nh nc

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

.PHONY: all clean fclean re nc nh na

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
