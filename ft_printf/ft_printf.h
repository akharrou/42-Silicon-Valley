/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 01:21:59 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 04:03:19 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# include "Libft/Includes/libft.h"
# include <stdarg.h>

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define N_SPECIFIERS (11)
# define SPECIFIERS   ("cspdifouxX%")
# define FLAGS        ("-+#0 ")

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

typedef struct	s_format_info
{
	t_int8		flags;
	t_int8		width;
	t_int8		precision;
	t_int8		length;
	t_int8		specifier;
	t_int8		format_length;
}				t_format;

typedef struct	s_dispatch
{
	char		specifier;
	t_char		*(*handler)(t_format format, va_list *args);
	size_t		default_size;
}				t_dispatch;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define NONE (-1)

enum e_flags
{
    MINUS = (1 << 0),
    PLUS  = (1 << 1),
    SPACE = (1 << 2),
    HASH  = (1 << 3),
    ZERO  = (1 << 4)
};

enum e_lengths
{
    H   = sizeof(int),
    HH  = sizeof(char),
    L   = sizeof(long int),
    LL  = sizeof(long long int),
    LLL = sizeof(long double)
};

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

int			ft_printf(const char *format, ...);
int			ft_fprintf(int filedes, const char *format, ...);
int			ft_sprintf(char *str, const char *format, ...);

t_int8		parse_flags(const char *format, t_int8 *i);
t_int8		parse_width(const char *format, t_int8 *i);
t_int8		parse_precison(const char *format, t_int8 *i);
t_int8		parse_length(const char *format, t_int8 *i);
t_int8		parse_specifier(const char *format, t_int8 *i);

t_format	parse_format(const char *format);

t_char		*i_specifier_handler(t_format format, va_list *args);     // [√]
t_char		*u_specifier_handler(t_format format, va_list *args);     // [√]
t_char		*f_specifier_handler(t_format format, va_list *args);
t_char		*o_specifier_handler(t_format format, va_list *args);     // [√]
t_char		*x_specifier_handler(t_format format, va_list *args);     // [√]
t_char		*c_specifier_handler(t_format format, va_list *args);     // [√]
t_char		*s_specifier_handler(t_format format, va_list *args);     // [√]
t_char		*p_specifier_handler(t_format format, va_list *args);     // [√]
t_char		*mod_specifier_handler(t_format format, va_list *args);   // [√]

t_char		*formatted_string(const char **buf, va_list *args);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
