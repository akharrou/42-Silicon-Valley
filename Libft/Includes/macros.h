/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 09:07:32 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/11 18:14:39 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/*
** Conveniance Macros
*/

# ifndef EVEN
#  define EVEN(n) (n % 2 == 0)
# endif

# ifndef ODD
#  define ODD(n) (n % 2 == 1)
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
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

# ifdef EXIT_SUCCESS
#  undef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif

# ifdef EXIT_FAILURE
#  undef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif

# ifndef _NULL
#  define _NULL (void *)0
# endif

/*
** Utility Macros
*/

# ifndef BUFF_SIZE
#  define BUFF_SIZE 256
# endif

/*
** Error Checking Macros
*/

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
#  define EXIT(error_msg) ft_putendl(error_msg); exit(EXIT_FAILURE);
#  define CHECK(expr, err, errmsg) if (expr == err) { EXIT(errmsg) }
# endif

#endif
