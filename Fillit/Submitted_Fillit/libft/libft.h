/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 16:20:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/23 18:28:31 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef ABS
#  define ABS(x)             ((x < 0) ? (-x) : (x))
# endif

# ifndef FLOOR
#  define FLOOR(x)           ((int)x)
# endif

# ifndef MAX
#  define MAX(x, y)          ((x > y) ? (x) : (y))
# endif

# ifndef MIN
#  define MIN(x, y)          ((x < y) ? (x) : (y))
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef SUCCESS
#  define SUCCESS 0
# endif

# ifndef FAILURE
#  define FAILURE -1
# endif

# ifndef EXIT
#  define EXIT(error_msg) { ft_putendl(error_msg); exit(EXIT_FAILURE); }
# endif

typedef unsigned char		t_bool;
typedef unsigned char		t_char;

typedef unsigned char		t_uint8;
typedef unsigned short		t_uint16;
typedef unsigned long		t_uint32;
typedef unsigned long long	t_uint64;

typedef signed char			t_int8;
typedef signed short		t_int16;
typedef signed long			t_int32;
typedef signed long long	t_int64;

void						*ft_memset(void *dst, int c, size_t n);
void						ft_bzero(void *str, size_t n);
void						ft_putendl(char const *s);
size_t						ft_strlen(const char *s);
double						ft_pow(double x, double y);
double						ft_sqrt(double x);

#endif
