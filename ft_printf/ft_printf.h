/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 01:21:59 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/18 17:08:48 by akharrou         ###   ########.fr       */
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
	t_int32		width;
	t_int32		precision;
	t_int8		length;
	t_int8		specifier;
	t_int8		format_length;
}				t_format;

typedef struct	s_dispatch
{
	char		specifier;
	t_char		*(*width_handler)(t_format format, t_char *fstr);
	t_char		*(*precision_handler)(t_format format, t_char *fstr);
	t_char		*(*flags_handler)(t_format format, t_char *fstr);
	t_char		*(*length_handler)(t_format format, va_list *args);
	size_t		default_size;
}				t_dispatch;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define NONE (-1)

enum	e_flags
{
	MINUS = (1 << 0),
	PLUS = (1 << 1),
	SPACE = (1 << 2),
	HASH = (1 << 3),
	ZERO = (1 << 4)
};

enum	e_lengths
{
	H = sizeof(int),
	HH = sizeof(char),
	L = sizeof(long int),
	LL = sizeof(long long int),
	LLL = sizeof(long double)
};

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

int				ft_printf(const char *format, ...);
int				ft_fprintf(int filedes, const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);

t_format		parse_format(const char *format), va_list *args);

t_int8			parse_flags(const char *format, t_int8 *i);
t_int32			parse_width(const char *format, va_list *args, t_int8 *i);
t_int32			parse_precison(const char *format, va_list *args, t_int8 *i);
t_int8			parse_length(const char *format, t_int8 *i);
t_int8			parse_specifier(const char *format, t_int8 *i);

t_char			*i_length_handler(t_format format, va_list *args);
t_char			*u_length_handler(t_format format, va_list *args);
t_char			*f_length_handler(t_format format, va_list *args);
t_char			*o_length_handler(t_format format, va_list *args);
t_char			*x_length_handler(t_format format, va_list *args);
t_char			*c_length_handler(t_format format, va_list *args);
t_char			*s_length_handler(t_format format, va_list *args);
t_char			*p_length_handler(t_format format, va_list *args);
t_char			*mod_length_handler(t_format format, va_list *args);

t_char			*formatted_string(const char **buf, va_list *args);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
