# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/16 13:27:10 by akharrou          #+#    #+#              #
#    Updated: 2019/03/18 09:11:51 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          =   gcc
CFLAGS      =   -Wall -Wextra -Werror -O0 -g

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

NAME        =   fillit

LIBRARY     =   Libft/libft.a

SOURCES     =   main.c      \
                input.c     \
                solver.c    \
                utils.c     \

OBJECTS     =   $(SOURCES:.c=.o)


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #
#                                                                             #
#                            DO NOT TOUCH THE REST                            #
#                                                                             #
# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #


all: $(NAME)

$(NAME): $(LIBRARY) $(OBJECTS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo && echo $(GREEN) "[√]   [Program Successfully Compiled!]" && echo

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(WHITE) "Compiling => " $<

$(LIBRARY):
	@make -C Libft/

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

DEL  =  /bin/rm -rf

clean:
	@$(DEL) $(shell find . -name '*.[o]')

fclean: clean
	@$(DEL) $(NAME)

re: fclean all

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #
#                                                                             #
#                                    EXTRA                                    #
#                                                                             #
# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #


nc:
	@echo && echo $(GREEN) "Checking Norme -- Source Files:" && echo $(WHITE);
	@norminette $(shell find . -name '*.c')

nh:
	@echo && echo $(GREEN) "Checking Norme -- Header Files:" && echo $(WHITE);
	@norminette $(shell find . -name '*.h')

na: nh nc

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

GREEN =  "\033[1;32m"
WHITE =  "\033[1;37m"

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

.PHONY: all clean fclean re nc nh na

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
