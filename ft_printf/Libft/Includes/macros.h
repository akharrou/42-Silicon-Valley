/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 09:07:32 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 06:38:57 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/*
** Constants
*/

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef MAX_FDS
#  define MAX_FDS 65536
# endif

/*
** Useful Macros
*/

# define STDIN  0
# define STDOUT 1
# define STDERR 2

# define DIGITS "0123456789"
# define ALPHABET_LOWER "abcdefghijklmnopqrstuvwxyz"
# define ALPHABET_UPPER "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

# define BINARY_BASE "01"
# define OCT_BASE "01234567"
# define DECIMAL_BASE "0123456789"
# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"

# ifndef BUFF_SIZE
#  define BUFF_SIZE 256
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef _NULL
#  define _NULL (void *)0
# endif

# ifndef SUCCESS
#  define SUCCESS 0
# endif

# ifndef FAILURE
#  define FAILURE -1
# endif

# ifdef EXIT_SUCCESS
#  undef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif

# ifdef EXIT_FAILURE
#  undef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif

# ifndef EXIT
#  define EXIT(error_msg) { ft_putendl(error_msg); exit(EXIT_FAILURE); }
# endif

# ifndef FLUSH
#  define FLUSH(buffer) if (buffer != NULL) { free(buffer); buffer = NULL; }
# endif

/*
** Error Checking Macros
*/

# ifndef ASSERT
#  define ASSERT(expr) (expr != FALSE)
# endif

# ifndef MALLOC_GUARD
#  define MALLOC_GUARD(expr, val) if (!(expr)) return (val)
# endif

# ifndef RETURN_CHECK
#  define RETURN_CHECK(expr, val) if (expr) return (val)
# endif

# ifndef BREAK_CHECK
#  define BREAK_CHECK(expr) if (expr) break
# endif

# ifndef CHECK
#  define CHECK(expr, err, errmsg) if (expr == err) { EXIT(errmsg) }
# endif

#endif
