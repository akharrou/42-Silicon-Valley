/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 01:21:59 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/21 11:45:18 by akharrou         ###   ########.fr       */
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

typedef union			u_data
{
	signed char			chr;
	signed short		shrt;
	signed int			intgr;
	signed long			lng;
	signed long long	lnglng;
	intmax_t			intmax_t;
	unsigned char		uchr;
	unsigned short		ushrt;
	unsigned int		uintgr;
	unsigned long		ulng;
	unsigned long long	ulnglng;
	uintmax_t			uintmax_t;
	double				dble;
	long double			ldble;
	char				*str;
	intptr_t			ptr;
}						t_data;

typedef struct			s_style
{
	t_char				*style;
	t_char				*ansi_code;
}						t_style;

typedef struct			s_format_info
{
	t_int8				flags;
	t_int32				width;
	t_int32				precision;
	t_int8				length;
	t_int8				specifier;
	t_char				**style;
	t_data				data;
	t_char				pad;
	t_int8				format_length;
}						t_format;

typedef struct			s_handler
{
	char				specifier;
	t_char				*(*handler)(t_format format);
}						t_handler;

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

int						ft_printf(const char *format, ...);
int						ft_fprintf(int filedes, const char *format, ...);
int						ft_sprintf(char *str, const char *format, ...);

t_format				parse_format(const char *format, va_list *args);
t_char					**parse_style(const char *format, t_int8 *i);

t_int8					parse_flags(const char *format, t_int8 *i);
t_int32					parse_width(const char *format, va_list *args,
						t_int8 *i);
t_int32					parse_precison(const char *format, va_list *args,
						t_int8 *i);
t_int8					parse_length(const char *format, t_int8 *i);
t_int8					parse_specifier(const char *format, t_int8 *i);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define				SPECIFIERS "cspdifouxXbr%"

t_char					*c_handler(t_format format);
t_char					*i_handler(t_format format);
t_char					*d_handler(t_format format);
t_char					*u_handler(t_format format);
t_char					*f_handler(t_format format);
t_char					*o_handler(t_format format);
t_char					*x_handler(t_format format);
t_char					*b_handler(t_format format);
t_char					*s_handler(t_format format);
t_char					*r_handler(t_format format);
t_char					*p_handler(t_format format);
t_char					*mod_handler(t_format format);
t_char					*style_handler(t_format format, t_char *fstr);

t_char					*format_converter(const char **buf, va_list *args);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
