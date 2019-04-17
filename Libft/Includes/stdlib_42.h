/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdlib_42.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 21:35:17 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 01:57:26 by akharrou         ###   ########.fr       */
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
size_t			ft_intlen(long long n);
size_t			ft_longlonglen_base(long long n, unsigned int base);
int				ft_find_next_prime(int n);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
int				ft_atoi_base(char *str, char *base);
char			*ft_itoa_base(long nbr, char *base);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
int				ft_wcount(const char *s, const char *charset);
int				ft_chrcount(const char *s, const char c);
void			ft_swap_int(int *a, int *b);
void			ft_swap_char(char *a, char *b);
void			ft_swap_str(char **a, char **b);
void			ft_swap_item(void **a, void **b);
unsigned int	ft_hash(const char *str);

#endif
