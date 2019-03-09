# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 16:23:01 by akharrou          #+#    #+#              #
#    Updated: 2019/03/06 11:57:05 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

CC          =	gcc
CFLAGS      =	-Wall -Wextra -Werror

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

NAME        =	libft.a

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

SRCS        =    dict_getentry_fast.c \
                 dict_getindex.c \
                 dict_getitem.c \
                 dict_getitem_fast.c \
                 dict_insert.c \
                 dict_new.c \
                 dict_remove.c \
                 ft_atoi.c \
                 ft_bzero.c \
                 ft_find_next_prime.c \
                 ft_hash.c \
                 ft_intlen.c \
                 ft_isalnum.c \
                 ft_isalpha.c \
                 ft_isascii.c \
                 ft_ischarset.c \
                 ft_isdigit.c \
                 ft_islower.c \
                 ft_isprime.c \
                 ft_isprint.c \
                 ft_isspace.c \
                 ft_isupper.c \
                 ft_itoa.c \
                 ft_memalloc.c \
                 ft_memccpy.c \
                 ft_memchr.c \
                 ft_memcmp.c \
                 ft_memcpy.c \
                 ft_memdel.c \
                 ft_memmove.c \
                 ft_memset.c \
                 ft_pow.c \
                 ft_putchar.c \
                 ft_putchar_fd.c \
                 ft_putendl.c \
                 ft_putendl_fd.c \
                 ft_putnbr.c \
                 ft_putnbr_fd.c \
                 ft_putstr.c \
                 ft_putstr_fd.c \
                 ft_strcat.c \
                 ft_strchr.c \
                 ft_strclr.c \
                 ft_strcmp.c \
                 ft_strcpy.c \
                 ft_strdel.c \
                 ft_strdup.c \
                 ft_strdup_range.c \
                 ft_strequ.c \
                 ft_striter.c \
                 ft_striteri.c \
                 ft_strjoin.c \
                 ft_strlcat.c \
                 ft_strlen.c \
                 ft_strmap.c \
                 ft_strmapi.c \
                 ft_strncat.c \
                 ft_strncmp.c \
                 ft_strncpy.c \
                 ft_strnequ.c \
                 ft_strnew.c \
                 ft_strnlen.c \
                 ft_strnstr.c \
                 ft_strrchr.c \
                 ft_strsplit.c \
                 ft_strstr.c \
                 ft_strsub.c \
                 ft_strtrim.c \
                 ft_tolower.c \
                 ft_toupper.c \
                 ft_wcount.c \
                 hashtab_alloc_table.c \
                 hashtab_delete_entry.c \
                 hashtab_destroy_table.c \
                 hashtab_fetch_entry.c \
                 hashtab_grow_table.c \
                 hashtab_insert_entry.c \
                 hashtab_rehash_entry.c \
                 hashtab_rehash_table.c \
                 hashtab_set_appropriate_load_factor.c \
                 hashtab_shrink_table.c \
                 list_append_both.c \
                 list_clear.c \
                 list_count.c \
                 list_elem_at.c \
                 list_extend_tail.c \
                 list_extendleft.c \
                 list_iter.c \
                 list_iteri.c \
                 list_last_elem.c \
                 list_merge.c \
                 list_pop.c \
                 list_pop_item.c \
                 list_pop_item_at.c \
                 list_popleft.c \
                 list_remove_item.c \
                 list_remove_item_at.c \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

OBJS        =	$(SRCS:.c=.o)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo && echo $(GREEN) "[√]     [Library Successfully Compiled!]" && echo

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling => " $<

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

DEL = /bin/rm -rf

clean:
	@$(DEL) $(shell find . -name '*.o')

fclean: clean
	@$(DEL) $(NAME)

re: fclean all

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

GREEN = "\033[1;32m"
WHITE = "\033[1;37m"

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 
