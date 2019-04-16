# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/16 13:27:10 by akharrou          #+#    #+#              #
#    Updated: 2019/03/23 18:38:07 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          =   gcc
CFLAGS      =   -Wall -Wextra -Werror

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

NAME        =   fillit

LIBRARY     =   libft/libft.a

SOURCES     =   main.c      \
                input.c     \
                solver.c    \
                utils.c     \
                output.c    \

OBJECTS     =   $(SOURCES:.c=.o)


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #
#                                                                             #
#                            DO NOT TOUCH THE REST                            #
#                                                                             #
# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #


all: $(NAME)

$(NAME): $(LIBRARY) $(OBJECTS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo && echo $(GREEN) "[√]     [Program Successfully Compiled!]" && echo

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(WHITE) "Compiling => " $<

$(LIBRARY):
	@make -C libft/

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

DEL  =  /bin/rm -rf

clean:
	@$(DEL) $(shell find . -name '*.[oa]')

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
