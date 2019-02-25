# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 16:23:01 by akharrou          #+#    #+#              #
#    Updated: 2019/02/24 14:07:44 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

CC          =	gcc
CFLAGS      =	-Wall -Wextra -Werror -O2

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

NAME        =	libft.a

SRCS        =   ft_isupper.c                                \
                ft_islower.c                                \
                ft_isblank.c                                \
                ft_isspace.c                                \
                ft_isalpha.c                                \
                ft_isdigit.c                                \
                ft_isalnum.c                                \
                ft_isascii.c                                \
                ft_isgraph.c                                \
                ft_ispunct.c                                \
                ft_iscntrl.c                                \
                ft_isprint.c                                \
                ft_isprime.c                                \
                ft_ischarset.c                              \
                ft_toupper.c                                \
                ft_tolower.c                                \
                                                            \
                ft_bzero.c                                  \
                ft_memset.c                                 \
                ft_memcpy.c                                 \
                ft_memccpy.c                                \
                ft_memmove.c                                \
                ft_memchr.c                                 \
                ft_memcmp.c                                 \
                ft_memdel.c                                 \
                ft_memalloc.c                               \
                ft_realloc.c                                \
                                                            \
                ft_strlen.c                                 \
                ft_strnlen.c                                \
                ft_strcmp.c                                 \
                ft_strncmp.c                                \
                ft_strequ.c                                 \
                ft_strnequ.c                                \
                ft_strrev.c                                 \
                ft_strcpy.c                                 \
                ft_strncpy.c                                \
                ft_strlcpy.c                                \
                ft_strcat.c                                 \
                ft_strncat.c                                \
                ft_strlcat.c                                \
                ft_strchr.c                                 \
                ft_strrchr.c                                \
                ft_strchrs.c                                \
                ft_strstr.c                                 \
                ft_strnstr.c                                \
                ft_strdup.c                                 \
                ft_strdup_range.c                           \
                ft_strnew.c                                 \
                ft_strdel.c                                 \
                ft_strclr.c                                 \
                ft_striter.c                                \
                ft_striteri.c                               \
                ft_strmapi.c                                \
                ft_strjoin.c                                \
                ft_strtrim.c                                \
                ft_strsplit.c                               \
                                                            \
                ft_putbyte.c                                \
                ft_putbyte_fd.c                             \
                ft_putbytes.c                               \
                ft_putbytes_fd.c                            \
                ft_putchar.c                                \
                ft_putchar_fd.c                             \
                ft_putstr.c                                 \
                ft_putstr_fd.c                              \
                ft_putendl.c                                \
                ft_putendl_fd.c                             \
                ft_putstrtab.c                              \
                ft_putstrtab_fd.c                           \
                ft_putnbr.c                                 \
                ft_putnbr_fd.c                              \
                ft_putnbr_base.c                            \
                ft_putnbr_base_fd.c                         \
                                                            \
                ft_intlen.c                                 \
                ft_atoi.c                                   \
                ft_itoa.c                                   \
                ft_atoi_base.c                              \
                ft_itoa_base.c                              \
                ft_convert_base.c                           \
                                                            \
                ft_pow.c                                    \
                ft_sqrt.c                                   \
                ft_wcount.c                                 \
                                                            \
                ft_swap_int.c                               \
                ft_swap_char.c                              \
                ft_swap_str.c                               \
                ft_swap_item.c                              \
                                                            \
                ft_hash.c                                   \
                                                            \
                list_newelem.c                              \
                list_prepend.c                              \
                list_append.c                               \
                list_append_tail.c                          \
                list_extend.c                               \
                list_extend_tail.c                          \
                list_extendleft.c                           \
                list_insert.c                               \
                list_insert_at.c                            \
                list_at.c                                   \
                list_getelem.c                              \
                list_getitem.c                              \
                list_clear.c                                \
                list_remove.c                               \
                list_pop.c                                  \
                list_popleft.c                              \
                list_iter.c                                 \
                list_iteri.c                                \
                list_count.c                                \
                list_sort.c                                 \
                list_reverse.c                              \
                list_copy.c                                 \
                list_map.c                                  \
                list_merge.c                                \
                                                            \
                btree_newnode.c                             \
                btree_apply_prefix.c                        \
                btree_apply_infix.c                         \
                btree_apply_suffix.c                        \
                btree_insert.c                              \
                btree_getitem.c                             \
                btree_level_count.c                         \
                                                            \
                trie_newnode.c                              \
                trie_insert.c                               \
                trie_remove.c                               \
                trie_clear.c                                \
                trie_getitem.c                              \
                trie_count.c                                \
                                                            \
                hashtab_alloc_table.c                       \
                hashtab_grow_table.c                        \
                hashtab_shrink_table.c                      \
                hashtab_fetch_entry.c                       \
                hashtab_insert_entry.c                      \
                hashtab_delete_entry.c                      \
                hashtab_rehash_entry.c                      \
                hashtab_rehash_table.c                      \
                hashtab_destroy_table.c                     \
                hashtab_set_appropriate_load_factor.c       \
                                                            \
                dict_insert.c                               \
                dict_getkey.c                               \
                dict_getvalue.c                             \
                dict_getitem.c                              \
                dict_getvalue_fast.c                        \
                dict_getitem_fast.c                         \
                dict_remove.c                               \
                dict_clear.c                                \

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
