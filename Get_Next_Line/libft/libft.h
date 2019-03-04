/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 16:20:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/02 09:55:34 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef _NULL
#  define _NULL (void *)0
# endif

# ifndef MALLOC_GUARD
#  define MALLOC_GUARD(expr, error) if (!(expr)) return (error)
# endif

# ifndef ERROR_CHECK
#  define ERROR_CHECK(expr, error) if (expr) return (error)
# endif

# define ISBLANK(c) (c == ' ' || c == '\t')
# define ISSPACE(c) (ISBLANK (c) || c >= 10 && c <= 13)
# define ISDIGIT(c) (c >= '0' && c <= '9')
# define ISLOWER(c) (c >= 'a' && c <= 'z')
# define ISUPPER(c) (c >= 'A' && c <= 'Z')
# define ISALPHA(c) (ISUPPER(c) || ISLOWER(c))
# define ISALNUM(c) (ISALPHA(c) || ISDIGIT(c))
# define ISPRINT(c) (c >= 32 && c <= 126)
# define ISGRAPH(c) (c >= 33 && c <= 126)
# define ISPUNCT(c) (ISGRAPH(c) && !ISALNUM(c))
# define ISCNTRL(c) (!ISPRINT(c))
# define ISASCII(c) (c >= 0 && <= 127)

typedef unsigned char		t_bool;

typedef unsigned char		t_uint8;
typedef unsigned short		t_uint16;
typedef unsigned long		t_uint32;
typedef unsigned long long	t_uint64;

typedef signed char			t_int8;
typedef signed short		t_int16;
typedef signed long			t_int32;
typedef signed long long	t_int64;

int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isblank(int c);
int					ft_isspace(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isgraph(int c);
int					ft_ispunct(int c);
int					ft_iscntrl(int c);
int					ft_isprint(int c);
int					ft_isprime(int n);
int					ft_ischarset(int c, const char *seperators);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				ft_bzero(void *str, size_t n);
void				*ft_memset(void *dst, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
char				*ft_realloc(char *buffer, int init_size);

size_t				ft_strlen(const char *str);
size_t				ft_strnlen(const char *s, size_t maxlen);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t len);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strrev(char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
int					ft_strchrs(char *str, char *substr);
char				*ft_strstr(const char *str, const char *find);
char				*ft_strnstr(const char *str, const char *find, size_t len);
char				*ft_strdup(const char *str);
char				*ft_strdup_range(const char *str, int index, int end);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);

void				ft_putbyte(int c);
void				ft_putbyte_fd(int c, int fd);
void				ft_putbytes(const char *byte_str);
void				ft_putbytes_fd(const char *byte_str, int fd);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstrtab(char **tab, char sep);
void				ft_putstrtab_fd(char **tab, char sep, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_base(int nbr, char *base);
void				ft_putnbr_base_fd(int nbr, char *base, int fd);

size_t				ft_intlen(long n);
int					ft_find_next_prime(int n);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
int					ft_atoi_base(char *str, char *base);
char				*ft_itoa_base(long nbr, char *base);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);

unsigned int		ft_hash(const char *str);

long double			ft_pow(int nb, int power);
int					ft_wcount(const char *s, const char *charset);

void				ft_swap_int(int *a, int *b);
void				ft_swap_char(char *a, char *b);
void				ft_swap_str(char **a, char **b);
void				ft_swap_item(void **a, void **b);

# ifndef LIST_H
#  define LIST_H

typedef struct		s_list_element
{
	void					*item;
	struct s_list_element	*next;
}					t_list;

t_list				*list_newelem(const void *item);

int					list_prepend(t_list **head, const void *item);
int					list_append(t_list **head, const void *item);
int					list_append_tail(t_list **tail, const void *item);
int					list_append_both(t_list **head, t_list **tail,
					const void *item);
int					list_extend(t_list **head, const void **item_vector);
int					list_extend_tail(t_list **tail, const void **item_vector);
int					list_extendleft(t_list **head, const void **item_vector);
int					list_insert(t_list **head, const void *item,
					int (*cmp)(void *, void *));
int					list_insert_at(t_list **head, const void *item,
					unsigned int i);

void				*list_item_at(t_list *head, unsigned int i);
void				*list_last_item(t_list *head);
t_list				*list_elem_at(t_list *head, unsigned int i);
t_list				*list_last_elem(t_list *head);
void				*list_getitem(t_list *head, const void *item_ref,
					int (*cmp)(void *, void *));
t_list				*list_getelem(t_list *head, const void *item_ref,
					int (*cmp)(void *, void *));

void				*list_pop(t_list **head);
void				*list_pop_tail(t_list **tail);
void				*list_popleft(t_list **head);
void				*list_pop_item_at(t_list **head, unsigned int i);
void				*list_pop_item(t_list **head, const void *item_ref,
					int (*cmp)(void *, void *));
int					list_remove_item(t_list **head, const void *item_ref,
					int (*cmp)(void *, void *), void (*free_item)(void *));
int					list_remove_item_at(t_list **head, unsigned int i,
					void (*free_item)(void *));
int					list_remove_elem(t_list **head, const void *item_ref,
					int (*cmp)(void *, void *), void (*free_item)(void *));
int					list_remove_elem_at(t_list **head, unsigned int i,
					void (*free_item)(void *));
int					list_clear(t_list **head, void (*free_item)(void *));

void				list_iter(t_list *head, void (*f)(void *item));
void				list_iteri(t_list *head,
					void (*f)(unsigned int i, void *item));
unsigned int		list_count(t_list *head);
void				list_sort(t_list **head, int (*cmp)(void *, void *));
int					list_reverse(t_list **head);
int					list_map(t_list **dest, t_list *src,
					t_list *(*f)(t_list *elem));
int					list_merge(t_list **list1, t_list *list2);

# endif

# ifndef BTREE_H
#  define BTREE_H

typedef struct		s_btree_node
{
	void				*item;
	struct s_btree_node	*left;
	struct s_btree_node	*right;
}					t_btree;

t_btree				*btree_newnode(void *item);
void				btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void				btree_apply_infix(t_btree *root, void (*applyf)(void *));
void				btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void				btree_insert(t_btree **root, void *item,
					int (*cmpf)(void *, void *));
void				*btree_getitem(t_btree *root, void *item_ref,
					int (*cmpf)(void *, void *));
int					btree_level_count(t_btree *root);

# endif

# ifndef TRIE_H
#  define TRIE_H

#  define ALPHABET_SIZE 27
#  define HEXDIGIT_SIZE 16
#  define SIZE_OF_ARRAY ALPHABET_SIZE

typedef struct		s_trie_node
{
	void				*item;
	struct s_trie_node	*children[SIZE_OF_ARRAY];
}					t_trie;

unsigned int		ft_alpha_to_index(char c);
unsigned int		ft_char_to_index(char c);

t_trie				*trie_newnode(void);
int					trie_insert(t_trie **root, char *hash, void *item,
					unsigned int (*char_to_index)(char c));
void				trie_remove(t_trie **root, char *hash,
					unsigned int (*char_to_index)(char c));
int					trie_clear(t_trie **root);
void				*trie_getitem(t_trie *root, char *hash,
					unsigned int (*char_to_index)(char c));
unsigned int		trie_count(t_trie *root);

# endif

# ifndef HASHTABLE_H
#  define HASHTABLE_H

#  define HASHCODE(key, buckets) (ft_hash(key) % buckets)

#  define MIN_LOAD_FACTOR 0.0
#  define MAX_LOAD_FACTOR 0.7

typedef struct		s_entry
{
	char			*key;
	void			*item;
	struct s_entry	*next;
}					t_entry;

typedef struct		s_hashtable
{
	unsigned int	entries;
	unsigned int	num_buckets;
	t_entry			**bucket_list;
}					t_hashtable;

t_hashtable			*hashtab_alloc_table(unsigned int num_entries);
int					hashtab_grow_table(t_hashtable **table);
int					hashtab_shrink_table(t_hashtable **table);
t_entry				*hashtab_fetch_entry(t_hashtable *table, char *key);
int					hashtab_insert_entry(t_hashtable **table,
										char *key,
										void *item);
int					hashtab_delete_entry(t_hashtable **table, char *key);
int					hashtab_rehash_entry(t_hashtable **table_to,
										t_entry **entry);
int					hashtab_rehash_table(t_hashtable **table_from,
										t_hashtable **table_to);
int					hashtab_destroy_table(t_hashtable **table);
int					hashtab_set_appropriate_load_factor(t_hashtable **table);

# endif

# ifndef DICT_H
#  define DICT_H

#  define INIT_DICT_SIZE 10

typedef t_hashtable	t_dict;

t_dict				*dict_new(unsigned int num_entries);
int					dict_insert(t_dict **table, char *key, void *item);
int					dict_getindex(t_dict *table, char *key);
void				*dict_getitem(t_dict *table, char *key);
void				*dict_getitem_fast(t_dict *table, char *key,
					int table_index);
t_entry				*dict_getentry(t_dict *table, char *key);
t_entry				*dict_getentry_fast(t_hashtable *table, char *key,
					int table_index);
int					dict_remove(t_dict **table, char *key);
int					dict_clear(t_dict **table);

# endif

#endif
