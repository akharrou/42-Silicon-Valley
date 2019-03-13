# **************************************************************************** #
#                                                                              #
#                              MAKEFILE FRAMEWORK                              #
#                                                                              #
# **************************************************************************** #

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

CC          =   gcc
CFLAGS      =   -Wall -Wextra -Werror

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

NAME        =   fillit

LIBRARIES   =   libft/libft.a

SOURCES     =   main.c \

OBJECTS     =   $(SOURCES:.c=.o)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
#                                                                             #
#                            DO NOT TOUCH THE REST                            #
#                                                                             #
# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

all: $(NAME)

$(NAME): $(LIBRARIES) $(OBJECTS)
	@$(CC) $(OBJECTS) $(LIBRARIES) -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling => " $<

$(LIBRARIES):
	@make -C libft/

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

DEL  =  /bin/rm -rf

clean:
	@$(DEL) $(shell find . -name '*.o')

fclean: clean
	@$(DEL) $(NAME)

re: fclean all

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

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
