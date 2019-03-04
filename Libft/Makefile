# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 16:23:01 by akharrou          #+#    #+#              #
#    Updated: 2019/03/04 13:06:59 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

CC          =   gcc
CFLAGS      =   -Wall -Wextra -Werror

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

NAME        =   libft.a

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

OBJECTS     =   $(SOURCES:.c=.o)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

SOURCES     =   $(STDIO)                                                      \
                $(STDLIB)                                                     \
                $(STRING)                                                     \
                $(CTYPE)                                                      \
                $(MATH)                                                       \
                $(LIST)                                                       \
                $(BTREE)                                                      \
                $(TRIE)                                                       \
                $(HASHTABLE)                                                  \
                $(DICT)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

STDIO       =   Sources/Stdio/ft_putbyte.c                                    \
                Sources/Stdio/ft_putbyte_fd.c                                 \
                Sources/Stdio/ft_putbytes.c                                   \
                Sources/Stdio/ft_putbytes_fd.c                                \
                Sources/Stdio/ft_putchar.c                                    \
                Sources/Stdio/ft_putchar_fd.c                                 \
                Sources/Stdio/ft_putstr.c                                     \
                Sources/Stdio/ft_putstr_fd.c                                  \
                Sources/Stdio/ft_putendl.c                                    \
                Sources/Stdio/ft_putendl_fd.c                                 \
                Sources/Stdio/ft_putstrtab.c                                  \
                Sources/Stdio/ft_putstrtab_fd.c                               \
                Sources/Stdio/ft_putnbr.c                                     \
                Sources/Stdio/ft_putnbr_fd.c                                  \
                Sources/Stdio/ft_putnbr_base.c                                \
                Sources/Stdio/ft_putnbr_base_fd.c                             \
                Sources/Stdio/ft_getline.c                                    \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

STDLIB      =   Sources/Stdlib/ft_bzero.c                                     \
                Sources/Stdlib/ft_memset.c                                    \
                Sources/Stdlib/ft_memcpy.c                                    \
                Sources/Stdlib/ft_memccpy.c                                   \
                Sources/Stdlib/ft_memmove.c                                   \
                Sources/Stdlib/ft_memchr.c                                    \
                Sources/Stdlib/ft_memcmp.c                                    \
                Sources/Stdlib/ft_memdel.c                                    \
                Sources/Stdlib/ft_memalloc.c                                  \
                Sources/Stdlib/ft_realloc.c                                   \
                Sources/Stdlib/ft_matrixnew.c                                 \
                Sources/Stdlib/ft_intlen.c                                    \
                Sources/Stdlib/ft_atoi.c                                      \
                Sources/Stdlib/ft_itoa.c                                      \
                Sources/Stdlib/ft_atoi_base.c                                 \
                Sources/Stdlib/ft_itoa_base.c                                 \
                Sources/Stdlib/ft_convert_base.c                              \
                Sources/Stdlib/ft_find_next_prime.c                           \
                Sources/Stdlib/ft_wcount.c                                    \
                Sources/Stdlib/ft_swap_int.c                                  \
                Sources/Stdlib/ft_swap_char.c                                 \
                Sources/Stdlib/ft_swap_str.c                                  \
                Sources/Stdlib/ft_swap_item.c                                 \
                Sources/Stdlib/ft_hash.c                                      \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

STRING      =   Sources/String/ft_strlen.c                                    \
                Sources/String/ft_strnlen.c                                   \
                Sources/String/ft_strcmp.c                                    \
                Sources/String/ft_strncmp.c                                   \
                Sources/String/ft_strequ.c                                    \
                Sources/String/ft_strnequ.c                                   \
                Sources/String/ft_strrev.c                                    \
                Sources/String/ft_strcpy.c                                    \
                Sources/String/ft_strncpy.c                                   \
                Sources/String/ft_strlcpy.c                                   \
                Sources/String/ft_strcpy_until.c                              \
                Sources/String/ft_strcat.c                                    \
                Sources/String/ft_strncat.c                                   \
                Sources/String/ft_strlcat.c                                   \
                Sources/String/ft_strchr.c                                    \
                Sources/String/ft_strrchr.c                                   \
                Sources/String/ft_strchrs.c                                   \
                Sources/String/ft_strstr.c                                    \
                Sources/String/ft_strnstr.c                                   \
                Sources/String/ft_strdup.c                                    \
                Sources/String/ft_strdup_range.c                              \
                Sources/String/ft_strnew.c                                    \
                Sources/String/ft_strdel.c                                    \
                Sources/String/ft_strclr.c                                    \
                Sources/String/ft_striter.c                                   \
                Sources/String/ft_striteri.c                                  \
                Sources/String/ft_strmap.c                                    \
                Sources/String/ft_strmapi.c                                   \
                Sources/String/ft_strjoin.c                                   \
                Sources/String/ft_strtrim.c                                   \
                Sources/String/ft_strsub.c                                    \
                Sources/String/ft_strsplit.c                                  \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

CTYPE       =   Sources/Ctype/ft_isupper.c                                    \
                Sources/Ctype/ft_islower.c                                    \
                Sources/Ctype/ft_isblank.c                                    \
                Sources/Ctype/ft_isspace.c                                    \
                Sources/Ctype/ft_isalpha.c                                    \
                Sources/Ctype/ft_isdigit.c                                    \
                Sources/Ctype/ft_isalnum.c                                    \
                Sources/Ctype/ft_isascii.c                                    \
                Sources/Ctype/ft_isgraph.c                                    \
                Sources/Ctype/ft_ispunct.c                                    \
                Sources/Ctype/ft_iscntrl.c                                    \
                Sources/Ctype/ft_isprint.c                                    \
                Sources/Ctype/ft_isprime.c                                    \
                Sources/Ctype/ft_ischarset.c                                  \
                Sources/Ctype/ft_toupper.c                                    \
                Sources/Ctype/ft_tolower.c                                    \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

MATH        =   Sources/Math/ft_pow.c                                         \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

LIST        =   Sources/Lists-Stacks-Queues/list_newelem.c                    \
                Sources/Lists-Stacks-Queues/list_prepend.c                    \
                Sources/Lists-Stacks-Queues/list_append.c                     \
                Sources/Lists-Stacks-Queues/list_append_tail.c                \
                Sources/Lists-Stacks-Queues/list_append_both.c                \
                Sources/Lists-Stacks-Queues/list_extend.c                     \
                Sources/Lists-Stacks-Queues/list_extend_tail.c                \
                Sources/Lists-Stacks-Queues/list_extendleft.c                 \
                Sources/Lists-Stacks-Queues/list_insert.c                     \
                Sources/Lists-Stacks-Queues/list_insert_at.c                  \
                Sources/Lists-Stacks-Queues/list_item_at.c                    \
                Sources/Lists-Stacks-Queues/list_last_item.c                  \
                Sources/Lists-Stacks-Queues/list_elem_at.c                    \
                Sources/Lists-Stacks-Queues/list_last_elem.c                  \
                Sources/Lists-Stacks-Queues/list_getitem.c                    \
                Sources/Lists-Stacks-Queues/list_getelem.c                    \
                Sources/Lists-Stacks-Queues/list_pop.c                        \
                Sources/Lists-Stacks-Queues/list_pop_tail.c                   \
                Sources/Lists-Stacks-Queues/list_popleft.c                    \
                Sources/Lists-Stacks-Queues/list_pop_item_at.c                \
                Sources/Lists-Stacks-Queues/list_pop_item.c                   \
                Sources/Lists-Stacks-Queues/list_remove_item.c                \
                Sources/Lists-Stacks-Queues/list_remove_item_at.c             \
                Sources/Lists-Stacks-Queues/list_remove_elem.c                \
                Sources/Lists-Stacks-Queues/list_remove_elem_at.c             \
                Sources/Lists-Stacks-Queues/list_clear.c                      \
                Sources/Lists-Stacks-Queues/list_iter.c                       \
                Sources/Lists-Stacks-Queues/list_iteri.c                      \
                Sources/Lists-Stacks-Queues/list_count.c                      \
                Sources/Lists-Stacks-Queues/list_sort.c                       \
                Sources/Lists-Stacks-Queues/list_reverse.c                    \
                Sources/Lists-Stacks-Queues/list_map.c                        \
                Sources/Lists-Stacks-Queues/list_merge.c                      \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

BTREE       =   Sources/Binary-Trees/btree_newnode.c                          \
                Sources/Binary-Trees/btree_apply_prefix.c                     \
                Sources/Binary-Trees/btree_apply_infix.c                      \
                Sources/Binary-Trees/btree_apply_suffix.c                     \
                Sources/Binary-Trees/btree_insert.c                           \
                Sources/Binary-Trees/btree_getitem.c                          \
                Sources/Binary-Trees/btree_level_count.c                      \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

TRIE        =   Sources/Tries/trie_newnode.c                                  \
                Sources/Tries/trie_insert.c                                   \
                Sources/Tries/trie_remove.c                                   \
                Sources/Tries/trie_clear.c                                    \
                Sources/Tries/trie_getitem.c                                  \
                Sources/Tries/trie_count.c                                    \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

HASHTABLE   =   Sources/Hashtables/hashtab_alloc_table.c                      \
                Sources/Hashtables/hashtab_grow_table.c                       \
                Sources/Hashtables/hashtab_shrink_table.c                     \
                Sources/Hashtables/hashtab_fetch_entry.c                      \
                Sources/Hashtables/hashtab_insert_entry.c                     \
                Sources/Hashtables/hashtab_delete_entry.c                     \
                Sources/Hashtables/hashtab_rehash_entry.c                     \
                Sources/Hashtables/hashtab_rehash_table.c                     \
                Sources/Hashtables/hashtab_destroy_table.c                    \
                Sources/Hashtables/hashtab_set_appropriate_load_factor.c      \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

DICT        =   $(SRC_DIR)/Dicts/dict_new.c                                   \
                $(SRC_DIR)/Dicts/dict_insert.c                                \
                $(SRC_DIR)/Dicts/dict_getindex.c                              \
                $(SRC_DIR)/Dicts/dict_getitem.c                               \
                $(SRC_DIR)/Dicts/dict_getitem_fast.c                          \
                $(SRC_DIR)/Dicts/dict_getentry.c                              \
                $(SRC_DIR)/Dicts/dict_getentry_fast.c                         \
                $(SRC_DIR)/Dicts/dict_remove.c                                \
                $(SRC_DIR)/Dicts/dict_clear.c                                 \

# Main — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS)
	@echo && echo $(GREEN) "   [√] 	[Library Successfully Compiled!]" && echo

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling => " $<

# House Keeping — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

DEL = /bin/rm -rf

clean:
	@$(DEL) $(shell find . -name '*.o')

fclean: clean
	@$(DEL) $(NAME)

re: fclean all

# Text Colorization — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

GREEN = "   \033[1;32m"
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
