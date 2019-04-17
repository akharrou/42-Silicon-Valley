/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdlib_42.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 21:35:17 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 06:30:45 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDLIB_42_H
# define STDLIB_42_H

# include <stdlib.h>
# include <string.h>

void			ft_bzero(void *str, size_t n);

void			*ft_memset(void *dst, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *dst, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memalloc(size_t size);
char			*ft_realloc(char *buffer, int init_size);

void			**ft_matrix_new(void **matrix, size_t height, size_t width,
				size_t typesize);

int				ft_find_next_prime(int n);

int				ft_wcount(const char *s, const char *charset);
int				ft_chrcount(const char *s, const char c);

void			ft_swap_int(int *a, int *b);
void			ft_swap_char(char *a, char *b);
void			ft_swap_str(char **a, char **b);
void			ft_swap_item(void **a, void **b);

size_t			ft_intlen(int n);
size_t			ft_intlen_base(int n, unsigned int base);
size_t			ft_longlen_base(long n, unsigned int base);
size_t			ft_longlonglen_base(long long n, unsigned int base);

int				valid_base(char *base_str);

int				ft_atoi(const char *str);
int				ft_atoi_base(char *str, char *base);

char			*ft_itoa(int n);
char			*ft_itoa_base(int n, char *base, int padding,
				char pad);
char			*ft_ltoa_base(long n, char *base, int padding,
				char pad);
char			*ft_lltoa_base(long long n, char *base, int padding,
				char pad);
char			*ft_uitoa_base(unsigned int n, char *base, int padding,
				char pad);
char			*ft_ultoa_base(unsigned long n, char *base, int padding,
				char pad);
char			*ft_ulltoa_base(unsigned long long n, char *base, int padding,
				char pad);

char			*ft_convert_base(char *nbr, char *base_from, char *base_to);

unsigned int	ft_hash(const char *str);

#endif
